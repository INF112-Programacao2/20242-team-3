#ifndef CORSERVICE_H
#define CORSERVICE_H

#include "CorDao.h"
#include "Cor.h"
#include <vector>

class CorService {
private:
    CorDao& corDao; // Referência ao DAO

public:
    // Construtor
    CorService(CorDao& dao);

    // Obter Cor por ID
    Cor getById(int id);

    // Obter todas as Cores
    std::vector<Cor> getAll();

    // Inserir uma nova Cor
    void insert(const Cor& cor);

    // Atualizar uma Cor existente
    void update(const Cor& cor);

    // Deletar uma Cor pelo ID
    void deleteById(int id);
};

#endif // CORSERVICE_H
