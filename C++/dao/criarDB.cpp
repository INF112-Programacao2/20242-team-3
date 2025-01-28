#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errorMessage = nullptr;

    // Abrir ou criar um banco de dados chamado "teste.db"
    int exit = sqlite3_open("BANCO.db", &db);
    if (exit) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }
    std::cout << "Banco de dados aberto/criado com sucesso!" << std::endl;

    // Criar uma tabela chamada "pessoas"
    const char* createTableSQL = R"(
        DROP TABLE IF EXISTS Pessoa;
        CREATE TABLE Pessoa (
            idPessoa INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL,
            nascimento DATE NOT NULL,
            telefone TEXT NOT NULL, 
            cpf TEXT NOT NULL UNIQUE,
            idade INTEGER NOT NULL,
            sexo TEXT CHECK(sexo IN ('MASCULINO', 'FEMININO')) NOT NULL
        );

        DROP TABLE IF EXISTS Cliente;
        CREATE TABLE Cliente (
            idCliente INTEGER PRIMARY KEY,
            envergadura REAL NOT NULL,
            peso REAL NOT NULL,
            altura REAL NOT NULL,
            torax REAL NOT NULL,
            cintura REAL NOT NULL,
            FOREIGN KEY (idCliente) REFERENCES Pessoa(idPessoa)
        );

        DROP TABLE IF EXISTS Funcionario;
        CREATE TABLE Funcionario (
            idFuncionario INTEGER PRIMARY KEY,
            email TEXT NOT NULL UNIQUE,
            senha TEXT NOT NULL,
            FOREIGN KEY (idFuncionario) REFERENCES Pessoa(idPessoa)
        );

        DROP TABLE IF EXISTS Marca;
        CREATE TABLE Marca (
            idMarca INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL
        );

        DROP TABLE IF EXISTS Modelo; 
        CREATE TABLE Modelo (
            idModelo INTEGER PRIMARY KEY AUTOINCREMENT,
            idMarca INTEGER NOT NULL,
            nome TEXT NOT NULL,
            FOREIGN KEY (idMarca) REFERENCES Marca(idMarca)
        );

        DROP TABLE IF EXISTS Tamanho;
        CREATE TABLE Tamanho (
            idTamanho INTEGER PRIMARY KEY AUTOINCREMENT,
            tipoProduto TEXT CHECK(tipoProduto IN ('BERMUDA', 'FAIXA', 'KIMONO', 'RASH_GUARD')) NOT NULL,
            nome TEXT NOT NULL
        );

        DROP TABLE IF EXISTS Cor;
        CREATE TABLE Cor (
            idCor INTEGER PRIMARY KEY AUTOINCREMENT,
            nome TEXT NOT NULL
        );

        DROP TABLE IF EXISTS Produto;
        CREATE TABLE Produto (
            idProduto INTEGER PRIMARY KEY AUTOINCREMENT,
            idMarca INTEGER NOT NULL,
            idModelo INTEGER NOT NULL,
            SKU TEXT NOT NULL UNIQUE,
            faixaEtaria TEXT CHECK(faixaEtaria IN ('ADULTO', 'INFANTIL', 'JUVENIL')) NOT NULL,
            idTamanho INTEGER NOT NULL,
            sexo TEXT CHECK(sexo IN ('MASCULINO', 'FEMININO', 'UNISSEX')) NOT NULL,
            idCor INTEGER NOT NULL,
            FOREIGN KEY (idMarca) REFERENCES Marca(idMarca),
            FOREIGN KEY (idModelo) REFERENCES Modelo(idModelo),
            FOREIGN KEY (idTamanho) REFERENCES Tamanho(idTamanho),
            FOREIGN KEY (idCor) REFERENCES Cor(idCor)
        );

        DROP TABLE IF EXISTS Kimono;
        CREATE TABLE Kimono (
            idKimono INTEGER PRIMARY KEY,
            gramaturaTecido REAL NOT NULL,
            encolhimento INTEGER NOT NULL,
            forma TEXT CHECK(forma IN ('TRADICIONAL', 'SLIM', 'ULTRASLIM')) NOT NULL,
            FOREIGN KEY (idKimono) REFERENCES Produto(idProduto)
        );

        DROP TABLE IF EXISTS Faixa;
        CREATE TABLE Faixa (
            idFaixa INTEGER PRIMARY KEY,
            espessura TEXT CHECK(espessura IN ('CLASSICA', 'ROBUSTA')) NOT NULL,
            FOREIGN KEY (idFaixa) REFERENCES Produto(idProduto)
        );

        DROP TABLE IF EXISTS Bermuda;
        CREATE TABLE Bermuda (
            idBermuda INTEGER PRIMARY KEY,
            ajuste TEXT CHECK(ajuste IN ('ELASTICO', 'BOTAO', 'AMARRACAO')) NOT NULL,
            comprimento TEXT CHECK(comprimento IN ('CURTO', 'MEDIO', 'LONGO')) NOT NULL,
            FOREIGN KEY (idBermuda) REFERENCES Produto(idProduto)
        );

        DROP TABLE IF EXISTS Rash_Guard;
        CREATE TABLE Rash_Guard (
            idRash_Guard INTEGER PRIMARY KEY,
            fps INTEGER NOT NULL,
            FOREIGN KEY (idRash_Guard) REFERENCES Produto(idProduto)
        );

        DROP TABLE IF EXISTS Venda;
        CREATE TABLE Venda (
            idVenda INTEGER PRIMARY KEY AUTOINCREMENT,
            cpf TEXT NOT NULL,
            SKU TEXT NOT NULL,
            dataVenda DATE NOT NULL,
            satisfacao TEXT CHECK(satisfacao IN ('MUITO_RUIM', 'RUIM', 'REGULAR', 'BOM', 'MUITO_BOM')) NOT NULL,
            ajuste TEXT CHECK(ajuste IN ('JUSTO', 'LEVEMENTE_JUSTO', 'BOM', 'LEVEMENTE_FOLGADO', 'FOLGADO')) NOT NULL,
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

    // Inserir um dado na tabela
    const char* insertSQL = R"(
        INSERT INTO Cor (nome) VALUES ('Azul Piscina');
    )";

    exit = sqlite3_exec(db, insertSQL, nullptr, nullptr, &errorMessage);
    if (exit != SQLITE_OK) {
        std::cerr << "Erro ao inserir dado: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return -1;
    }
    std::cout << "Dado inserido com sucesso!" << std::endl;

    // Ler os dados da tabela
    const char* selectSQL = "SELECT * FROM Cor;";
    sqlite3_stmt* stmt;

    exit = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return -1;
    }

    std::cout << "Dados na tabela:" << std::endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::cout << "ID: " << id << " | Nome: " << nome << std::endl;
    }

    // Finalizar a consulta e fechar o banco de dados
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}