#ifndef RASH_GUARD_H
#define RASH_GUARD_H

#include <string>
#include "Produto.h" // Certifique-se de que o caminho para "Produto.h" está correto

class Rash_Guard : public Produto
{
private:
    int fps; // Fator de proteção solar

public:
    // Construtor com todos os atributos
    Rash_Guard(int idProduto, int idMarca, Marca *marca, int idModelo, Modelo *modelo, const std::string &SKU,
               FaixaEtaria faixaEtaria, int idTamanho, Tamanho *tamanho, Sexo sexo, int idCor, Cor *cor, int fps);

    // Construtor com valores padrão
    Rash_Guard();

    // Getter para fps
    int getFps() const;

    // Setter para fps
    void setFps(int value);
};

#endif // RASH_GUARD_H
