#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <iostream>
#include <string>
#include "ProdutoController.h"

class MenuController{

    private:
        ProdutoController produtoController;

    public:
    void exibirMenu() {
        std::cout << "\nMENU DE OPÇÕES:\n";
        std::cout << "1 - Gerenciar produto\n";
        std::cout << "2 - Gerenciar cliente\n";
        std::cout << "3 - Realizar venda\n";
        std::cout << "4 - Pesquisar produto\n";
        std::cout << "5 - Sair\n";
        std::cout << "6 - Gerenciar funcionário (exclusivo para o gerente)\n";
        std::cout << "Escolha uma opção: ";
    }

    void menu(){
        int opcao;
        bool continuar = true;

        while (continuar){
            exibirMenu();
            std::cin >> opcao;

            switch (opcao){
            case 1:
                std::cout << "Opção 1 selecionada: Gerenciar produto.\n";
                produtoController.menu();
                break;

            case 2:
                std::cout << "Opção 2 selecionada: Gerenciar cliente.\n";
                break;

            case 3:
                std::cout << "Opção 3 selecionada: Realizar venda.\n";
                break;

            case 4:
                std::cout << "Opção 4 selecionada: Pesquisar produto.\n";
                break;

            case 5:
                std::cout << "Saindo do sistema. Até logo!\n";
                continuar = false;
                break;

            case 6:
                std::cout << "Opção 6 selecionada: Gerenciar funcionário.\n";
                break;

            default:
                std::cout << "Opção inválida. Por favor, tente novamente.\n";
                break;
            }
        }
    }
};


#endif

int main() {
    MenuController menuController;
    
    std::cout << "=== SISTEMA DE TESTE ===\n";
    menuController.menu(); 

    return 0;
}

