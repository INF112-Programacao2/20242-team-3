#include "TamanhoService.h"

// Construtor
TamanhoService::TamanhoService(TamanhoDao& dao) : tamanhoDao(dao) {}

// Obter Tamanho por ID
Tamanho TamanhoService::getById(int id) {
    return tamanhoDao.findById(id);
}

// Obter todos os Tamanhos
std::vector<Tamanho> TamanhoService::getAll() {
    return tamanhoDao.findAll();
}

// Obter todos os Tamanhos por TipoProduto
std::vector<Tamanho> TamanhoService::getAllByTipoProduto(const std::string& tipoProduto) {
    return tamanhoDao.findAllByTipoProduto(tipoProduto);
}

// Inserir um novo Tamanho
void TamanhoService::insert(const Tamanho& tamanho) {
    tamanhoDao.insert(tamanho);
}

// Atualizar um Tamanho existente
void TamanhoService::update(const Tamanho& tamanho) {
    tamanhoDao.update(tamanho);
}

// Deletar um Tamanho pelo ID
void TamanhoService::deleteById(int id) {
    tamanhoDao.deleteById(id);
}
