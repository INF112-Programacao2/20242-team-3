#include <string>
#include <ctime>

// Enum para Sexo
enum class Sexo {
    MASCULINO,
    FEMININO
};

class Pessoa {
private:
    int idPessoa;
    std::string nome;
    std::tm nascimento; // Representação de data (substituto para Date em C++)
    std::string telefone;
    std::string cpf;
    int idade;
    Sexo sexo;

public:
    // Construtor com todos os atributos
    Pessoa(int idPessoa, const std::string& nome, const std::tm& nascimento, const std::string& telefone, 
           const std::string& cpf, int idade, Sexo sexo);

    // Construtor com nenhum atributo (valores padrão)
    Pessoa();

    // Getters e Setters
    int getIdPessoa() const;
    void setIdPessoa(int value);

    std::string getNome() const;
    void setNome(const std::string& value);

    std::tm getNascimento() const;
    void setNascimento(const std::tm& value);

    std::string getTelefone() const;
    void setTelefone(const std::string& value);

    std::string getCpf() const;
    void setCpf(const std::string& value);

    int getIdade() const;
    void setIdade(int value);

    Sexo getSexo() const;
    void setSexo(Sexo value);
};
