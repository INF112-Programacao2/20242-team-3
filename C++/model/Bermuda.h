#ifndef BERMUDA_H
#define BERMUDA_H

#include <string>
#include "Produto.h" 

// Enum para Ajuste
enum class Ajuste {
    ELASTICO,
    BOTAO,
    AMARRACAO
};

// Enum para Comprimento
enum class Comprimento {
    CURTO,
    MEDIO,
    LONGO
};

class Bermuda : public Produto {
private:
    Ajuste ajuste;
    Comprimento comprimento;

public:
    // Construtor com todos os atributos
    Bermuda(int idProduto, Marca marca, Modelo modelo, const std::string& SKU, 
            FaixaEtaria faixaEtaria, Tamanho tamanho, Sexo sexo, Cor cor, 
            Ajuste ajuste, Comprimento comprimento);

    // Construtor com nenhum atributo (valores padrão)
    Bermuda();

    // Getters e Setters
    Ajuste getAjuste() const;
    void setAjuste(Ajuste value);

    Comprimento getComprimento() const;
    void setComprimento(Comprimento value);

    // Coversores para STRING
    void bermudaToString();
    std::string ajusteToString(Ajuste ajuste);
    std::string comprimentoToString(Comprimento comprimento);
};


#endif