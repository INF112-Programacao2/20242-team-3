#ifndef MODELO_H
#define MODELO_H

#include <string>

class Modelo {
private:
    int idModelo;
    int idMarca;
    std::string nome;

public:
    // Construtor com todos os atributos
    Modelo(int idModelo, int idMarca, const std::string& nome);

    // Construtor com nenhum atributo (valores padrão)
    Modelo();

    // Getters e Setters
    int getIdModelo() const;
    void setIdModelo(int value);

    int getIdMarca() const;
    void setIdMarca(int value);

    std::string getNome() const;
    void setNome(const std::string& value);
};

#endif