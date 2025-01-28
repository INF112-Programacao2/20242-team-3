#ifndef COR_H
#define COR_H

#include <string>

class Cor {
private:
    int idCor;
    std::string nome;

public:
    // Construtor com todos os atributos
    Cor(int idCor, const std::string& nome);

    // Construtor com nenhum atributo (valores padrão)
    Cor();

    // Getters e Setters
    int getIdCor() const;
    void setIdCor(int value);

    std::string getNome() const;
    void setNome(const std::string& value);
};

#endif