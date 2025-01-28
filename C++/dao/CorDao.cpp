#include "CorDao.h"

// Construtor para abrir o banco
CorDao::CorDao(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Não foi possível abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Destrutor para fechar o banco
CorDao::~CorDao() {
    sqlite3_close(db);
}

// Buscar uma cor pelo ID
Cor CorDao::findById(int idCor) {
    std::string sql = "SELECT idCor, nome FROM Cor WHERE idCor = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idCor);

    Cor cor(0, ""); // Objeto vazio para armazenar os dados
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        cor.setIdCor(sqlite3_column_int(stmt, 0));
        cor.setNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
    } else {
        std::cerr << "Nenhuma cor encontrada com o ID: " << idCor << std::endl;
    }

    sqlite3_finalize(stmt);
    return cor;
}

// Buscar todas as cores
std::vector<Cor> CorDao::findAll() {
    std::string sql = "SELECT idCor, nome FROM Cor";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::vector<Cor> cores;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Cor cor(
            sqlite3_column_int(stmt, 0),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
        );
        cores.push_back(cor);
    }

    sqlite3_finalize(stmt);
    return cores;
}

// Inserir uma nova cor
void CorDao::insert(const Cor& cor) {
    std::string sql = "INSERT INTO Cor (nome) VALUES (?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, cor.getNome().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao inserir a cor: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Atualizar uma cor existente
void CorDao::update(const Cor& cor) {
    std::string sql = "UPDATE Cor SET nome = ? WHERE idCor = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, cor.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, cor.getIdCor());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao atualizar a cor: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Deletar uma cor pelo ID
void CorDao::deleteById(int idCor) {
    std::string sql = "DELETE FROM Cor WHERE idCor = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idCor);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao deletar a cor: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}