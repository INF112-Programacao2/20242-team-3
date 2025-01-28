#include "BermudaService.h"
#include <iostream>

// Construtor
BermudaService::BermudaService(BermudaDao bermudaDao, ProdutoDao produtoDao, MarcaDao marcaDao,
                               ModeloDao modeloDao, TamanhoDao tamanhoDao, CorDao corDao)
    : bermudaDao(bermudaDao), produtoDao(produtoDao), marcaDao(marcaDao), modeloDao(modeloDao),
      tamanhoDao(tamanhoDao), corDao(corDao) {}

// Método getById
Bermuda BermudaService::getById(int idProduto) {
    // Recupera o Produto associado ao ID
    Produto produto = produtoDao.findById(idProduto);
    if (produto.getIdProduto() == 0) {
        return Bermuda(); // Retorna um objeto vazio se não encontrar o produto
    }

    Bermuda bermuda = bermudaDao.findById(idProduto);
    bermuda.setIdProduto(produto.getIdProduto());
    bermuda.setIdMarca(produto.getIdMarca());
    bermuda.setMarca(marcaDao.findById(bermuda.getIdMarca()));
    bermuda.setIdModelo(produto.getIdModelo());
    bermuda.setModelo(modeloDao.findById(bermuda.getIdModelo()));
    bermuda.setSKU(produto.getSKU());
    bermuda.setFaixaEtaria(produto.getFaixaEtaria());
    bermuda.setIdTamanho(produto.getIdTamanho());
    bermuda.setTamanho(tamanhoDao.findById(bermuda.getIdTamanho()));
    bermuda.setSexo(produto.getSexo());
    bermuda.setIdCor(produto.getIdCor());
    bermuda.setCor(corDao.findById(bermuda.getIdCor()));

    return bermuda;
}

// Método getAll
std::vector<Bermuda> BermudaService::getAll() {
    std::vector<Bermuda> bermudas = bermudaDao.findAll();

    for (Bermuda& bermuda : bermudas) {
        Produto produto = produtoDao.findById(bermuda.getIdProduto());
        if (produto.getIdProduto() != 0) {
            bermuda.setIdProduto(produto.getIdProduto());
            bermuda.setIdMarca(produto.getIdMarca());
            bermuda.setMarca(marcaDao.findById(bermuda.getIdMarca()));
            bermuda.setIdModelo(produto.getIdModelo());
            bermuda.setModelo(modeloDao.findById(bermuda.getIdModelo()));
            bermuda.setSKU(produto.getSKU());
            bermuda.setFaixaEtaria(produto.getFaixaEtaria());
            bermuda.setIdTamanho(produto.getIdTamanho());
            bermuda.setTamanho(tamanhoDao.findById(bermuda.getIdTamanho()));
            bermuda.setSexo(produto.getSexo());
            bermuda.setIdCor(produto.getIdCor());
            bermuda.setCor(corDao.findById(bermuda.getIdCor()));
        }
    }

    return bermudas;
}

// Método insert
void BermudaService::insert(Bermuda bermuda) {
    Produto produtoSalvo = produtoDao.insert(bermuda);
    bermuda.setIdProduto(produtoSalvo.getIdProduto());
    bermudaDao.insert(bermuda);
}

// Método update
void BermudaService::update(Bermuda bermuda) {
    produtoDao.update(bermuda);
    bermudaDao.update(bermuda);
}

// Método deleteById
void BermudaService::deleteById(int idProduto) {
    bermudaDao.delete(idProduto);
    produtoDao.delete(idProduto);
}
