#include "KimonoDao.h"
#include <stdexcept>
#include <iostream>

// Construtor que recebe o nome do banco de dados
KimonoDao::KimonoDao(const std::string& dbPath) {
    try {
        if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
            throw std::runtime_error("Erro ao abrir o banco de dados: " + std::string(sqlite3_errmsg(db)));
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro no construtor do KimonoDao: " << e.what() << std::endl;
        throw;
    }
}

// Destrutor para fechar a conexão com o banco de dados
KimonoDao::~KimonoDao() {
    try {
        if (db) {
            sqlite3_close(db);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao fechar conexão com banco de dados: " << e.what() << std::endl;
    }
}

// Converter enum Forma para string
std::string KimonoDao::formaToString(Forma forma) {
    try {
        switch (forma) {
            case Forma::TRADICIONAL: return "TRADICIONAL";
            case Forma::SLIM: return "SLIM";
            case Forma::ULTRASLIM: return "ULTRASLIM";
            default: throw std::invalid_argument("Forma inválida");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro na conversão de Forma para string: " << e.what() << std::endl;
        throw;
    }
}

// Converter string para enum Forma
Forma KimonoDao::stringToForma(const std::string& formaStr) {
    try {
        if (formaStr == "TRADICIONAL") return Forma::TRADICIONAL;
        if (formaStr == "SLIM") return Forma::SLIM;
        if (formaStr == "ULTRASLIM") return Forma::ULTRASLIM;
        throw std::invalid_argument("Forma inválida: " + formaStr);
    } catch (const std::exception& e) {
        std::cerr << "Erro na conversão de string para Forma: " << e.what() << std::endl;
        throw;
    }
}

// Buscar um Kimono pelo ID
Kimono KimonoDao::findById(int idKimono) {
    sqlite3_stmt* stmt = nullptr;
    try {
        const char* sql = "SELECT * FROM Kimono WHERE idKimono = ?;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a consulta SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, idKimono);

        Kimono kimono;
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            // Buscar o Produto correspondente
            ProdutoDao produtoDao("NovoBanco.db");
            Produto produto = produtoDao.findById(idKimono);

            // Copiar os valores do Produto para o Kimono
            kimono.setIdProduto(produto.getIdProduto());
            kimono.setMarca(produto.getMarca());
            kimono.setModelo(produto.getModelo());
            kimono.setSKU(produto.getSKU());
            kimono.setFaixaEtaria(produto.getFaixaEtaria());
            kimono.setTamanho(produto.getTamanho());
            kimono.setSexo(produto.getSexo());
            kimono.setCor(produto.getCor());

            // Preencher os atributos específicos do Kimono
            double gramatura = sqlite3_column_double(stmt, 1);
            int encolhimento = sqlite3_column_int(stmt, 2);
            std::string formaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

            Forma forma = stringToForma(formaStr);

            kimono.setGramaturaTecido(gramatura);
            kimono.setEncolhimento(encolhimento);
            kimono.setForma(forma);
        } else {
            throw std::runtime_error("Kimono não encontrado com ID: " + std::to_string(idKimono));
        }

        sqlite3_finalize(stmt);
        return kimono;
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao buscar Kimono por ID: " << e.what() << std::endl;
        throw;
    }
}

// Buscar todos os Kimonos
std::vector<Kimono> KimonoDao::findAll() {
    sqlite3_stmt* stmt = nullptr;
    try {
        std::vector<Kimono> kimonos;
        const char* sql = "SELECT * FROM Kimono;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a consulta SQL: " + std::string(sqlite3_errmsg(db)));
        }

        ProdutoDao produtoDao("NovoBanco.db");

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            try {
                int idKimono = sqlite3_column_int(stmt, 0);
                double gramatura = sqlite3_column_double(stmt, 1);
                int encolhimento = sqlite3_column_int(stmt, 2);
                std::string formaStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

                Forma forma = stringToForma(formaStr);

                // Buscar os dados da tabela Produto
                Produto produto = produtoDao.findById(idKimono);

                // Criar um objeto Kimono preenchido corretamente
                Kimono kimono(
                    produto.getIdProduto(),
                    produto.getMarca(),
                    produto.getModelo(),
                    produto.getSKU(),
                    produto.getFaixaEtaria(),
                    produto.getTamanho(),
                    produto.getSexo(),
                    produto.getCor(),
                    gramatura,
                    encolhimento,
                    forma
                );

                kimonos.push_back(kimono);
            } catch (const std::exception& e) {
                std::cerr << "Erro ao processar registro individual: " << e.what() << std::endl;
                continue;
            }
        }

        sqlite3_finalize(stmt);
        return kimonos;
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao buscar todos os Kimonos: " << e.what() << std::endl;
        throw;
    }
}

// Inserir um novo Kimono
void KimonoDao::insert(Kimono& kimono) {
    sqlite3_stmt* stmt = nullptr;
    try {
        // Inserindo o Produto primeiro
        ProdutoDao produtoDao("NovoBanco.db");
        Produto produtoInserido = produtoDao.insert(kimono);

        // Atualiza o ID do produto no objeto Kimono
        kimono.setIdProduto(produtoInserido.getIdProduto());

        const char* sql = "INSERT INTO Kimono (idKimono, gramaturaTecido, encolhimento, forma) VALUES (?, ?, ?, ?);";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a inserção SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, kimono.getIdProduto());
        sqlite3_bind_double(stmt, 2, kimono.getGramaturaTecido());
        sqlite3_bind_int(stmt, 3, kimono.getEncolhimento());
        sqlite3_bind_text(stmt, 4, formaToString(kimono.getForma()).c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("Erro ao inserir Kimono: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao inserir Kimono: " << e.what() << std::endl;
        throw;
    }
}

// Atualizar um Kimono existente
void KimonoDao::update(Kimono& kimono) {
    sqlite3_stmt* stmt = nullptr;
    try {
        // Inserindo o Produto primeiro
        ProdutoDao produtoDao("NovoBanco.db");
        Produto produtoInserido = produtoDao.update(kimono);

        // Atualiza o ID do produto no objeto Kimono
        kimono.setIdProduto(produtoInserido.getIdProduto());

        const char* sql = "UPDATE Kimono SET gramaturaTecido = ?, encolhimento = ?, forma = ? WHERE idKimono = ?;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a atualização SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_double(stmt, 1, kimono.getGramaturaTecido());
        sqlite3_bind_int(stmt, 2, kimono.getEncolhimento());
        sqlite3_bind_text(stmt, 3, formaToString(kimono.getForma()).c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, kimono.getIdProduto());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("Erro ao atualizar Kimono: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao atualizar Kimono: " << e.what() << std::endl;
        throw;
    }
}

// Deletar um Kimono pelo ID
void KimonoDao::deleteById(int idKimono) {
    sqlite3_stmt* stmt = nullptr;
    try {
        const char* sql = "DELETE FROM Kimono WHERE idKimono = ?;";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            throw std::runtime_error("Erro ao preparar a exclusão SQL: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_bind_int(stmt, 1, idKimono);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            throw std::runtime_error("Erro ao excluir Kimono: " + std::string(sqlite3_errmsg(db)));
        }

        sqlite3_finalize(stmt);
    } catch (const std::exception& e) {
        if (stmt) sqlite3_finalize(stmt);
        std::cerr << "Erro ao excluir Kimono: " << e.what() << std::endl;
        throw;
    }
}