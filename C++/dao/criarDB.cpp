#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errorMessage = nullptr;

    // Abrir ou criar um banco de dados chamado "teste.db"
    int exit = sqlite3_open("NovoBanco.db", &db);
    if (exit) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }
    std::cout << "Banco de dados aberto/criado com sucesso!" << std::endl;

    // Criar uma tabela chamada "pessoas"
    const char* createTableSQL = R"(

        CREATE TABLE IF NOT EXISTS Pessoa (
            idPessoa INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL,
            nascimento DATE NOT NULL,
            telefone TEXT NOT NULL, 
            cpf TEXT NOT NULL UNIQUE,
            idade INTEGER NOT NULL CHECK(idade >= 0 AND idade <= 255), -- SQLite usa INTEGER e permite CHECK constraints.
            sexo TEXT NOT NULL CHECK(sexo IN ('MASCULINO', 'FEMININO')) -- Emula o comportamento de ENUM com CHECK.
        );

        CREATE TABLE IF NOT EXISTS Cliente (
            idCliente INTEGER NOT NULL,
            envergadura REAL NOT NULL, -- DECIMAL é mapeado como REAL no SQLite.
            peso REAL NOT NULL,
            altura REAL NOT NULL,
            torax REAL NOT NULL,
            cintura REAL NOT NULL,
            PRIMARY KEY (idCliente),
            FOREIGN KEY (idCliente) REFERENCES Pessoa(idPessoa)
        );

        CREATE TABLE IF NOT EXISTS Funcionario (
            idFuncionario INTEGER NOT NULL,
            email TEXT NOT NULL UNIQUE,
            senha TEXT NOT NULL,
            PRIMARY KEY (idFuncionario),
            FOREIGN KEY (idFuncionario) REFERENCES Pessoa(idPessoa)
        );

        CREATE TABLE IF NOT EXISTS Produto (
            idProduto INTEGER PRIMARY KEY AUTOINCREMENT,
            marca TEXT NOT NULL CHECK(marca IN ('KVRA', 'VOUK', 'DUBAI', 'SUERTE')),
            modelo TEXT NOT NULL CHECK(modelo IN ('COMUM', 'REFORÇADO')),
            SKU TEXT NOT NULL UNIQUE,
            faixaEtaria TEXT NOT NULL CHECK(faixaEtaria IN ('ADULTO', 'INFANTIL', 'JUVENIL')),
            tamanho TEXT NOT NULL CHECK(tamanho IN ('P', 'M', 'G', 'GG', 'XGG')),
            sexo TEXT NOT NULL CHECK(sexo IN ('MASCULINO', 'FEMININO', 'UNISSEX')),
            cor TEXT NOT NULL CHECK(cor IN ('PRETO', 'BRANCO', 'AZUL', 'ROSA', 'CINZA', 'VERDE'))
        );

        CREATE TABLE IF NOT EXISTS Kimono (
            idKimono INTEGER NOT NULL,
            gramaturaTecido REAL NOT NULL,
            encolhimento INTEGER NOT NULL,
            forma TEXT NOT NULL CHECK(forma IN ('TRADICIONAL', 'SLIM', 'ULTRASLIM')),
            PRIMARY KEY (idKimono),
            FOREIGN KEY (idKimono) REFERENCES Produto(idProduto)
        );

        CREATE TABLE IF NOT EXISTS Faixa (
            idFaixa INTEGER NOT NULL,
            espessura TEXT NOT NULL CHECK(espessura IN ('CLASSICA', 'ROBUSTA')),
            PRIMARY KEY (idFaixa),
            FOREIGN KEY (idFaixa) REFERENCES Produto(idProduto)
        );

        CREATE TABLE IF NOT EXISTS Bermuda (
            idBermuda INTEGER NOT NULL,
            ajuste TEXT NOT NULL CHECK(ajuste IN ('ELASTICO', 'BOTAO', 'AMARRACAO')),
            comprimento TEXT NOT NULL CHECK(comprimento IN ('CURTO', 'MEDIO', 'LONGO')),
            PRIMARY KEY (idBermuda),
            FOREIGN KEY (idBermuda) REFERENCES Produto(idProduto)
        );

        CREATE TABLE IF NOT EXISTS Venda (
            idVenda INTEGER PRIMARY KEY AUTOINCREMENT,
            cpf TEXT NOT NULL,
            SKU TEXT NOT NULL,
            dataVenda DATE NOT NULL,
            satisfacao TEXT NOT NULL CHECK(satisfacao IN ('MUITO_RUIM', 'RUIM', 'REGULAR', 'BOM', 'MUITO_BOM')),
            ajuste TEXT NOT NULL CHECK(ajuste IN ('JUSTO', 'LEVEMENTE_JUSTO', 'BOM', 'LEVEMENTE_FOLGADO', 'FOLGADO')),
            FOREIGN KEY (cpf) REFERENCES Pessoa(cpf),
            FOREIGN KEY (SKU) REFERENCES Produto(SKU)
        );

    )";

    exit = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMessage);
    if (exit != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return -1;
    }
    std::cout << "Tabela criada com sucesso!" << std::endl;

    // // Inserir um dado na tabela
    // const char* insertSQL = R"(
    //     INSERT INTO Cor (nome) VALUES ('Azul Piscina');
    // )";

    // exit = sqlite3_exec(db, insertSQL, nullptr, nullptr, &errorMessage);
    // if (exit != SQLITE_OK) {
    //     std::cerr << "Erro ao inserir dado: " << errorMessage << std::endl;
    //     sqlite3_free(errorMessage);
    //     sqlite3_close(db);
    //     return -1;
    // }
    // std::cout << "Dado inserido com sucesso!" << std::endl;

    // // Ler os dados da tabela
    // const char* selectSQL = "SELECT * FROM Cor;";
    // sqlite3_stmt* stmt;

    // exit = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
    // if (exit != SQLITE_OK) {
    //     std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
    //     sqlite3_close(db);
    //     return -1;
    // }

    // std::cout << "Dados na tabela:" << std::endl;
    // while (sqlite3_step(stmt) == SQLITE_ROW) {
    //     int id = sqlite3_column_int(stmt, 0);
    //     const char* nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    //     std::cout << "ID: " << id << " | Nome: " << nome << std::endl;
    // }

    // // Finalizar a consulta e fechar o banco de dados
    // sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}