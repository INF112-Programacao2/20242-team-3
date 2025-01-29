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

std::string Kimono::formaToString(Forma forma) {
    switch (forma) {
        case Forma::TRADICIONAL: return "TRADICIONAL";
        case Forma::SLIM: return "SLIM";
        case Forma::ULTRASLIM: return "ULTRASLIM";
    }
    return "Desconhecido";
}

void Kimono::kimonoToString() {
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
