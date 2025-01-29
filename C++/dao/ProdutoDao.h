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

    // Conversores de ENUMS para STRING
    std::string sexoToString(const Sexo& sexo);
    std::string faixaEtariaToString(const FaixaEtaria& faixaEtaria);
    std::string marcaToString(Marca marca);
    std::string modeloToString(Modelo modelo);
    std::string tamanhoToString(Tamanho tamanho);
    std::string corToString(Cor cor);

    // Conversores de STRING para ENUMS
    Sexo stringToSexo(const std::string& sexoStr);
    FaixaEtaria stringToFaixaEtaria(const std::string& faixaEtariaStr);
    Marca stringToMarca(const std::string& marcaStr);
    Modelo stringToModelo(const std::string& modeloStr);
    Tamanho stringToTamanho(const std::string& tamanhoStr);
    Cor stringToCor(const std::string& corStr);

    Produto findById(int idProduto);
    std::vector<Produto> findAll();
    Produto insert(Produto& produto);
    Produto update(const Produto& produto);
    void deleteById(int idProduto);
    Produto findBySKU(const std::string& SKU);
    std::string searchTipoProduto(int idProduto);
};

#endif
