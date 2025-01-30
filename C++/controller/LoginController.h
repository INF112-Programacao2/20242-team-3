#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include <iostream>
#include "../interface/Login.h"

class LoginController : public Login {
private:
    const std::string EMAIL_CORRETO = "usuario@email.com";
    const std::string SENHA_CORRETA = "INF112*#&";

public:
    void fazerLogin() override;
};

#endif // LOGIN_CONTROLLER_H
