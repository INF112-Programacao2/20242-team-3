#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Pessoa.h" // Supondo que a classe Pessoa está em um arquivo separado

class Cliente : public Pessoa {
private:
    double envergadura;
    double peso;
    double altura;
    double torax;
    double cintura;

public:
    // Construtor com todos os atributos
    Cliente(int idPessoa, const std::string& nome, const std::tm& nascimento, const std::string& telefone, 
            const std::string& cpf, int idade, Sexo sexo, double envergadura, double peso, 
            double altura, double torax, double cintura);

    // Construtor com nenhum atributo (valores padrão)
    Cliente();

    // Getters e Setters
    double getEnvergadura() const;
    void setEnvergadura(double value);

    double getPeso() const;
    void setPeso(double value);

    double getAltura() const;
    void setAltura(double value);

    double getTorax() const;
    void setTorax(double value);

    double getCintura() const;
    void setCintura(double value);
};

#endif