#include "CorDao.h"
#include <stdexcept>

// Construtor para abrir o banco
CorDao::CorDao(const std::string& dbName) {
    try {
        if (sqlite3_open(dbName.c_str(), &db)) {
            throw std::runtime_error("Não foi possível abrir o banco de dados: " + std::string(sqlite3_errmsg(db)));
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro no construtor CorDao: " << e.what() << std::endl;
        throw;  // Re-lançando a exceção para que ela possa ser tratada mais acima
    }
}

// Destrutor para fechar o banco
CorDao::~CorDao() {
    try {
        if (db) {
            sqlite3_close(db);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao fechar o banco no destrutor: " << e.what() << std::endl;
    }
}

// Buscar uma cor pelo ID
Cor CorDao::findById(int idCor) {
    try {
        std::string sql = "SELECT idCor, nome FROM Cor WHERE idCor = ?";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar consulta para buscar cor pelo ID: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, idCor);

        Cor cor(0, ""); // Objeto vazio para armazenar os dados
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            cor.setIdCor(sqlite3_column_int(stmt, 0));
            cor.setNome(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        } else {
            sqlite3_finalize(stmt);
            throw std::runtime_error("Nenhuma cor encontrada com o ID: " + std::to_string(idCor));
        }

        sqlite3_finalize(stmt);
        return cor;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao buscar cor pelo ID: " << e.what() << std::endl;
        throw;  // Re-lançando a exceção
    }
}

// Buscar todas as cores
std::vector<Cor> CorDao::findAll() {
    try {
        std::string sql = "SELECT idCor, nome FROM Cor";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar consulta para buscar todas as cores: " + std::string(sqlite3_errmsg(db)));
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
    } catch (const std::exception& e) {
        std::cerr << "Erro ao buscar todas as cores: " << e.what() << std::endl;
        throw;  // Re-lançando a exceção
    }
}

// Inserir uma nova cor
void CorDao::insert(const Cor& cor) {
    try {
        std::string sql = "INSERT INTO Cor (nome) VALUES (?)";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar consulta para inserir cor: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_text(stmt, 1, cor.getNome().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw std::runtime_error("Erro ao inserir a cor: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao inserir cor: " << e.what() << std::endl;
        throw;  // Re-lançando a exceção
    }
}

// Atualizar uma cor existente
void CorDao::update(const Cor& cor) {
    try {
        std::string sql = "UPDATE Cor SET nome = ? WHERE idCor = ?";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar consulta para atualizar cor: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_text(stmt, 1, cor.getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, cor.getIdCor());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw std::runtime_error("Erro ao atualizar a cor: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao atualizar cor: " << e.what() << std::endl;
        throw;  // Re-lançando a exceção
    }
}

// Deletar uma cor pelo ID
void CorDao::deleteById(int idCor) {
    try {
        std::string sql = "DELETE FROM Cor WHERE idCor = ?";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar consulta para deletar cor: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, idCor);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
            throw std::runtime_error("Erro ao deletar a cor: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao deletar cor: " << e.what() << std::endl;
        throw;  // Re-lançando a exceção
    }
}
