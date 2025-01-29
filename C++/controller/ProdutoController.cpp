#include "ProdutoController.h"

void ProdutoController::exibirMenu() {
    std::cout << "\nTIPOS DE PRODUTOS:\n";
    std::cout << "1 - BERMUDA\n";
    std::cout << "2 - KIMONO\n";
    std::cout << "3 - FAIXA\n";
    std::cout << "4 - RASH GUARD\n";
    std::cout << "Escolha uma opção: ";
}

void ProdutoController::menu() {
    int opcao;
    bool continuar = true;

    while (continuar) {
        exibirMenu();
        std::cin >> opcao;

        continuar = false;

        switch (opcao) {
            case 1:
                std::cout << "Opção 1 selecionada: BERMUDA.\n";
                //bermudaController.menu();
                break;
            case 2:
                std::cout << "Opção 2 selecionada: KIMONO.\n";
                kimonoController.menu();
                break;
            case 3:
                std::cout << "Opção 3 selecionada: FAIXA.\n";
                break;
            case 4:
                std::cout << "Opção 4 selecionada: RASH GUARD.\n";
                break;
            default:
                std::cout << "Opção inválida. Por favor, tente novamente.\n";
                continuar = true;
                break;
        }
    }
}
