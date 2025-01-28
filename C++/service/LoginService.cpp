#include <string>
#include <stdexcept>
#include "FuncionarioDao.h"
#include "PessoaDao.h"
#include "util/EncryptionUtil.h"
#include "model/Funcionario.h"
#include "model/Pessoa.h"

class LoginService {
private:
    FuncionarioDao funcionarioDao;
    PessoaDao pessoaDao;

public:
    // Método para realizar login
    Funcionario fazerLogin(const std::string &email, const std::string &senha) {
        // Busca o funcionário pelo email criptografado
        Funcionario funcionario = funcionarioDao.findByEmail(EncryptionUtil::encrypt(email));

        if (!funcionario.isValid()) {
            throw std::runtime_error("Email não encontrado."); // Email não encontrado
        }

        // Verifica a senha
        if (!funcionario.verificarSenha(senha)) {
            throw std::runtime_error("Senha incorreta."); // Senha incorreta
        }

        Pessoa pessoa = pessoaDao.findById(funcionario.getIdPessoa());

        if (pessoa.isValid()) {
            funcionario.setIdPessoa(pessoa.getIdPessoa());
            funcionario.setNome(pessoa.getNome());
            funcionario.setNascimento(pessoa.getNascimento());
            funcionario.setTelefone(pessoa.getTelefone());
            funcionario.setCpf(pessoa.getCpf());
            funcionario.setIdade(pessoa.getIdade());
            funcionario.setSexo(pessoa.getSexo());
        }

        return funcionario; // Retorna o funcionário se o login for bem-sucedido
    }
};
