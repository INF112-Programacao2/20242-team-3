class Pesquisa {
private:
    double peso;
    double variacaoPeso;
    double altura;
    double variacaoAltura;

public:
    // Construtor com todos os atributos
    Pesquisa(double peso, double variacaoPeso, double altura, double variacaoAltura)
        : peso(peso), variacaoPeso(variacaoPeso), altura(altura), variacaoAltura(variacaoAltura) {}

    // Construtor com nenhum atributo (valores padrão)
    Pesquisa()
        : peso(0.0), variacaoPeso(0.0), altura(0.0), variacaoAltura(0.0) {}

    // Getters e Setters
    double getPeso() const { return peso; }
    void setPeso(double value) { peso = value; }

    double getVariacaoPeso() const { return variacaoPeso; }
    void setVariacaoPeso(double value) { variacaoPeso = value; }

    double getAltura() const { return altura; }
    void setAltura(double value) { altura = value; }

    double getVariacaoAltura() const { return variacaoAltura; }
    void setVariacaoAltura(double value) { variacaoAltura = value; }
};
