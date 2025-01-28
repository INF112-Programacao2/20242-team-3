#ifndef TAMANHODAO_H
#define TAMANHODAO_H

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "../model/Tamanho.h"

// Classe DAO para interagir com o banco de dados
class TamanhoDao {
private:
    sqlite3* db;

public:
    // Construtor para abrir o banco
    TamanhoDao(const std::string& dbName);

    // Destrutor para fechar o banco
    ~TamanhoDao();

    // Converter string para TipoProduto
    TipoProduto stringToTipoProduto(const std::string& tipoProdutoStr);

    // Converter TipoProduto para String
    std::string tipoProdutoToString(const TipoProduto& tipoProduto);

    // Buscar um tamanho pelo ID
    Tamanho findById(int idTamanho);

    // Buscar todos od tamanhos, filtrados pelo TipoProduto
    std::vector<Tamanho> findAllByTipoProduto(const std::string& tipoProduto);

    // Buscar todos os tamanhos
    std::vector<Tamanho> findAll();

    // Inserir um novo tamanho
    void insert(const Tamanho& tamanho);

    // Atualizar um tamanho existente
    void update(const Tamanho& tamanho);

    // Deletar um tamanho pelo ID
    void deleteById(int idTamanho);
};

#endif