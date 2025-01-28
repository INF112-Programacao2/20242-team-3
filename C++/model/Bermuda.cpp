#include "Bermuda.h"

// Construtor com todos os atributos
Bermuda::Bermuda(int idProduto, int idMarca, Marca* marca, int idModelo, Modelo* modelo, const std::string& SKU, 
        FaixaEtaria faixaEtaria, int idTamanho, Tamanho* tamanho, Sexo sexo, int idCor, Cor* cor, 
        Ajuste ajuste, Comprimento comprimento)
    : Produto(idProduto, idMarca, marca, idModelo, modelo, SKU, faixaEtaria, idTamanho, tamanho, sexo, idCor, cor),
        ajuste(ajuste), comprimento(comprimento) {}

// Construtor com nenhum atributo (valores padrão)
Bermuda::Bermuda()
    : Produto(), ajuste(Ajuste::ELASTICO), comprimento(Comprimento::CURTO) {}

// Getters e Setters
Ajuste Bermuda::getAjuste() const { return ajuste; }
void Bermuda::setAjuste(Ajuste value) { ajuste = value; }

Comprimento Bermuda::getComprimento() const { return comprimento; }
void Bermuda::setComprimento(Comprimento value) { comprimento = value; }
