#include "BermudaDao.h"
#include "ProdutoDao.h"
#include <stdexcept>
#include <iostream>

// Construtor que recebe o nome do banco de dados
BermudaDao::BermudaDao(const std::string& dbPath) {
    try {
        if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
            throw std::runtime_error("Erro ao abrir o banco de dados: " + std::string(sqlite3_errmsg(db)));
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro no construtor do BermudaDao: " << e.what() << std::endl;
        throw;
    }
}

// Destrutor para fechar a conexão com o banco de dados
BermudaDao::~BermudaDao() {
    try {
        if (db) {
            sqlite3_close(db);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao fechar conexão com banco de dados: " << e.what() << std::endl;
    }
}

// Converter ENUMS para STRING
std::string BermudaDao::ajusteToString(Ajuste ajuste) {
    try {
        switch (ajuste) {
            case Ajuste::ELASTICO: return "ELASTICO";
            case Ajuste::BOTAO: return "BOTAO";
            case Ajuste::AMARRACAO: return "AMARRACAO";
            default: throw std::invalid_argument("Ajuste inválido");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro na conversão de Ajuste para string: " << e.what() << std::endl;
        throw;
    }
}

std::string BermudaDao::comprimentoToString(Comprimento comprimento) {
    try {
        switch (comprimento) {
            case Comprimento::CURTO: return "CURTO";
            case Comprimento::MEDIO: return "MEDIO";
            case Comprimento::LONGO: return "LONGO";
            default: throw std::invalid_argument("Comprimento inválido");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro na conversão de Comprimento para string: " << e.what() << std::endl;
        throw;
    }
}

// Converter STRING para ENUMS
Ajuste BermudaDao::stringToAjuste(const std::string& ajusteStr) {
    try {
        if (ajusteStr == "ELASTICO") return Ajuste::ELASTICO;
        if (ajusteStr == "BOTAO") return Ajuste::BOTAO;
        if (ajusteStr == "AMARRACAO") return Ajuste::AMARRACAO;
        throw std::invalid_argument("Ajuste inválido: " + ajusteStr);
    } catch (const std::exception& e) {
        std::cerr << "Erro na conversão de string para Ajuste: " << e.what() << std::endl;
        throw;
    }
}

Comprimento BermudaDao::stringToComprimento(const std::string& comprimentoStr) {
    try {
        if (comprimentoStr == "CURTO") return Comprimento::CURTO;
        if (comprimentoStr == "MEDIO") return Comprimento::MEDIO;
        if (comprimentoStr == "LONGO") return Comprimento::LONGO;
        throw std::invalid_argument("Comprimento inválido: " + comprimentoStr);
    } catch (const std::exception& e) {
        std::cerr << "Erro na conversão de string para Comprimento: " << e.what() << std::endl;
        throw;
    }
}

// Buscar uma Bermuda pelo ID
Bermuda BermudaDao::findById(int idBermuda) {
    sqlite3_stmt* stmt = nullptr;
    try {
        const char* sql = "SELECT * FROM Bermuda WHERE idBermuda = ?;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a consulta SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, idBermuda);

        Bermuda bermuda;
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            // Buscar o Produto correspondente
            ProdutoDao produtoDao("NovoBanco.db");
            Produto produto = produtoDao.findById(idBermuda);

            // Copiar os valores do Produto para o Bermuda
            bermuda.setIdProduto(produto.getIdProduto());
            bermuda.setMarca(produto.getMarca());
            bermuda.setModelo(produto.getModelo());
            bermuda.setSKU(produto.getSKU());
            bermuda.setFaixaEtaria(produto.getFaixaEtaria());
            bermuda.setTamanho(produto.getTamanho());
            bermuda.setSexo(produto.getSexo());
            bermuda.setCor(produto.getCor());

            // Preencher os atributos específicos do Bermuda
            Ajuste ajuste = stringToAjuste(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            Comprimento comprimento = stringToComprimento(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

            bermuda.setAjuste(ajuste);
            bermuda.setComprimento(comprimento);
        } else {
            throw std::runtime_error("Bermuda não encontrada com ID: " + std::to_string(idBermuda));
        }

        sqlite3_finalize(stmt);
        return bermuda;
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao buscar Bermuda por ID: " << e.what() << std::endl;
        throw;
    }
}

// Buscar todos as Bermudas
std::vector<Bermuda> BermudaDao::findAll() {
    sqlite3_stmt* stmt = nullptr;
    try {
        std::vector<Bermuda> bermudas;
        const char* sql = "SELECT * FROM Bermuda;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a consulta SQL: " + std::string(sqlite3_errmsg(db)));
        }

        ProdutoDao produtoDao("NovoBanco.db");

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            try {
                int idBermuda = sqlite3_column_int(stmt, 0);
                Ajuste ajuste = stringToAjuste(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
                Comprimento comprimento = stringToComprimento(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

                // Buscar os dados da tabela Produto
                Produto produto = produtoDao.findById(idBermuda);

                // Criar um objeto Bermuda preenchido corretamente
                Bermuda bermuda(
                    produto.getIdProduto(),
                    produto.getMarca(),
                    produto.getModelo(),
                    produto.getSKU(),
                    produto.getFaixaEtaria(),
                    produto.getTamanho(),
                    produto.getSexo(),
                    produto.getCor(),
                    ajuste,
                    comprimento
                );

                bermudas.push_back(bermuda);
            } catch (const std::exception& e) {
                std::cerr << "Erro ao processar registro individual: " << e.what() << std::endl;
                continue;
            }
        }

        sqlite3_finalize(stmt);
        return bermudas;
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao buscar todas as Bermudas: " << e.what() << std::endl;
        throw;
    }
}

// Inserir uma nova Bermuda
void BermudaDao::insert(Bermuda& bermuda) {
    sqlite3_stmt* stmt = nullptr;
    try {
        // Inserindo o Produto primeiro
        ProdutoDao produtoDao("NovoBanco.db");
        Produto produtoInserido = produtoDao.insert(bermuda);
        
        // Atualiza o ID do produto no objeto Bermuda
        bermuda.setIdProduto(produtoInserido.getIdProduto());

        const char* sql = "INSERT INTO Bermuda (idBermuda, ajuste, comprimento) VALUES (?, ?, ?);";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a inserção SQL: " + std::string(sqlite3_errmsg(db)));
        }

        std::string ajusteStr = ajusteToString(bermuda.getAjuste());
        std::string comprimentoStr = comprimentoToString(bermuda.getComprimento());

        sqlite3_bind_int(stmt, 1, bermuda.getIdProduto());
        sqlite3_bind_text(stmt, 2, ajusteStr.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, comprimentoStr.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("Erro ao inserir Bermuda: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao inserir Bermuda: " << e.what() << std::endl;
        throw;
    }
}

// Atualizar uma Bermuda existente
void BermudaDao::update(Bermuda& bermuda) {
    sqlite3_stmt* stmt = nullptr;
    try {
        // Atualizando o Produto primeiro
        ProdutoDao produtoDao("NovoBanco.db");
        Produto produtoAtualizado = produtoDao.update(bermuda);
        
        // Atualiza o ID do produto no objeto Bermuda
        bermuda.setIdProduto(produtoAtualizado.getIdProduto());

        const char* sql = "UPDATE Bermuda SET ajuste = ?, comprimento = ? WHERE idBermuda = ?;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a atualização SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_text(stmt, 1, ajusteToString(bermuda.getAjuste()).c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, comprimentoToString(bermuda.getComprimento()).c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, bermuda.getIdProduto());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("Erro ao atualizar Bermuda: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao atualizar Bermuda: " << e.what() << std::endl;
        throw;
    }
}

// Deletar uma Bermuda pelo ID
void BermudaDao::deleteById(int idBermuda) {
    sqlite3_stmt* stmt = nullptr;
    try {
        const char* sql = "DELETE FROM Bermuda WHERE idBermuda = ?;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a exclusão SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, idBermuda);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("Erro ao excluir Bermuda: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao excluir Bermuda: " << e.what() << std::endl;
        throw;
    }
}