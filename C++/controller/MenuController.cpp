#include "MenuController.h"

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
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            std::cout << "Opção 1 selecionada: Gerenciar kimonos.\n";
            kimonoController.menu();
            break;

        case 2:
            std::cout << "Opção 2 selecionada: Gerenciar bermudas.\n";
            bermudaController.menu();
            break;

        case 3:
            std::cout << "Saindo do sistema. Até logo!\n";
            continuar = false;
            break;

        default:
            std::cout << "Opção inválida. Por favor, tente novamente.\n";
            break;
        }
    }
}
