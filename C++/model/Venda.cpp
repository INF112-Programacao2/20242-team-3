#include "Venda.h"

// Construtor com todos os atributos
Venda::Venda(int idVenda, const std::string &cpf, Cliente *cliente, const std::string &SKU, Produto *produto,
        const std::tm &dataVenda, Satisfacao satisfacao, Ajuste ajuste)
    : idVenda(idVenda), cpf(cpf), cliente(cliente), SKU(SKU), produto(produto),
        dataVenda(dataVenda), satisfacao(satisfacao), ajuste(ajuste) {}

// Construtor com nenhum atributo (valores padrão)
Venda::Venda()
    : idVenda(0), cpf(""), cliente(nullptr), SKU(""), produto(nullptr), satisfacao(Satisfacao::REGULAR),
        ajuste(Ajuste::JUSTO) {}

// Getters e Setters
int Venda::getIdVenda() const { return idVenda; }
void Venda::setIdVenda(int value) { idVenda = value; }

std::string Venda::getCpf() const { return cpf; }
void Venda::setCpf(const std::string &value) { cpf = value; }

Cliente* Venda::getCliente() const { return cliente; }
void Venda::setCliente(Cliente *value) { cliente = value; }

std::string Venda::getSKU() const { return SKU; }
void Venda::setSKU(const std::string &value) { SKU = value; }

Produto* Venda::getProduto() const { return produto; }
void Venda::setProduto(Produto *value) { produto = value; }

std::tm Venda::getDataVenda() const { return dataVenda; }
void Venda::setDataVenda(const std::tm &value) { dataVenda = value; }

Satisfacao Venda::getSatisfacao() const { return satisfacao; }
void Venda::setSatisfacao(Satisfacao value) { satisfacao = value; }

Ajuste Venda::getAjuste() const { return ajuste; }
void Venda::setAjuste(Ajuste value) { ajuste = value; }