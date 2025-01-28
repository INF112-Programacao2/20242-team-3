#include <string>
#include "Produto.cpp" // Supondo que a classe Produto está em um arquivo separado

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
           double gramaturaTecido, int encolhimento, Forma forma)
        : Produto(idProduto, idMarca, marca, idModelo, modelo, SKU, faixaEtaria, idTamanho, tamanho, sexo, idCor, cor),
          gramaturaTecido(gramaturaTecido), encolhimento(encolhimento), forma(forma) {}

    // Construtor com nenhum atributo (valores padrão)
    Kimono()
        : Produto(), gramaturaTecido(0.0), encolhimento(0), forma(Forma::TRADICIONAL) {}

    // Getters e Setters
    double getGramaturaTecido() const { return gramaturaTecido; }
    void setGramaturaTecido(double value) { gramaturaTecido = value; }

    int getEncolhimento() const { return encolhimento; }
    void setEncolhimento(int value) { encolhimento = value; }

    Forma getForma() const { return forma; }
    void setForma(Forma value) { forma = value; }
};
