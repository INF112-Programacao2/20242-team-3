#include "Kimono.h"

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
