#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include "Marca.h"
#include "Modelo.h"
#include "Tamanho.h"
#include "Cor.h"

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
    int idMarca;
    Marca* marca;
    int idModelo;
    Modelo* modelo;
    std::string SKU;
    FaixaEtaria faixaEtaria;
    int idTamanho;
    Tamanho* tamanho;
    Sexo sexo;
    int idCor;
    Cor* cor;

public:
    // Construtor com todos os atributos
    Produto(int idProduto, int idMarca, Marca* marca, int idModelo, Modelo* modelo, 
            const std::string& SKU, FaixaEtaria faixaEtaria, int idTamanho, Tamanho* tamanho, 
            Sexo sexo, int idCor, Cor* cor);

    // Construtor com nenhum atributo (valores padrão)
    Produto();

    // Getters e Setters
    int getIdProduto() const;
    void setIdProduto(int value);

    int getIdMarca() const;
    void setIdMarca(int value);

    Marca* getMarca() const;
    void setMarca(Marca* value);

    int getIdModelo() const;
    void setIdModelo(int value);

    Modelo* getModelo() const;
    void setModelo(Modelo* value);

    std::string getSKU() const;
    void setSKU(const std::string& value);

    FaixaEtaria getFaixaEtaria() const;
    void setFaixaEtaria(FaixaEtaria value);

    int getIdTamanho() const;
    void setIdTamanho(int value);

    Tamanho* getTamanho() const;
    void setTamanho(Tamanho* value);

    Sexo getSexo() const;
    void setSexo(Sexo value);

    int getIdCor() const;
    void setIdCor(int value);

    Cor* getCor() const;
    void setCor(Cor* value);
};

#endif