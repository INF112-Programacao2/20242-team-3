#ifndef VENDA_H
#define VENDA_H

#include <string>
#include <ctime>       
#include "Cliente.h"
#include "Produto.h"

// Enum para Satisfacao
enum class Satisfacao
{
    MUITO_RUIM,
    RUIM,
    REGULAR,
    BOM,
    MUITO_BOM
};

// Enum para Ajuste
enum class Ajuste
{
    JUSTO,
    LEVEMENTE_JUSTO,
    BOM,
    LEVEMENTE_FOLGADO,
    FOLGADO
};

class Venda
{
private:
    int idVenda;
    std::string cpf;
    Cliente *cliente;
    std::string SKU;
    Produto *produto;
    std::tm dataVenda; // Tipo tm para armazenar data
    Satisfacao satisfacao;
    Ajuste ajuste;

public:
    // Construtor com todos os atributos
    Venda(int idVenda, const std::string &cpf, Cliente *cliente, const std::string &SKU, Produto *produto,
          const std::tm &dataVenda, Satisfacao satisfacao, Ajuste ajuste);

    // Construtor com nenhum atributo (valores padrão)
    Venda();

    // Getters e Setters
    int getIdVenda() const;
    void setIdVenda(int value);

    std::string getCpf() const;
    void setCpf(const std::string &value);

    Cliente *getCliente() const;
    void setCliente(Cliente *value);

    std::string getSKU() const;
    void setSKU(const std::string &value);

    Produto *getProduto() const;
    void setProduto(Produto *value);

    std::tm getDataVenda() const;
    void setDataVenda(const std::tm &value);

    Satisfacao getSatisfacao() const;
    void setSatisfacao(Satisfacao value);

    Ajuste getAjuste() const;
    void setAjuste(Ajuste value);
};

#endif