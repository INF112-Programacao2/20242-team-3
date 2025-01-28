#ifndef MARCASERVICE_H
#define MARCASERVICE_H

#include "MarcaDao.h"
#include "Marca.h"
#include <vector>

class MarcaService {
private:
    MarcaDao& marcaDao; // Referência ao DAO

public:
    // Construtor
    MarcaService(MarcaDao& dao);

    // Obter Marca por ID
    Marca getById(int id);

    // Obter todas as Marcas
    std::vector<Marca> getAll();

    // Inserir uma nova Marca
    void insert(const Marca& marca);

    // Atualizar uma Marca existente
    void update(const Marca& marca);

    // Deletar uma Marca pelo ID
    void deleteById(int id);
};

#endif // MARCASERVICE_H
