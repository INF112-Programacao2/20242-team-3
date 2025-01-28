#ifndef TAMANHOSERVICE_H
#define TAMANHOSERVICE_H

#include "TamanhoDao.h"
#include "Tamanho.h"
#include <vector>
#include <string>

class TamanhoService {
private:
    TamanhoDao& tamanhoDao; // Referência ao DAO

public:
    // Construtor
    TamanhoService(TamanhoDao& dao);

    // Obter Tamanho por ID
    Tamanho getById(int id);

    // Obter todos os Tamanhos
    std::vector<Tamanho> getAll();

    // Obter todos os Tamanhos por TipoProduto
    std::vector<Tamanho> getAllByTipoProduto(const std::string& tipoProduto);

    // Inserir um novo Tamanho
    void insert(const Tamanho& tamanho);

    // Atualizar um Tamanho existente
    void update(const Tamanho& tamanho);

    // Deletar um Tamanho pelo ID
    void deleteById(int id);
};

#endif // TAMANHOSERVICE_H
