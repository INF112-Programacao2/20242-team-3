#ifndef MODELO_SERVICE_H
#define MODELO_SERVICE_H

#include "ModeloDao.h"
#include "Modelo.h"
#include <vector>
#include <memory>

class ModeloService {
private:
    std::shared_ptr<ModeloDao> modeloDao; // Ponteiro inteligente para o ModeloDao

public:
    // Construtor
    explicit ModeloService(std::shared_ptr<ModeloDao> dao);

    // Buscar um modelo pelo ID
    Modelo getById(int id);

    // Buscar todos os modelos
    std::vector<Modelo> getAll();

    // Buscar todos os modelos por ID da marca
    std::vector<Modelo> getAllByMarca(int idMarca);

    // Inserir um novo modelo
    void insert(const Modelo& modelo);

    // Atualizar um modelo existente
    void update(const Modelo& modelo);

    // Deletar um modelo pelo ID
    void deleteById(int id);
};

#endif // MODELO_SERVICE_H
