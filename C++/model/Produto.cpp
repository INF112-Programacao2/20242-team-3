#include "Produto.h"

// Construtor com todos os atributos
Produto::Produto(int idProduto, int idMarca, Marca* marca, int idModelo, Modelo* modelo, 
        const std::string& SKU, FaixaEtaria faixaEtaria, int idTamanho, Tamanho* tamanho, 
        Sexo sexo, int idCor, Cor* cor) 
    : idProduto(idProduto), idMarca(idMarca), marca(marca), idModelo(idModelo), modelo(modelo), 
        SKU(SKU), faixaEtaria(faixaEtaria), idTamanho(idTamanho), tamanho(tamanho), sexo(sexo), 
        idCor(idCor), cor(cor) {}

// Construtor com nenhum atributo (valores padrão)
Produto::Produto()
    : idProduto(0), idMarca(0), marca(nullptr), idModelo(0), modelo(nullptr), 
        SKU(""), faixaEtaria(FaixaEtaria::ADULTO), idTamanho(0), tamanho(nullptr), 
        sexo(Sexo::UNISSEX), idCor(0), cor(nullptr) {}

// Getters e Setters
int Produto::getIdProduto() const { return idProduto; }
void Produto::setIdProduto(int value) { idProduto = value; }

int Produto::getIdMarca() const { return idMarca; }
void Produto::setIdMarca(int value) { idMarca = value; }

Marca* Produto::getMarca() const { return marca; }
void Produto::setMarca(Marca* value) { marca = value; }

int Produto::getIdModelo() const { return idModelo; }
void Produto::setIdModelo(int value) { idModelo = value; }

Modelo* Produto::getModelo() const { return modelo; }
void Produto::setModelo(Modelo* value) { modelo = value; }

std::string Produto::getSKU() const { return SKU; }
void Produto::setSKU(const std::string& value) { SKU = value; }

FaixaEtaria Produto::getFaixaEtaria() const { return faixaEtaria; }
void Produto::setFaixaEtaria(FaixaEtaria value) { faixaEtaria = value; }

int Produto::getIdTamanho() const { return idTamanho; }
void Produto::setIdTamanho(int value) { idTamanho = value; }

Tamanho* Produto::getTamanho() const { return tamanho; }
void Produto::setTamanho(Tamanho* value) { tamanho = value; }

Sexo Produto::getSexo() const { return sexo; }
void Produto::setSexo(Sexo value) { sexo = value; }

int Produto::getIdCor() const { return idCor; }
void Produto::setIdCor(int value) { idCor = value; }

Cor* Produto::getCor() const { return cor; }
void Produto::setCor(Cor* value) { cor = value; }
