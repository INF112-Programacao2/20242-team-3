#include "Modelo.h"

// Construtor com todos os atributos
Modelo::Modelo(int idModelo, int idMarca, const std::string& nome)
    : idModelo(idModelo), idMarca(idMarca), nome(nome) {}

// Construtor com nenhum atributo (valores padrão)
Modelo::Modelo()
    : idModelo(0), idMarca(0), nome("") {}

// Getters e Setters
int Modelo::getIdModelo() const { return idModelo; }
void Modelo::setIdModelo(int value) { idModelo = value; }

int Modelo::getIdMarca() const { return idMarca; }
void Modelo::setIdMarca(int value) { idMarca = value; }

std::string Modelo::getNome() const { return nome; }
void Modelo::setNome(const std::string& value) { nome = value; }