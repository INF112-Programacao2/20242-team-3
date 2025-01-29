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

// Conversores de ENUM para STRING
std::string Produto::marcaToString(Marca marca) {
    switch (marca) {
        case Marca::KVRA: return "KVRA";
        case Marca::VOUK: return "VOUK";
        case Marca::DUBAI: return "DUBAI";
        case Marca::SUERTE: return "SUERTE";
    }
    return "Desconhecida";
}

std::string Produto::modeloToString(Modelo modelo) {
    switch (modelo) {
        case Modelo::COMUM: return "COMUM";
        case Modelo::REFORÇADO: return "REFORÇADO";
    }
    return "Desconhecido";
}

std::string Produto::tamanhoToString(Tamanho tamanho) {
    switch (tamanho) {
        case Tamanho::P: return "P";
        case Tamanho::M: return "M";
        case Tamanho::G: return "G";
        case Tamanho::GG: return "GG";
        case Tamanho::XGG: return "XGG";
    }
    return "Desconhecido";
}

std::string Produto::sexoToString(Sexo sexo) {
    switch (sexo) {
        case Sexo::MASCULINO: return "MASCULINO";
        case Sexo::FEMININO: return "FEMININO";
        case Sexo::UNISSEX: return "UNISSEX";
    }
    return "Desconhecido";
}

std::string Produto::corToString(Cor cor) {
    switch (cor) {
        case Cor::PRETO: return "PRETO";
        case Cor::BRANCO: return "BRANCO";
        case Cor::AZUL: return "AZUL";
        case Cor::ROSA: return "ROSA";
        case Cor::CINZA: return "CINZA";
        case Cor::VERDE: return "VERDE";
    }
    return "Desconhecido";
}

std::string Produto::faixaEtariaToString(FaixaEtaria faixa) {
    switch (faixa) {
        case FaixaEtaria::ADULTO: return "ADULTO";
        case FaixaEtaria::INFANTIL: return "INFANTIL";
        case FaixaEtaria::JUVENIL: return "JUVENIL";
    }
    return "Desconhecido";
}
