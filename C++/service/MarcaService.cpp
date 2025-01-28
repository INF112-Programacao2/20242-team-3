#include "MarcaService.h"

// Construtor
MarcaService::MarcaService(MarcaDao& dao) : marcaDao(dao) {}

// Obter Marca por ID
Marca MarcaService::getById(int id) {
    return marcaDao.findById(id);
}

// Obter todas as Marcas
std::vector<Marca> MarcaService::getAll() {
    return marcaDao.findAll();
}

// Inserir uma nova Marca
void MarcaService::insert(const Marca& marca) {
    marcaDao.insert(marca);
}

// Atualizar uma Marca existente
void MarcaService::update(const Marca& marca) {
    marcaDao.update(marca);
}

// Deletar uma Marca pelo ID
void MarcaService::deleteById(int id) {
    marcaDao.deleteById(id);
}
