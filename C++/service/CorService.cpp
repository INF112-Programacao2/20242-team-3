#include "CorDao.h"
#include "Cor.h"
#include <vector>

class CorService {
private:
    CorDao& corDao; // Referência ao DAO

public:
    // Construtor
    CorService(CorDao& dao) : corDao(dao) {}

    // Obter Cor por ID
    Cor getById(int id) {
        return corDao.findById(id);
    }

    // Obter todas as Cores
    std::vector<Cor> getAll() {
        return corDao.findAll();
    }

    // Inserir uma nova Cor
    void insert(const Cor& cor) {
        corDao.insert(cor);
    }

    // Atualizar uma Cor existente
    void update(const Cor& cor) {
        corDao.update(cor);
    }

    // Deletar uma Cor pelo ID
    void deleteById(int id) {
        corDao.deleteById(id);
    }
};
