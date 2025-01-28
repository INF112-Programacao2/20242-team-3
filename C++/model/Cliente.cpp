#include "Cliente.h" // Supondo que a classe Pessoa está em um arquivo separado

// Construtor com todos os atributos
Cliente::Cliente(int idPessoa, const std::string& nome, const std::tm& nascimento, const std::string& telefone, 
        const std::string& cpf, int idade, Sexo sexo, double envergadura, double peso, 
        double altura, double torax, double cintura)
    : Pessoa(idPessoa, nome, nascimento, telefone, cpf, idade, sexo), envergadura(envergadura),
        peso(peso), altura(altura), torax(torax), cintura(cintura) {}

// Construtor com nenhum atributo (valores padrão)
Cliente::Cliente()
    : Pessoa(), envergadura(0.0), peso(0.0), altura(0.0), torax(0.0), cintura(0.0) {}

// Getters e Setters
double Cliente::getEnvergadura() const { return envergadura; }
void Cliente::setEnvergadura(double value) { envergadura = value; }

double Cliente::getPeso() const { return peso; }
void Cliente::setPeso(double value) { peso = value; }

double Cliente::getAltura() const { return altura; }
void Cliente::setAltura(double value) { altura = value; }

double Cliente::getTorax() const { return torax; }
void Cliente::setTorax(double value) { torax = value; }

double Cliente::getCintura() const { return cintura; }
void Cliente::setCintura(double value) { cintura = value; }