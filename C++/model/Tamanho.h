#ifndef TAMANHO_H
#define TAMANHO_H

#include <string>

// Enum para TipoProduto
enum class TipoProduto {
    BERMUDA,
    FAIXA,
    KIMONO,
    RASH_GUARD
};

class Tamanho {
private:
    int idTamanho;
    TipoProduto tipoProduto;
    std::string nome;

public:
    // Construtor com todos os atributos
    Tamanho(int idTamanho, TipoProduto tipoProduto, const std::string& nome);

    // Construtor com nenhum atributo (valores padrão)
    Tamanho();

    // Getters e Setters
    int getIdTamanho() const;
    void setIdTamanho(int value);

    TipoProduto getTipoProduto() const;
    void setTipoProduto(TipoProduto value);

    std::string getNome() const;
    void setNome(const std::string& value);
};

#endif  