#ifndef LOGIN_SERVICE_H
#define LOGIN_SERVICE_H

#include <string>
#include "FuncionarioDao.h"
#include "PessoaDao.h"
#include "Funcionario.h"
#include "Pessoa.h"
#include "EncryptionUtil.h"

class LoginService {
private:
    FuncionarioDao funcionarioDao;
    PessoaDao pessoaDao;

public:
    // Construtor padrão
    LoginService() = default;

    // Método para realizar login
    Funcionario fazerLogin(const std::string &email, const std::string &senha);
};

#endif // LOGIN_SERVICE_H
