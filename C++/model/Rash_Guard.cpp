#include <string>
#include "Produto.cpp" // Supondo que a classe Produto está em um arquivo separado

class Rash_Guard : public Produto
{
private:
    int fps;

public:
    // Construtor com todos os atributos
    Rash_Guard(int idProduto, int idMarca, Marca *marca, int idModelo, Modelo *modelo, const std::string &SKU,
               FaixaEtaria faixaEtaria, int idTamanho, Tamanho *tamanho, Sexo sexo, int idCor, Cor *cor, int fps)
        : Produto(idProduto, idMarca, marca, idModelo, modelo, SKU, faixaEtaria, idTamanho, tamanho, sexo, idCor, cor), fps(fps) {}

    // Construtor com nenhum atributo (valores padrão)
    Rash_Guard()
        : Produto(), fps(0) {}

    // Getter e Setter para fps
    int getFps() const { return fps; }
    void setFps(int value) { fps = value; }
};
