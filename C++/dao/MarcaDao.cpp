#include "MarcaDao.h"

// Construtor para abrir o banco
MarcaDao::MarcaDao(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Não foi possível abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Destrutor para fechar o banco
MarcaDao::~MarcaDao() {
    sqlite3_close(db);
}

// Buscar uma marca pelo ID
Marca MarcaDao::findById(int idMarca) {
    std::string sql = "SELECT idMarca, nome FROM Marca WHERE idMarca = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idMarca);

    Marca marca(0, ""); // Objeto vazio para armazenar os dados
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        marca.setIdMarca(sqlite3_column_int(stmt, 0));
        marca.setNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
    } else {
        std::cerr << "Nenhuma marca encontrada com o ID: " << idMarca << std::endl;
    }

    sqlite3_finalize(stmt);
    return marca;
}

// Buscar todas as marcas
std::vector<Marca> MarcaDao::findAll() {
    std::string sql = "SELECT idMarca, nome FROM Marca";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::vector<Marca> marcas;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Marca marca(
            sqlite3_column_int(stmt, 0),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))
        );
        marcas.push_back(marca);
    }

    sqlite3_finalize(stmt);
    return marcas;
}

// Inserir uma nova marca
void MarcaDao::insert(const Marca& marca) {
    std::string sql = "INSERT INTO Marca (nome) VALUES (?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, marca.getNome().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao inserir a marca: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Atualizar uma marca existente
void MarcaDao::update(const Marca& marca) {
    std::string sql = "UPDATE Marca SET nome = ? WHERE idMarca = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, marca.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, marca.getIdMarca());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao atualizar a marca: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}

// Deletar uma marca pelo ID
void MarcaDao::deleteById(int idMarca) {
    std::string sql = "DELETE FROM Marca WHERE idMarca = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idMarca);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Erro ao deletar a marca: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
}