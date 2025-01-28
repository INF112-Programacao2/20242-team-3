#include "ModeloDao.h"

// Construtor para abrir o banco
ModeloDao::ModeloDao(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Não foi possível abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Destrutor para fechar o banco
ModeloDao::~ModeloDao() {
    sqlite3_close(db);
}

// Buscar uma modelo pelo ID
Modelo ModeloDao::findById(int idModelo) {
    std::string sql = "SELECT idModelo, idMarca, nome FROM Modelo WHERE idModelo = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idModelo);

    Modelo modelo(0, 0, ""); // Objeto vazio para armazenar os dados
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        modelo.setIdModelo(sqlite3_column_int(stmt, 0));
        modelo.setIdMarca(sqlite3_column_int(stmt, 1));
        modelo.setNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
    } else {
        std::cerr << "Nenhuma modelo encontrada com o ID: " << idModelo << std::endl;
    }

    sqlite3_finalize(stmt);
    return modelo;
}

// Buscar todas as modelos
std::vector<Modelo> ModeloDao::findAll() {
    std::string sql = "SELECT idModelo, idMarca, nome FROM Modelo";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::vector<Modelo> modelos;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Modelo modelo(
            sqlite3_column_int(stmt, 0),
            sqlite3_column_int(stmt, 1),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))
        );
        modelos.push_back(modelo);
    }

    sqlite3_finalize(stmt);
    return modelos;
}

// Inserir um novO modelo
void ModeloDao::insert(const Modelo& modelo) {
    std::string sql = "INSERT INTO Modelo (idMarca, nome) VALUES (?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, modelo.getIdMarca());
    sqlite3_bind_text(stmt, 2, modelo.getNome().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao inserir a modelo: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Atualizar uma modelo existente
void ModeloDao::update(const Modelo& modelo) {
    std::string sql = "UPDATE Modelo SET idMarca = ?, nome = ? WHERE idModelo = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, modelo.getIdMarca());
    sqlite3_bind_text(stmt, 2, modelo.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, modelo.getIdModelo());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao atualizar a modelo: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Deletar uma modelo pelo ID
void ModeloDao::deleteById(int idModelo) {
    std::string sql = "DELETE FROM Modelo WHERE idModelo = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idModelo);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao deletar a modelo: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}