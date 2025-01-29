#include "BermudaController.h"

void BermudaController::exibirMenu() {
    std::cout << "\n1 - INSERIR BERMUDA\n";
    std::cout << "2 - ATUALIZAR BERMUDA\n";
    std::cout << "3 - LISTAR KIMONOS\n";
    std::cout << "4 - LISTAR KIMONO POR ID\n";
    std::cout << "5 - DELETAR KIMONO\n";
    std::cout << "Escolha uma opção: ";
}

void BermudaController::menu() {
    int opcao;
    bool continuar = true;

    while (continuar) {
        exibirMenu();
        continuar = false;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Opção 1 selecionada: INSERIR BERMUDA.\n";
                inserir();
                break;
            case 2:
                std::cout << "Opção 2 selecionada: ATUALIZAR BERMUDA.\n";
                atualizar();
                break;
            case 3:
                std::cout << "Opção 3 selecionada: LISTAR KIMONOS.\n";
                listarTodos();
                break;
            case 4:
                std::cout << "Opção 4 selecionada: LISTAR KIMONO POR ID.\n";
                listarPorId(); // Apenas um exemplo, ajustar lógica conforme necessário
                break;
            case 5:
                std::cout << "Opção 5 selecionada: DELETAR KIMONO.\n";
                deletar(); // Apenas um exemplo, ajustar lógica conforme necessário
                break;
            default:
                std::cout << "Opção inválida. Por favor, tente novamente.\n";
                continuar = true;
                break;
        }
    }
}

void BermudaController::inserir() {
    std::cout << "Inserindo bermuda.\n";
}

void BermudaController::atualizar() {
    std::cout << "Atualizando bermuda.\n";
}

void BermudaController::listarTodos() {
    std::cout << "Listando todas as bermudas.\n";
}

void BermudaController::listarPorId() {
    int idBermuda = 0;
    std::cout << "Listando a bermuda com id: " << idBermuda << "\n";
}

void BermudaController::deletar() {
    int idBermuda = 0;
    std::cout << "Deletando a bermuda com id: " << idBermuda << "\n";
}
