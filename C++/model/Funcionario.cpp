#include <string>
#include "Pessoa.cpp" // Supondo que a classe Pessoa está em um arquivo separado
#include "util/EncryptionUtil.cpp"
#include "util/PasswordUtil.cpp"

class Funcionario : public Pessoa{
private:
    std::string email;
    std::string senha;

public:
    // Construtor com todos os atributos
    Funcionario(int idPessoa, const std::string &nome, const std::tm &nascimento, const std::string &telefone,
                const std::string &cpf, int idade, Sexo sexo, const std::string &email, const std::string &senha)
        : Pessoa(idPessoa, nome, nascimento, telefone, cpf, idade, sexo), email(email), senha(senha) {}

    // Construtor com nenhum atributo (valores padrão)
    Funcionario()
        : Pessoa(), email(""), senha("") {}

    // Getters e setters para email e senha
    std::string getEmail() const { return email; }
    void setEmail(const std::string &value) { email = value; }

    std::string getSenha() const { return senha; }
    void setSenha(const std::string &value) { senha = value; }

    // Métodos adicionais
    void setEmailEncrypted(const std::string &email)
    {
        this->email = EncryptionUtil::encrypt(email);
    }

    std::string getEmailDecrypted() const
    {
        return EncryptionUtil::decrypt(this->email);
    }

    void setHashedSenha(const std::string &senha)
    {
        this->senha = PasswordUtil::hashPassword(senha);
    }

    bool verificarSenha(const std::string &senha) const
    {
        return PasswordUtil::checkPassword(senha, this->senha);
    }
};
