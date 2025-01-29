#include "Produto.h"

// Construtor com todos os atributos
Produto::Produto(int idProduto, Marca marca, Modelo modelo, 
        const std::string& SKU, FaixaEtaria faixaEtaria, Tamanho tamanho, 
        Sexo sexo, Cor cor) 
    : idProduto(idProduto), marca(marca), modelo(modelo), SKU(SKU),
      faixaEtaria(faixaEtaria), tamanho(tamanho), sexo(sexo),cor(cor) {}

// Construtor com nenhum atributo (valores padrão)
Produto::Produto()
    : idProduto(0), marca(Marca::DUBAI), modelo(Modelo::COMUM), 
        SKU(""), faixaEtaria(FaixaEtaria::ADULTO), tamanho(Tamanho::G), 
        sexo(Sexo::UNISSEX), cor(Cor::AZUL) {}

// Getters e Setters
int Produto::getIdProduto() const { return idProduto; }
void Produto::setIdProduto(int value) { idProduto = value; }


Marca Produto::getMarca() const { return marca; }
void Produto::setMarca(Marca value) { marca = value; }

Modelo Produto::getModelo() const { return modelo; }
void Produto::setModelo(Modelo value) { modelo = value; }

std::string Produto::getSKU() const { return SKU; }
void Produto::setSKU(const std::string& value) { SKU = value; }

FaixaEtaria Produto::getFaixaEtaria() const { return faixaEtaria; }
void Produto::setFaixaEtaria(FaixaEtaria value) { faixaEtaria = value; }

Tamanho Produto::getTamanho() const { return tamanho; }
void Produto::setTamanho(Tamanho value) { tamanho = value; }

Sexo Produto::getSexo() const { return sexo; }
void Produto::setSexo(Sexo value) { sexo = value; }

Cor Produto::getCor() const { return cor; }
void Produto::setCor(Cor value) { cor = value; }
