#include <iostream>
#include "LoginController.h"

void LoginController::fazerLogin()
{
    std::string email, senha;

    while (true)
    {
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "Senha: ";
        std::cin >> senha;

        if (email == EMAIL_CORRETO && senha == SENHA_CORRETA)
        {
            std::cout << "Login bem-sucedido!\n\n";
            break;
        }
        else
        {
            std::cout << "Email ou senha incorretos. Tente novamente.\n\n";
        }
    }
}