#ifndef PESQUISA_H
#define PESQUISA_H

class Pesquisa {
private:
    double peso;
    double variacaoPeso;
    double altura;
    double variacaoAltura;

public:
    // Construtor com todos os atributos
    Pesquisa(double peso, double variacaoPeso, double altura, double variacaoAltura);

    // Construtor com valores padrão
    Pesquisa();

    // Getters e Setters
    double getPeso() const;
    void setPeso(double value);

    double getVariacaoPeso() const;
    void setVariacaoPeso(double value);

    double getAltura() const;
    void setAltura(double value);

    double getVariacaoAltura() const;
    void setVariacaoAltura(double value);
};

#endif // PESQUISA_H
