#ifndef KIMONO_H
#define KIMONO_H

#include <string>
#include "Produto.h" // Certifique-se de que o caminho para "Produto.h" está correto
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
    Kimono(int idProduto, int idMarca, Marca* marca, int idModelo, Modelo* modelo, const std::string& SKU, 
           FaixaEtaria faixaEtaria, int idTamanho, Tamanho* tamanho, Sexo sexo, int idCor, Cor* cor, 
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

#endif // KIMONO_H
