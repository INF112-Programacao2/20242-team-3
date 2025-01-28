#include "Pessoa.h"

Pessoa::Pessoa(int idPessoa, const std::string& nome, const std::tm& nascimento, const std::string& telefone, 
        const std::string& cpf, int idade, Sexo sexo)
    : idPessoa(idPessoa), nome(nome), nascimento(nascimento), telefone(telefone), cpf(cpf), idade(idade), sexo(sexo) {}

// Construtor com nenhum atributo (valores padrão)
Pessoa::Pessoa()
    : idPessoa(0), nome(""), telefone(""), cpf(""), idade(0), sexo(Sexo::MASCULINO) {
    std::tm defaultNascimento = {};
    defaultNascimento.tm_year = 0;
    defaultNascimento.tm_mon = 0;
    defaultNascimento.tm_mday = 0;
    nascimento = defaultNascimento;
}

// Getters e Setters
int Pessoa::getIdPessoa() const { return idPessoa; }
void Pessoa::setIdPessoa(int value) { idPessoa = value; }

std::string Pessoa::getNome() const { return nome; }
void Pessoa::setNome(const std::string& value) { nome = value; }

std::tm Pessoa::getNascimento() const { return nascimento; }
void Pessoa::setNascimento(const std::tm& value) { nascimento = value; }

std::string Pessoa::getTelefone() const { return telefone; }
void Pessoa::setTelefone(const std::string& value) { telefone = value; }

std::string Pessoa::getCpf() const { return cpf; }
void Pessoa::setCpf(const std::string& value) { cpf = value; }

int Pessoa::getIdade() const { return idade; }
void Pessoa::setIdade(int value) { idade = value; }

Sexo Pessoa::getSexo() const { return sexo; }
void Pessoa::setSexo(Sexo value) { sexo = value; }