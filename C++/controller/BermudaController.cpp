#include "BermudaController.h"
#include <iomanip>

void BermudaController::exibirMenu()
{
    std::cout << "\n1 - INSERIR BERMUDA\n";
    std::cout << "2 - ATUALIZAR BERMUDA\n";
    std::cout << "3 - LISTAR BERMUDAS\n";
    std::cout << "4 - LISTAR BERMUDA POR ID\n";
    std::cout << "5 - DELETAR BERMUDA\n";
    std::cout << "Escolha uma opção: ";
}

void BermudaController::menu()
{
    int opcao;
    bool continuar = true;

    while (continuar)
    {
        exibirMenu();
        continuar = false;
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            std::cout << "Opção 1 selecionada: INSERIR Bermuda.\n";
            inserir();
            break;
        case 2:
            std::cout << "Opção 2 selecionada: ATUALIZAR Bermuda.\n";
            atualizar();
            break;
        case 3:
            std::cout << "Opção 3 selecionada: LISTAR BERMUDAS.\n";
            listarTodos();
            break;
        case 4:
            std::cout << "Opção 4 selecionada: LISTAR BERMUDA POR ID.\n";
            listarPorId();
            break;
        case 5:
            std::cout << "Opção 5 selecionada: DELETAR BERMUDA.\n";
            deletar();
            break;
        default:
            std::cout << "Opção inválida. Por favor, tente novamente.\n";
            continuar = true;
            break;
        }
    }
}

void BermudaController::inserir()
{
    Bermuda bermuda;

    int intInput;
    double doubleInput;
    std::string SKU;

    do
    {
        std::cout << "SKU: ";
        std::cin >> SKU;

        if (SKU.empty())
        {
            std::cout << "Erro: A string não pode estar vazia.\n";
        }
        else if (SKU.length() > 30)
        {
            std::cout << "Erro: A string deve ter no máximo 30 caracteres.\n";
        }

    } while (SKU.empty() || SKU.length() > 30);

    bermuda.setSKU(SKU);

    do
    {
        std::cout << "Marca (0-KVRA, 1-VOUK, 2-DUBAI, 3-SUERTE): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 3)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 3);

    Marca marca = static_cast<Marca>(intInput);
    bermuda.setMarca(marca);

    do
    {
        std::cout << "Modelo (0-COMUM, 1-REFORÇADO): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 1)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 1);

    Modelo modelo = static_cast<Modelo>(intInput);
    bermuda.setModelo(modelo);

    do
    {
        std::cout << "Faixa Etária (0-ADULTO, 1-INFANTIL, 2-JUVENIL): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 2)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 2);

    FaixaEtaria faixaEtaria = static_cast<FaixaEtaria>(intInput);
    bermuda.setFaixaEtaria(faixaEtaria);

    do
    {
        std::cout << "Tamanho (0-P, 1-M, 2-G, 3-GG, 4-XGG): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 4)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 4);

    Tamanho tamanho = static_cast<Tamanho>(intInput);
    bermuda.setTamanho(tamanho);

    do
    {
        std::cout << "Sexo (0-MASCULINO, 1-FEMININO, 2-UNISSEX): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 2)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 2);

    Sexo sexo = static_cast<Sexo>(intInput);
    bermuda.setSexo(sexo);

    do
    {
        std::cout << "Cor (0-PRETO, 1-BRANCO, 2-AZUL, 3-ROSA, 4-CINZA, 5-VERDE): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 5)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 5);

    Cor cor = static_cast<Cor>(intInput);
    bermuda.setCor(cor);

    do
    {
        std::cout << "Ajuste (0-ELASTICO, 1-BOTAO, 2-AMARRACAO): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 2)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 2);

    Ajuste ajuste = static_cast<Ajuste>(intInput);
    bermuda.setAjuste(ajuste);

    do
    {
        std::cout << "Comprimento (0-CURTO, 1-MEDIO, 2-LONGO): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 2)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 2);

    Comprimento comprimento = static_cast<Comprimento>(intInput);
    bermuda.setComprimento(comprimento);

    std::cout << "Inserindo bermuda.\n";

    BermudaDao bermudaDao("NovoBanco.db");
    bermudaDao.insert(bermuda);

    std::cout << "Bermuda inserida com sucesso.\n";
}

void BermudaController::atualizar()
{
    std::cout << "Atualizando bermuda.\n";
}

void BermudaController::listarTodos()
{
    BermudaDao bermudaDao("NovoBanco.db");
    std::vector<Bermuda> listBermuda = bermudaDao.findAll();

    std::cout << std::left
              << std::setw(15) << "ID Produto"
              << std::setw(15) << "Marca"
              << std::setw(15) << "Modelo"
              << std::setw(15) << "SKU"
              << std::setw(15) << "Faixa Etária"
              << std::setw(15) << "Tamanho"
              << std::setw(15) << "Sexo"
              << std::setw(15) << "Cor"
              << std::setw(15) << "Ajuste"
              << std::setw(15) << "Comprimento" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    for (Bermuda &bermuda : listBermuda)
    {
        bermuda.bermudaToString();
    }
}

void BermudaController::listarPorId()
{
    int idProduto;

    std::cout << "Insira o id do seu bermuda: ";
    std::cin >> idProduto;

    BermudaDao bermudaDao("NovoBanco.db");
    Bermuda bermuda = bermudaDao.findById(idProduto);

    std::cout << std::left
              << std::setw(15) << "ID Produto"
              << std::setw(15) << "Marca"
              << std::setw(15) << "Modelo"
              << std::setw(15) << "SKU"
              << std::setw(15) << "Faixa Etária"
              << std::setw(15) << "Tamanho"
              << std::setw(15) << "Sexo"
              << std::setw(15) << "Cor"
              << std::setw(15) << "Ajuste"
              << std::setw(15) << "Comprimento" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    bermuda.bermudaToString();
}

void BermudaController::deletar()
{
    listarTodos();
    int idProduto;

    std::cout << "Insira o id do bermuda a ser deletado: ";
    std::cin >> idProduto;

    BermudaDao bermudaDao("NovoBanco.db");
    bermudaDao.deleteById(idProduto);

    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    listarTodos();
    std::cout << "\n\n EXCLUSÃO REALIZADA COM SUCESSO.";
}
