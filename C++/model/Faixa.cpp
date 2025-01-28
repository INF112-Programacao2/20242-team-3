#include <string>
#include "Produto.cpp"

// Enum para Espessura
enum class Espessura {
    CLASSICA,
    ROBUSTA
};

class Faixa : public Produto {
private:
    Espessura espessura;

public:
    // Construtor com todos os atributos
    Faixa(int idProduto, int idMarca, Marca* marca, int idModelo, Modelo* modelo, const std::string& SKU, 
          FaixaEtaria faixaEtaria, int idTamanho, Tamanho* tamanho, Sexo sexo, int idCor, Cor* cor, 
          Espessura espessura)
        : Produto(idProduto, idMarca, marca, idModelo, modelo, SKU, faixaEtaria, idTamanho, tamanho, sexo, idCor, cor),
          espessura(espessura) {}

    // Construtor com nenhum atributo (valores padrão)
    Faixa()
        : Produto(), espessura(Espessura::CLASSICA) {}

    // Getter e Setter
    Espessura getEspessura() const { return espessura; }
    void setEspessura(Espessura value) { espessura = value; }
};
