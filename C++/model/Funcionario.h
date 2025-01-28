#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <ctime>
#include "Pessoa.h" 
#include "util/EncryptionUtil.h"
#include "util/PasswordUtil.h"

class Funcionario : public Pessoa {
private:
    std::string email;
    std::string senha;

public:
    // Construtor com todos os atributos
    Funcionario(int idPessoa, const std::string &nome, const std::tm &nascimento, const std::string &telefone,
                const std::string &cpf, int idade, Sexo sexo, const std::string &email, const std::string &senha);

    // Construtor com nenhum atributo (valores padrão)
    Funcionario();

    // Getters e setters para email e senha
    std::string getEmail() const;
    void setEmail(const std::string &value);

    std::string getSenha() const;
    void setSenha(const std::string &value);

    // Métodos adicionais
    void setEmailEncrypted(const std::string &email);
    std::string getEmailDecrypted() const;

    void setHashedSenha(const std::string &senha);
    bool verificarSenha(const std::string &senha) const;
};

#endif // FUNCIONARIO_H
