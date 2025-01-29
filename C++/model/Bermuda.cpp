#include "Bermuda.h"
#include <iostream>
#include <iomanip>

// Construtor com todos os atributos
Bermuda::Bermuda(int idProduto, Marca marca, Modelo modelo, const std::string& SKU, 
            FaixaEtaria faixaEtaria, Tamanho tamanho, Sexo sexo, Cor cor, 
            Ajuste ajuste, Comprimento comprimento)
    : Produto(idProduto, marca, modelo, SKU, faixaEtaria, tamanho, sexo, cor),
        ajuste(ajuste), comprimento(comprimento) {}

// Construtor com nenhum atributo (valores padrão)
Bermuda::Bermuda()
    : Produto(), ajuste(Ajuste::ELASTICO), comprimento(Comprimento::CURTO) {}

// Getters e Setters
Ajuste Bermuda::getAjuste() const { return ajuste; }
void Bermuda::setAjuste(Ajuste value) { ajuste = value; }

Comprimento Bermuda::getComprimento() const { return comprimento; }
void Bermuda::setComprimento(Comprimento value) { comprimento = value; }

// Conversores para STRING
std::string Bermuda::ajusteToString(Ajuste ajuste) {
    switch (ajuste) {
        case Ajuste::ELASTICO: return "ELASTICO";
        case Ajuste::BOTAO: return "BOTAO";
        case Ajuste::AMARRACAO: return "AMARRACAO";
    }
    return "Desconhecido";
}

std::string Bermuda::comprimentoToString(Comprimento comprimento) {
    switch (comprimento) {
        case Comprimento::CURTO: return "CURTO";
        case Comprimento::MEDIO: return "MEDIO";
        case Comprimento::LONGO: return "LONGO";
    }
    return "Desconhecido";
}

void Bermuda::bermudaToString() {
    std::cout << std::left
              << std::setw(15) << idProduto
              << std::setw(15) << marcaToString(marca)
              << std::setw(15) << modeloToString(modelo)
              << std::setw(15) << SKU
              << std::setw(15) << faixaEtariaToString(faixaEtaria)
              << std::setw(15) << tamanhoToString(tamanho)
              << std::setw(15) << sexoToString(sexo)
              << std::setw(15) << corToString(cor)
              << std::setw(15) << ajusteToString(ajuste)
              << std::setw(15) << comprimentoToString(comprimento)
              << std::endl;
}