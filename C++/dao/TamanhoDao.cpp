#include "TamanhoDao.h"

// Construtor para abrir o banco
TamanhoDao::TamanhoDao(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Não foi possível abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Destrutor para fechar o banco
TamanhoDao::~TamanhoDao() {
    sqlite3_close(db);
}

// Converter string para TipoProduto
TipoProduto TamanhoDao::stringToTipoProduto(const std::string& tipoProdutoStr) {
    if (tipoProdutoStr == "BERMUDA") return TipoProduto::BERMUDA;
    if (tipoProdutoStr == "FAIXA") return TipoProduto::FAIXA;
    if (tipoProdutoStr == "KIMONO") return TipoProduto::KIMONO;
    if (tipoProdutoStr == "RASH_GUARD") return TipoProduto::RASH_GUARD;
    throw std::invalid_argument("Tipo de produto inválido: " + tipoProdutoStr);
}

// Converter TipoProduto para String
std::string TamanhoDao::tipoProdutoToString(const TipoProduto& tipoProduto) {
    std::string tipoProdutoStr;

    switch (tipoProduto) {
        case TipoProduto::BERMUDA: tipoProdutoStr = "BERMUDA"; break;
        case TipoProduto::FAIXA: tipoProdutoStr = "FAIXA"; break;
        case TipoProduto::KIMONO: tipoProdutoStr = "KIMONO"; break;
        case TipoProduto::RASH_GUARD: tipoProdutoStr = "RASH_GUARD"; break;
    }

    return tipoProdutoStr;
}

// Buscar o tamanho pelo ID
Tamanho TamanhoDao::findById(int idTamanho) {
    std::string sql = "SELECT idTamanho, tipoProduto, nome FROM Tamanho WHERE idTamanho = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idTamanho);

    Tamanho tamanho(0, TipoProduto::FAIXA, ""); // Objeto vazio para armazenar os dados
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        tamanho.setIdTamanho(sqlite3_column_int(stmt, 0));
        const char* tipoProduto = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)); // Convertendo TipoProduto para string
        tamanho.setTipoProduto(stringToTipoProduto(tipoProduto));
        tamanho.setNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
    } else {
        std::cerr << "Nenhum tamanho encontrada com o ID: " << idTamanho << std::endl;
    }

    sqlite3_finalize(stmt);
    return tamanho;
}

// Buscar todos os tamanhos, filtrando pelo TipoProduto
std::vector<Tamanho> TamanhoDao::findAllByTipoProduto(const std::string& tipoProduto) {
    std::string sql = "SELECT idTamanho, tipoProduto, nome FROM Tamanho WHERE tipoProduto = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, tipoProduto.c_str(), -1, SQLITE_STATIC);

    std::vector<Tamanho> tamanhos;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Tamanho tamanho(
            sqlite3_column_int(stmt, 0),
            stringToTipoProduto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))
        );
        tamanhos.push_back(tamanho);
    }

    sqlite3_finalize(stmt);
    return tamanhos;
}


// Buscar todas as tamanhos
std::vector<Tamanho> TamanhoDao::findAll() {
    std::string sql = "SELECT idTamanho, tipoProduto, nome FROM Tamanho";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::vector<Tamanho> tamanhos;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Tamanho tamanho(
            sqlite3_column_int(stmt, 0),
            stringToTipoProduto(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))), // Convertendo TipoProduto para string
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))
        );
        tamanhos.push_back(tamanho);
    }

    sqlite3_finalize(stmt);
    return tamanhos;
}

// Inserir uma novo tamanho
void TamanhoDao::insert(const Tamanho& tamanho) {
    std::string sql = "INSERT INTO Tamanho (tipoProduto, nome) VALUES (?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::string tipoProdutoStr = tipoProdutoToString(tamanho.getTipoProduto()); // Converte TipoProduto pra String

    sqlite3_bind_text(stmt, 1, tipoProdutoStr.c_str(), -1, SQLITE_STATIC); 
    sqlite3_bind_text(stmt, 2, tamanho.getNome().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao inserir o tamanho: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Atualizar um tamanho existente
void TamanhoDao::update(const Tamanho& tamanho) {
    std::string sql = "UPDATE Tamanho SET tipoProduto = ?, nome = ? WHERE idTamanho = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::string tipoProdutoStr = tipoProdutoToString(tamanho.getTipoProduto());

    sqlite3_bind_text(stmt, 1, tipoProdutoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, tamanho.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, tamanho.getIdTamanho());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao atualizar o tamanho: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Deletar um tamanho pelo ID
void TamanhoDao::deleteById(int idTamanho) {
    std::string sql = "DELETE FROM Tamanho WHERE idTamanho = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idTamanho);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao deletar o tamanho: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}