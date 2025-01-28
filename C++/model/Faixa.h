#ifndef FAIXA_H
#define FAIXA_H

#include <string>
#include "Produto.h" // Certifique-se de que o caminho para "Produto.h" está correto

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
          Espessura espessura);

    // Construtor com valores padrão
    Faixa();

    // Getter e Setter
    Espessura getEspessura() const;
    void setEspessura(Espessura value);
};

#endif // FAIXA_H
