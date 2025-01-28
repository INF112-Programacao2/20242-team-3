#include "Cor.h"

// Construtor com todos os atributos
Cor::Cor(int idCor, const std::string& nome)
    : idCor(idCor), nome(nome) {}

// Construtor com nenhum atributo (valores padrão)
Cor::Cor()
    : idCor(0), nome("") {}

// Getters e Setters
int Cor::getIdCor() const { return idCor; }
void Cor::setIdCor(int value) { idCor = value; }

std::string Cor::getNome() const { return nome; }
void Cor::setNome(const std::string& value) { nome = value; }