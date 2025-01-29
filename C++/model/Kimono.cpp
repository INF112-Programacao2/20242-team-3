#include "Kimono.h"
#include <iostream>
#include <iomanip>

// Construtor com todos os atributos
Kimono::Kimono(int idProduto, Marca marca, Modelo modelo, const std::string& SKU, 
           FaixaEtaria faixaEtaria, Tamanho tamanho, Sexo sexo, Cor cor, 
           double gramaturaTecido, int encolhimento, Forma forma)
    : Produto(idProduto, marca, modelo, SKU, faixaEtaria, tamanho, sexo, cor),
        gramaturaTecido(gramaturaTecido), encolhimento(encolhimento), forma(forma) {}

// Construtor com nenhum atributo (valores padrão)
Kimono::Kimono()
    : Produto(), gramaturaTecido(0.0), encolhimento(0), forma(Forma::TRADICIONAL) {}

// Getters e Setters
double Kimono::getGramaturaTecido() const { return gramaturaTecido; }
void Kimono::setGramaturaTecido(double value) { gramaturaTecido = value; }

int Kimono::getEncolhimento() const { return encolhimento; }
void Kimono::setEncolhimento(int value) { encolhimento = value; }

Forma Kimono::getForma() const { return forma; }
void Kimono::setForma(Forma value) { forma = value; }

std::string Kimono::marcaToString(Marca marca) {
    switch (marca) {
        case Marca::KVRA: return "KVRA";
        case Marca::VOUK: return "VOUK";
        case Marca::DUBAI: return "DUBAI";
        case Marca::SUERTE: return "SUERTE";
    }
    return "Desconhecida";
}

std::string Kimono::modeloToString(Modelo modelo) {
    switch (modelo) {
        case Modelo::COMUM: return "COMUM";
        case Modelo::REFORÇADO: return "REFORÇADO";
    }
    return "Desconhecido";
}

std::string Kimono::tamanhoToString(Tamanho tamanho) {
    switch (tamanho) {
        case Tamanho::P: return "P";
        case Tamanho::M: return "M";
        case Tamanho::G: return "G";
        case Tamanho::GG: return "GG";
        case Tamanho::XGG: return "XGG";
    }
    return "Desconhecido";
}

std::string Kimono::sexoToString(Sexo sexo) {
    switch (sexo) {
        case Sexo::MASCULINO: return "MASCULINO";
        case Sexo::FEMININO: return "FEMININO";
        case Sexo::UNISSEX: return "UNISSEX";
    }
    return "Desconhecido";
}

std::string Kimono::corToString(Cor cor) {
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

std::string Kimono::faixaEtariaToString(FaixaEtaria faixa) {
    switch (faixa) {
        case FaixaEtaria::ADULTO: return "ADULTO";
        case FaixaEtaria::INFANTIL: return "INFANTIL";
        case FaixaEtaria::JUVENIL: return "JUVENIL";
    }
    return "Desconhecido";
}

std::string Kimono::formaToString(Forma forma) {
    switch (forma) {
        case Forma::TRADICIONAL: return "TRADICIONAL";
        case Forma::SLIM: return "SLIM";
        case Forma::ULTRASLIM: return "ULTRASLIM";
    }
    return "Desconhecido";
}

void Kimono::toString() {
    std::cout << std::left
              << std::setw(15) << idProduto
              << std::setw(15) << marcaToString(marca)
              << std::setw(15) << modeloToString(modelo)
              << std::setw(15) << SKU
              << std::setw(15) << faixaEtariaToString(faixaEtaria)
              << std::setw(15) << tamanhoToString(tamanho)
              << std::setw(15) << sexoToString(sexo)
              << std::setw(15) << corToString(cor)
              << std::setw(15) << gramaturaTecido
              << std::setw(15) << encolhimento
              << std::setw(15) << formaToString(forma)
              << std::endl;
}
