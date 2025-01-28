#ifndef BERMUDASERVICE_H
#define BERMUDASERVICE_H

#include <vector>
#include "Bermuda.h"
#include "Produto.h"
#include "MarcaDao.h"
#include "ModeloDao.h"
#include "TamanhoDao.h"
#include "CorDao.h"
#include "ProdutoDao.h"

class BermudaService {
private:
    BermudaDao bermudaDao;
    ProdutoDao produtoDao;
    MarcaDao marcaDao;
    ModeloDao modeloDao;
    TamanhoDao tamanhoDao;
    CorDao corDao;

public:
    // Construtor
    BermudaService(BermudaDao bermudaDao, ProdutoDao produtoDao, MarcaDao marcaDao,
                   ModeloDao modeloDao, TamanhoDao tamanhoDao, CorDao corDao);

    // Métodos
    Bermuda getById(int idProduto);
    std::vector<Bermuda> getAll();
    void insert(Bermuda bermuda);
    void update(Bermuda bermuda);
    void deleteById(int idProduto);
};

#endif // BERMUDASERVICE_H
