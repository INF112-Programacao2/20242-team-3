#ifndef KIMONO_H
#define KIMONO_H

#include <string>
#include "Produto.h" 

// Enum para Forma
enum class Forma {
    TRADICIONAL,
    SLIM,
    ULTRASLIM
};

class Kimono : public Produto {
private:
    double gramaturaTecido;
    int encolhimento;
    Forma forma;

public:
    // Construtor com todos os atributos
    Kimono(int idProduto, Marca marca, Modelo modelo, const std::string& SKU, 
           FaixaEtaria faixaEtaria, Tamanho tamanho, Sexo sexo, Cor cor, 
           double gramaturaTecido, int encolhimento, Forma forma);

    // Construtor com valores padrão
    Kimono();

    // Getters e Setters
    double getGramaturaTecido() const;
    void setGramaturaTecido(double value);

    int getEncolhimento() const;
    void setEncolhimento(int value);

    Forma getForma() const;
    void setForma(Forma value);
};

#endif
