#ifndef PRODUTODAO_H
#define PRODUTODAO_H

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "../model/Produto.h"

class ProdutoDao {
private:
    sqlite3* db;

public:
    // Construtor para abrir o banco
    ProdutoDao(const std::string& dbName);

    // Destrutor para fechar o banco
    ~ProdutoDao();

    // Conversores de tipos
    Sexo stringToSexo(const std::string& sexoStr);
    std::string sexoToString(const Sexo& sexo);
    FaixaEtaria stringToFaixaEtaria(const std::string& faixaEtariaStr);
    std::string faixaEtariaToString(const FaixaEtaria& faixaEtaria);

    Produto findById(int idProduto);
    std::vector<Produto> findAll();
    Produto insert(Produto& produto);
    Produto update(const Produto& produto);
    void deleteById(int idProduto);
    Produto findBySKU(const std::string& SKU);
    std::string searchTipoProduto(int idProduto);
};

#endif
