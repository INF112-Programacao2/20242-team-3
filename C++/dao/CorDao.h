#ifndef CORDAO_H
#define CORDAO_H

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "../model/Cor.h"

// Classe DAO para interagir com o banco de dados
class CorDao {
private:
    sqlite3* db;

public:
    // Construtor para abrir o banco
    CorDao(const std::string& dbName);

    // Destrutor para fechar o banco
    ~CorDao();

    // Buscar uma cor pelo ID
    Cor findById(int idCor);

    // Buscar todas as cores
    std::vector<Cor> findAll();

    // Inserir uma nova cor
    void insert(const Cor& cor);

    // Atualizar uma cor existente
    void update(const Cor& cor);

    // Deletar uma cor pelo ID
    void deleteById(int idCor);
};

#endif