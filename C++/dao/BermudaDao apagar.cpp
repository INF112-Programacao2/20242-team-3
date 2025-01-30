#include "BermudaDao.h"
#include "ProdutoDao.h"
#include <stdexcept>
#include <iostream>

// Construtor que recebe o nome do banco de dados
BermudaDao::BermudaDao(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        throw std::runtime_error("Erro ao abrir o banco de dados: " + std::string(sqlite3_errmsg(db)));
    }
}

// Destrutor para fechar a conexão com o banco de dados
BermudaDao::~BermudaDao() {
    sqlite3_close(db);
}

// Converter ENUMS para STRING
std::string BermudaDao::ajusteToString(Ajuste ajuste) {
    switch (ajuste) {
        case Ajuste::ELASTICO: return "ELASTICO";
        case Ajuste::BOTAO: return "BOTAO";
        case Ajuste::AMARRACAO: return "AMARRACAO";
        default: return "";
    }
}

std::string BermudaDao::comprimentoToString(Comprimento comprimento) {
    switch (comprimento) {
        case Comprimento::CURTO: return "CURTO";
        case Comprimento::MEDIO: return "MEDIO";
        case Comprimento::LONGO: return "LONGO";
        default: return "";
    }
}

// Converter STRING para ENUMS
Ajuste BermudaDao::stringToAjuste(const std::string& ajusteStr) {
    if (ajusteStr == "ELASTICO") return Ajuste::ELASTICO;
    if (ajusteStr == "BOTAO") return Ajuste::BOTAO;
    if (ajusteStr == "AMARRACAO") return Ajuste::AMARRACAO;
    throw std::runtime_error("Ajuste inválido.");
}

Comprimento BermudaDao::stringToComprimento(const std::string& comprimentoStr) {
    if (comprimentoStr == "CURTO") return Comprimento::CURTO;
    if (comprimentoStr == "MEDIO") return Comprimento::MEDIO;
    if (comprimentoStr == "LONGO") return Comprimento::LONGO;
    throw std::runtime_error("Comprimento inválido.");
}


// Buscar um Bermuda pelo ID
Bermuda BermudaDao::findById(int idBermuda) {
    const char* sql = "SELECT * FROM Bermuda WHERE idBermuda = ?;";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a consulta SQL.");
    }

    sqlite3_bind_int(stmt, 1, idBermuda);
    
    Bermuda bermuda;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Ajuste ajuste = stringToAjuste(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        Comprimento comprimento = stringToComprimento(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

        bermuda.setAjuste(ajuste);
        bermuda.setComprimento(comprimento);
        bermuda.setIdProduto(idBermuda);
    }

    sqlite3_finalize(stmt);
    return bermuda;
}

// Buscar todos os Bermudas
std::vector<Bermuda> BermudaDao::findAll() {
    std::vector<Bermuda> bermudas;
    const char* sql = "SELECT * FROM Bermuda;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a consulta SQL.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idBermuda = sqlite3_column_int(stmt, 0);
        Ajuste ajuste = stringToAjuste(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        Comprimento comprimento = stringToComprimento(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

        Bermuda bermuda;
        bermuda.setIdProduto(idBermuda);
        bermuda.setAjuste(ajuste); 
        bermuda.setComprimento(comprimento);

        bermudas.push_back(bermuda);
    }

    sqlite3_finalize(stmt);
    return bermudas;
}

// Inserir um novo Bermuda
void BermudaDao::insert(Bermuda& bermuda) {
    // Inserindo o Produto primeiro
    ProdutoDao produtoDao("NovoBanco.db");
    Produto produtoInserido = produtoDao.insert(bermuda);

    // Atualiza o ID do produto no objeto Bermuda
    bermuda.setIdProduto(produtoInserido.getIdProduto());
    
    const char* sql = "INSERT INTO Bermuda (idBermuda, ajuste, comprimento) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a inserção SQL.");
    }

    sqlite3_bind_int(stmt, 1, bermuda.getIdProduto());
    sqlite3_bind_text(stmt, 2, ajusteToString(bermuda.getAjuste()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, comprimentoToString(bermuda.getComprimento()).c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Erro ao inserir Bermuda no banco.");
    }

    sqlite3_finalize(stmt);
}

// Atualizar um Bermuda existente
void BermudaDao::update(Bermuda& bermuda) {
    // Atualizando o Produto primeiro
    ProdutoDao produtoDao("NovoBanco.db");
    Produto produtoInserido = produtoDao.update(bermuda);

    // Atualiza o ID do produto no objeto Bermuda
    bermuda.setIdProduto(produtoInserido.getIdProduto());

    const char* sql = "UPDATE Bermuda SET ajuste = ?, comprimento = ? WHERE idBermuda = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a atualização SQL.");
    }

    sqlite3_bind_text(stmt, 1, ajusteToString(bermuda.getAjuste()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, comprimentoToString(bermuda.getComprimento()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, bermuda.getIdProduto());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Erro ao atualizar Bermuda no banco.");
    }

    sqlite3_finalize(stmt);
}

// Deletar um Bermuda pelo ID
void BermudaDao::deleteById(int idBermuda) {
    const char* sql = "DELETE FROM Bermuda WHERE idBermuda = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar a exclusão SQL.");
    }

    sqlite3_bind_int(stmt, 1, idBermuda);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Erro ao excluir Bermuda no banco.");
    }

    sqlite3_finalize(stmt);
}