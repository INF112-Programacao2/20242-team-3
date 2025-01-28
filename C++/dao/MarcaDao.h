#ifndef MARCADAO_H
#define MARCADAO_H

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "../model/Marca.h"

// Classe DAO para interagir com o banco de dados
class MarcaDao {
private:
    sqlite3* db;

public:
    // Construtor para abrir o banco
    MarcaDao(const std::string& dbName);

    // Destrutor para fechar o banco
    ~MarcaDao();

    // Buscar uma marca pelo ID
    Marca findById(int idMarca);

    // Buscar todas as marcas
    std::vector<Marca> findAll();

    // Inserir uma nova marca
    void insert(const Marca& marca);

    // Atualizar uma marca existente
    void update(const Marca& marca);

    // Deletar uma marca pelo ID
    void deleteById(int idMarca);
};

#endif