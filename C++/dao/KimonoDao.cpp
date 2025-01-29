#include "KimonoDao.h"
#include "ProdutoDao.h"
#include <stdexcept>
#include <iostream>

// Construtor que recebe o nome do banco de dados
KimonoDao::KimonoDao(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        throw std::runtime_error("Erro ao abrir o banco de dados: " + std::string(sqlite3_errmsg(db)));
    }
}

// Destrutor para fechar a conexão com o banco de dados
KimonoDao::~KimonoDao() {
    sqlite3_close(db);
}

// Converter enum Forma para string
std::string KimonoDao::formaToString(Forma forma) {
    switch (forma) {
        case Forma::TRADICIONAL: return "TRADICIONAL";
        case Forma::SLIM: return "SLIM";
        case Forma::ULTRASLIM: return "ULTRASLIM";
        default: return "";
    }
}

// Converter string para enum Forma
Forma KimonoDao::stringToForma(const std::string& formaStr) {
    if (formaStr == "TRADICIONAL") return Forma::TRADICIONAL;
    if (formaStr == "SLIM") return Forma::SLIM;
    if (formaStr == "ULTRASLIM") return Forma::ULTRASLIM;
    throw std::runtime_error("Forma inválida.");
}


// Buscar um Kimono pelo ID
Kimono KimonoDao::findById(int idKimono) {
    const char* sql = "SELECT * FROM Kimono WHERE idKimono = ?;";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a consulta SQL.");
    }

    sqlite3_bind_int(stmt, 1, idKimono);
    
    Kimono kimono;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        double gramatura = sqlite3_column_double(stmt, 0);
        int encolhimento = sqlite3_column_int(stmt, 1);
        std::string formaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

        Forma forma;
        if (formaStr == "TRADICIONAL") forma = Forma::TRADICIONAL;
        else if (formaStr == "SLIM") forma = Forma::SLIM;
        else if (formaStr == "ULTRASLIM") forma = Forma::ULTRASLIM;

        kimono.setGramaturaTecido(gramatura);
        kimono.setEncolhimento(encolhimento);
        kimono.setForma(forma);
        kimono.setIdProduto(idKimono);
    }

    sqlite3_finalize(stmt);
    return kimono;
}

// Buscar todos os Kimonos
std::vector<Kimono> KimonoDao::findAll() {
    std::vector<Kimono> kimonos;
    const char* sql = "SELECT * FROM Kimono;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a consulta SQL.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idKimono = sqlite3_column_int(stmt, 0);
        double gramatura = sqlite3_column_double(stmt, 1);
        int encolhimento = sqlite3_column_int(stmt, 2);
        std::string formaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        Forma forma;
        if (formaStr == "TRADICIONAL") forma = Forma::TRADICIONAL;
        else if (formaStr == "SLIM") forma = Forma::SLIM;
        else if (formaStr == "ULTRASLIM") forma = Forma::ULTRASLIM;

        Kimono kimono;
        kimono.setIdProduto(idKimono);
        kimono.setGramaturaTecido(gramatura);
        kimono.setEncolhimento(encolhimento);
        kimono.setForma(forma);

        kimonos.push_back(kimono);
    }

    sqlite3_finalize(stmt);
    return kimonos;
}

// Inserir um novo Kimono
void KimonoDao::insert(Kimono& kimono) {
    // Inserindo o Produto primeiro
    ProdutoDao produtoDao("NovoBanco.db");
    Produto produtoInserido = produtoDao.insert(kimono);

    // Atualiza o ID do produto no objeto Kimono
    kimono.setIdProduto(produtoInserido.getIdProduto());
    

    const char* sql = "INSERT INTO Kimono (idKimono, gramaturaTecido, encolhimento, forma) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a inserção SQL.");
    }

    sqlite3_bind_int(stmt, 1, kimono.getIdProduto());
    sqlite3_bind_double(stmt, 2, kimono.getGramaturaTecido());
    sqlite3_bind_int(stmt, 3, kimono.getEncolhimento());
    sqlite3_bind_text(stmt, 4, formaToString(kimono.getForma()).c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Erro ao inserir Kimono no banco.");
    }

    sqlite3_finalize(stmt);
}

// Atualizar um Kimono existente
void KimonoDao::update(const Kimono& kimono) {
    const char* sql = "UPDATE Kimono SET gramaturaTecido = ?, encolhimento = ?, forma = ? WHERE idKimono = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a atualização SQL.");
    }

    sqlite3_bind_double(stmt, 1, kimono.getGramaturaTecido());
    sqlite3_bind_int(stmt, 2, kimono.getEncolhimento());
    sqlite3_bind_text(stmt, 3, formaToString(kimono.getForma()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, kimono.getIdProduto());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Erro ao atualizar Kimono no banco.");
    }

    sqlite3_finalize(stmt);
}

// Deletar um Kimono pelo ID
void KimonoDao::deleteById(int idKimono) {
    const char* sql = "DELETE FROM Kimono WHERE idKimono = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a exclusão SQL.");
    }

    sqlite3_bind_int(stmt, 1, idKimono);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Erro ao excluir Kimono no banco.");
    }

    sqlite3_finalize(stmt);
}