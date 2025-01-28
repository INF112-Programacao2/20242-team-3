#include "Marca.h"

// Construtor com todos os atributos
Marca::Marca(int idMarca, const std::string& nome)
    : idMarca(idMarca), nome(nome) {}

// Construtor com nenhum atributo (valores padrão)
Marca::Marca()
    : idMarca(0), nome("") {}

// Getters e Setters
int Marca::getIdMarca() const { return idMarca; }
void Marca::setIdMarca(int value) { idMarca = value; }

std::string Marca::getNome() const { return nome; }
void Marca::setNome(const std::string& value) { nome = value; }