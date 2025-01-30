#include "MenuController.h"
#include <limits>
#include <stdexcept>

class MenuException : public std::runtime_error {
public:
    MenuException(const std::string& message) : std::runtime_error(message) {}
};

void MenuController::exibirMenu() {
    std::cout << "\nMENU DE OPÇÕES:\n";
    std::cout << "1 - Gerenciar kimonos\n";
    std::cout << "2 - Gerenciar bermudas\n";
    std::cout << "3 - Sair\n";
    std::cout << "Escolha uma opção: ";
}

void MenuController::menu() {
    int opcao;
    bool continuar = true;
    
    while (continuar) {
        try {
            exibirMenu();
            
            if (!(std::cin >> opcao)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta a entrada inválida
                throw MenuException("Entrada inválida. Por favor, digite um número entre 1 e 3.");
            }
            
            if (opcao < 1 || opcao > 3) {
                throw MenuException("Opção inválida. Escolha uma opção entre 1 e 3.");
            }
            
            switch (opcao) {
                case 1:
                    try {
                        std::cout << "Opção 1 selecionada: Gerenciar kimonos.\n";
                        kimonoController.menu();
                    } catch (const std::exception& e) {
                        throw MenuException("Erro ao gerenciar kimonos: " + std::string(e.what()));
                    }
                    break;
                    
                case 2:
                    try {
                        std::cout << "Opção 2 selecionada: Gerenciar bermudas.\n";
                        bermudaController.menu();
                    } catch (const std::exception& e) {
                        throw MenuException("Erro ao gerenciar bermudas: " + std::string(e.what()));
                    }
                    break;
                    
                case 3:
                    std::cout << "Saindo do sistema. Até logo!\n";
                    continuar = false;
                    break;
            }
            
        } catch (const MenuException& e) {
            std::cerr << "\nERRO: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\nERRO INESPERADO: " << e.what() << std::endl;
        }
    }
}