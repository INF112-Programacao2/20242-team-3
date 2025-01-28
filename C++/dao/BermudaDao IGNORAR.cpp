// #pragma once
// #include <string>
// #include <vector>
// #include <optional>
// #include "sqlite3.h"
// #include "Bermuda.h" // Define a classe Bermuda

// class BermudaDao {
// private:
//     sqlite3* db;

// public:
//     BermudaDao(const std::string& dbPath) {
//         if (sqlite3_open(dbPath.c_str(), &db)) {
//             throw std::runtime_error("Erro ao abrir o banco de dados.");
//         }
//     }

//     ~BermudaDao() {
//         sqlite3_close(db);
//     }

//     // Buscar uma Bermuda pelo ID
//     Bermuda findById(int idBermuda) {
//         std::string query = "SELECT * FROM Bermuda WHERE idBermuda = ?"; //cria a query
//         sqlite3_stmt* stmt;
//         if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
//             throw std::runtime_error("Erro ao preparar a consulta SQL.");
//         }

//         // prepara a query, substituindo os argumentos
//         sqlite3_bind_int(stmt, 1, idBermuda);

//         // faz a conexão e verifica se obteve alguma linha (objeto do tipo Bermuda)
//         if (sqlite3_step(stmt) == SQLITE_ROW) {
//             Bermuda bermuda{
//                 // recupera e faz a conversão com reinterpretate_cast (coluna 0 é a 1a etc.)
//                 sqlite3_column_int(stmt, 0),  // idBermuda
//                 reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)), // ajuste, convertido pra string
//                 reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))  // comprimento
//             };

//             // encerra a conexão e retorna vazio
//             sqlite3_finalize(stmt);
//             return bermuda;
//         }

//         // Se não obteve nenhuma linha, encerra a conexão e retorna vazio
//         sqlite3_finalize(stmt);
//         return std::nullopt;
//     }

//     // Buscar todos os Bermudas
//     std::vector<Bermuda> findAll() {
//         std::string query = "SELECT * FROM Bermuda";
//         sqlite3_stmt* stmt;
//         std::vector<Bermuda> bermudas;

//         if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
//             throw std::runtime_error("Erro ao preparar a consulta SQL.");
//         }

//         while (sqlite3_step(stmt) == SQLITE_ROW) {
//             bermudas.emplace_back(
//                 sqlite3_column_int(stmt, 0),
//                 reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
//                 reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))
//             );
//         }

//         sqlite3_finalize(stmt);
//         return bermudas;
//     }

//     // Inserir um novo Bermuda
//     void insert(const Bermuda& bermuda) {
//         std::string query = "INSERT INTO Bermuda (ajuste, comprimento) VALUES (?, ?)";
//         sqlite3_stmt* stmt;

//         if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
//             throw std::runtime_error("Erro ao preparar a consulta SQL.");
//         }

//         sqlite3_bind_text(stmt, 1, bermuda.ajuste.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 2, bermuda.comprimento.c_str(), -1, SQLITE_STATIC);

//         if (sqlite3_step(stmt) != SQLITE_DONE) {
//             throw std::runtime_error("Erro ao executar a inserção.");
//         }

//         sqlite3_finalize(stmt);
//     }

//     // Atualizar uma Bermuda existente
//     void update(const Bermuda& bermuda) {
//         std::string query = "UPDATE Bermuda SET ajuste = ?, comprimento = ? WHERE idBermuda = ?";
//         sqlite3_stmt* stmt;

//         if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
//             throw std::runtime_error("Erro ao preparar a consulta SQL.");
//         }

//         sqlite3_bind_text(stmt, 1, bermuda.ajuste.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_text(stmt, 2, bermuda.comprimento.c_str(), -1, SQLITE_STATIC);
//         sqlite3_bind_int(stmt, 3, bermuda.id);

//         if (sqlite3_step(stmt) != SQLITE_DONE) {
//             throw std::runtime_error("Erro ao executar a atualização.");
//         }

//         sqlite3_finalize(stmt);
//     }

//     // Deletar uma Bermuda pelo ID
//     void deleteById(int idBermuda) {
//         std::string query = "DELETE FROM Bermuda WHERE idBermuda = ?";
//         sqlite3_stmt* stmt;

//         if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
//             throw std::runtime_error("Erro ao preparar a consulta SQL.");
//         }

//         sqlite3_bind_int(stmt, 1, idBermuda);

//         if (sqlite3_step(stmt) != SQLITE_DONE) {
//             throw std::runtime_error("Erro ao executar a exclusão.");
//         }

//         sqlite3_finalize(stmt);
//     }
// };

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "Produto.h"  // Assumindo que você tem a classe Produto já definida

// Classe que representa a Bermuda
class Bermuda : public Produto {
private:
    std::string ajuste;
    std::string comprimento;

public:
    Bermuda(int idProduto, int idMarca, Marca* marca, int idModelo, Modelo* modelo,
            const std::string& SKU, FaixaEtaria faixaEtaria, int idTamanho, Tamanho* tamanho,
            Sexo sexo, int idCor, Cor* cor, const std::string& ajuste, const std::string& comprimento)
        : Produto(idProduto, idMarca, marca, idModelo, modelo, SKU, faixaEtaria, idTamanho, tamanho, sexo, idCor, cor),
          ajuste(ajuste), comprimento(comprimento) {}

    Bermuda() : Produto(), ajuste(""), comprimento("") {}

    std::string getAjuste() const { return ajuste; }
    void setAjuste(const std::string& ajuste) { this->ajuste = ajuste; }

    std::string getComprimento() const { return comprimento; }
    void setComprimento(const std::string& comprimento) { this->comprimento = comprimento; }
};

// Classe DAO para interagir com o banco de dados
class BermudaDao {
private:
    sqlite3* db;

public:
    BermudaDao(const std::string& dbName) {
        if (sqlite3_open(dbName.c_str(), &db)) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        }
    }

    ~BermudaDao() {
        sqlite3_close(db);
    }

    Bermuda findById(int idBermuda) {
        std::string sql = "SELECT idBermuda, ajuste, comprimento FROM Bermuda WHERE idBermuda = " + std::to_string(idBermuda);
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

        Bermuda bermuda(0, 0, nullptr, 0, nullptr, "", FaixaEtaria::ADULTO, 0, nullptr, Sexo::MASCULINO, 0, nullptr, "", "");

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            bermuda.setIdProduto(sqlite3_column_int(stmt, 0));
            bermuda.setAjuste(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            bermuda.setComprimento(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        }

        sqlite3_finalize(stmt);
        return bermuda;
    }

    std::vector<Bermuda> findAll() {
        std::string sql = "SELECT idBermuda, ajuste, comprimento FROM Bermuda";
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

        std::vector<Bermuda> bermudas;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Bermuda bermuda(
                sqlite3_column_int(stmt, 0),
                0, nullptr, 0, nullptr, "", FaixaEtaria::ADULTO, 0, nullptr, Sexo::MASCULINO, 0, nullptr,
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
                reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))
            );
            bermudas.push_back(bermuda);
        }

        sqlite3_finalize(stmt);
        return bermudas;
    }

    void insert(const Bermuda& bermuda) {
        std::string sql = "INSERT INTO Bermuda (ajuste, comprimento) VALUES (?, ?)";
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

        sqlite3_bind_text(stmt, 1, bermuda.getAjuste().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, bermuda.getComprimento().c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void update(const Bermuda& bermuda) {
        std::string sql = "UPDATE Bermuda SET ajuste = ?, comprimento = ? WHERE idBermuda = ?";
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

        sqlite3_bind_text(stmt, 1, bermuda.getAjuste().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, bermuda.getComprimento().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, bermuda.getIdProduto());

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void deleteById(int idBermuda) {
        std::string sql = "DELETE FROM Bermuda WHERE idBermuda = ?";
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

        sqlite3_bind_int(stmt, 1, idBermuda);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
};

int main() {
    BermudaDao bermudaDao("estoque.db");

    Bermuda bermuda(1, 1, nullptr, 1, nullptr, "SKU001", FaixaEtaria::ADULTO, 1, nullptr, Sexo::MASCULINO, 1, nullptr, "Ajuste1", "Curto");
    bermudaDao.insert(bermuda);

    Bermuda retrievedBermuda = bermudaDao.findById(1);
    std::cout << "Bermuda ID: " << retrievedBermuda.getIdProduto() << ", Ajuste: " << retrievedBermuda.getAjuste() << ", Comprimento: " << retrievedBermuda.getComprimento() << std::endl;

    retrievedBermuda.setAjuste("Ajuste2");
    bermudaDao.update(retrievedBermuda);

    bermudaDao.deleteById(1);

    return 0;
}
