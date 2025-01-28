#ifndef MARCADAO_H
#define MARCADAO_H

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "../model/Modelo.h"

// Classe DAO para interagir com o banco de dados
class ModeloDao {
private:
    sqlite3* db;

public:
    // Construtor para abrir o banco
    ModeloDao(const std::string& dbName);

    // Destrutor para fechar o banco
    ~ModeloDao();

    // Buscar um modelo pelo ID
    Modelo findById(int idModelo);

    // Buscar todos os modelos
    std::vector<Modelo> findAll();

    // Inserir um novo modelo
    void insert(const Modelo& modelo);

    // Atualizar um modelo existente
    void update(const Modelo& modelo);

    // Deletar um modelo pelo ID
    void deleteById(int idModelo);
};

#endif