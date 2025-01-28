#ifndef MARCA_H
#define MARCA_H

#include <string>

class Marca {
private:
    int idMarca;
    std::string nome;

public:
    // Construtor com todos os atributos
    Marca(int idMarca, const std::string& nome);

    // Construtor com nenhum atributo (valores padrão)
    Marca();

    // Getters e Setters
    int getIdMarca() const;
    void setIdMarca(int value);

    std::string getNome() const;
    void setNome(const std::string& value);
};

#endif