#include "Tamanho.h"

// Construtor com todos os atributos
Tamanho::Tamanho(int idTamanho, TipoProduto tipoProduto, const std::string& nome)
    : idTamanho(idTamanho), tipoProduto(tipoProduto), nome(nome) {}

// Construtor com nenhum atributo (valores padrão)
Tamanho::Tamanho()
    : idTamanho(0), tipoProduto(TipoProduto::BERMUDA), nome("") {}

// Getters e Setters
int Tamanho::getIdTamanho() const { return idTamanho; }
void Tamanho::setIdTamanho(int value) { idTamanho = value; }

TipoProduto Tamanho::getTipoProduto() const { return tipoProduto; }
void Tamanho::setTipoProduto(TipoProduto value) { tipoProduto = value; }

std::string Tamanho::getNome() const { return nome; }
void Tamanho::setNome(const std::string& value) { nome = value; }