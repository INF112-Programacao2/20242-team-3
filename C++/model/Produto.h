#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
// #include "Marca.h"
// #include "Modelo.h"
// #include "Tamanho.h"
// #include "Cor.h"

// Definição de enum para Marca
enum class Marca {
   KVRA, VOUK, DUBAI, SUERTE
};

// Definição de enum para Modelo
enum class Modelo {
   COMUM, REFORÇADO
};

// Definição de enum para Tamanho
enum class Tamanho {
   P, M, G,GG, XGG
};

// Definição de enum para Cor
enum class Cor {
    PRETO, BRANCO, AZUL, ROSA, CINZA, VERDE
};

// Definição de enum para Sexo
enum class Sexo {
    MASCULINO,
    FEMININO,
    UNISSEX
};

// Definição de enum para FaixaEtaria
enum class FaixaEtaria {
    ADULTO,
    INFANTIL,
    JUVENIL
};

class Produto {
protected:
    int idProduto;
    Marca marca;
    Modelo modelo;
    std::string SKU;
    FaixaEtaria faixaEtaria;
    Tamanho tamanho;
    Sexo sexo;
    Cor cor;

public:
    // Construtor com todos os atributos
    Produto(int idProduto, Marca marca, Modelo modelo, 
            const std::string& SKU, FaixaEtaria faixaEtaria, Tamanho tamanho, 
            Sexo sexo, Cor cor);

    // Construtor com nenhum atributo (valores padrão)
    Produto();

    // Getters e Setters
    int getIdProduto() const;
    void setIdProduto(int value);

    Marca getMarca() const;
    void setMarca(Marca value);

    Modelo getModelo() const;
    void setModelo(Modelo value);

    std::string getSKU() const;
    void setSKU(const std::string& value);

    FaixaEtaria getFaixaEtaria() const;
    void setFaixaEtaria(FaixaEtaria value);

    Tamanho getTamanho() const;
    void setTamanho(Tamanho value);

    Sexo getSexo() const;
    void setSexo(Sexo value);

    Cor getCor() const;
    void setCor(Cor value);

    // Conversores de ENUM para STRING
    std::string marcaToString(Marca marca);
    std::string modeloToString(Modelo modelo);
    std::string tamanhoToString(Tamanho tamanho);
    std::string sexoToString(Sexo sexo);
    std::string corToString(Cor cor);
    std::string faixaEtariaToString(FaixaEtaria faixa);
};

#endif