#include <iostream>
#include <stdexcept>
#include <limits>
#include "LoginController.h"

// Classe de exceção personalizada para erros de login
class LoginException : public std::runtime_error {
public:
    explicit LoginException(const std::string& message)
        : std::runtime_error(message) {}
};

void LoginController::fazerLogin() {
    std::string email, senha;
    bool loginSucesso = false;

    while (!loginSucesso) {
        try {
            std::cout << "Email: ";
            if (!(std::cin >> email)) {
                throw LoginException("Erro na leitura do email");
            }

            // Validação básica do email
            if (email.empty()) {
                throw LoginException("Email não pode estar vazio");
            }

            std::cout << "Senha: ";
            if (!(std::cin >> senha)) {
                throw LoginException("Erro na leitura da senha");
            }

            // Validação básica da senha
            if (senha.empty()) {
                throw LoginException("Senha não pode estar vazia");
            }

            // Verificação das credenciais
            if (email == EMAIL_CORRETO && senha == SENHA_CORRETA) {
                std::cout << "Login bem-sucedido!\n\n";
                loginSucesso = true;
            } else {
                throw LoginException("Email ou senha incorretos");
            }
        }
        catch (const LoginException& e) {
            std::cerr << "Erro de login: " << e.what() << "\n\n";
            // Limpar o cin em caso de erro
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::exception& e) {
            std::cerr << "Erro inesperado: " << e.what() << "\n\n";
            // Limpar o cin em caso de erro
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}