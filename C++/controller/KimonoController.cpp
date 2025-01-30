#include "KimonoController.h"
#include <iomanip>

void KimonoController::exibirMenu(){
    std::cout << "\n1 - INSERIR KIMONO\n";
    std::cout << "2 - ATUALIZAR KIMONO\n";
    std::cout << "3 - LISTAR KIMONOS\n";
    std::cout << "4 - LISTAR KIMONO POR ID\n";
    std::cout << "5 - DELETAR KIMONO\n";
    std::cout << "Escolha uma opção: ";
}

void KimonoController::menu()
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
            std::cout << "Opção 1 selecionada: INSERIR Kimono.\n";
            inserir();
            break;
        case 2:
            std::cout << "Opção 2 selecionada: ATUALIZAR Kimono.\n";
            atualizar();
            break;
        case 3:
            std::cout << "Opção 3 selecionada: LISTAR KIMONOS.\n";
            listarTodos();
            break;
        case 4:
            std::cout << "Opção 4 selecionada: LISTAR KIMONO POR ID.\n";
            listarPorId();
            break;
        case 5:
            std::cout << "Opção 5 selecionada: DELETAR KIMONO.\n";
            deletar();
            break;
        default:
            std::cout << "Opção inválida. Por favor, tente novamente.\n";
            continuar = true;
            break;
        }
    }
}

void KimonoController::inserir()
{
    Kimono kimono;

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

    kimono.setSKU(SKU);

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
    kimono.setMarca(marca);

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
    kimono.setModelo(modelo);

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
    kimono.setFaixaEtaria(faixaEtaria);

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
    kimono.setTamanho(tamanho);

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
    kimono.setSexo(sexo);

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
    kimono.setCor(cor);

    do
    {
        std::cout << "Gramatura do Tecido (g/m²): ";
        std::cin >> doubleInput;

        if (doubleInput <= 0)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (doubleInput <= 0);

    kimono.setGramaturaTecido(doubleInput);

    do
    {
        std::cout << "Encolhimento (%): ";
        std::cin >> doubleInput;

        if (doubleInput < 0 || doubleInput > 100)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (doubleInput < 0 || doubleInput > 100);
    kimono.setEncolhimento(doubleInput);

    do 
    {
        std::cout << "Forma (0-TRADICIONAL, 1-SLIM, 2-ULTRASLIM): ";
        std::cin >> intInput;

        if (intInput < 0 || intInput > 2)
        {
            std::cout << "OPÇÃO INVÁLIDA.\n";
        }

    } while (intInput < 0 || intInput > 2);

    Forma forma = static_cast<Forma>(intInput);
    kimono.setForma(forma);

    std::cout << "Inserindo kimono.\n";

    KimonoDao kimonoDao("NovoBanco.db");
    kimonoDao.insert(kimono);

    std::cout << "Kimono inserido com sucesso.\n";
}

void KimonoController::atualizar()
{
    std::cout << "Atualizando kimono.\n";
}

void KimonoController::listarTodos()
{
    KimonoDao kimonoDao("NovoBanco.db");
    std::vector<Kimono> listKimono = kimonoDao.findAll();

    std::cout << std::left
              << std::setw(15) << "ID Produto"
              << std::setw(15) << "Marca"
              << std::setw(15) << "Modelo"
              << std::setw(15) << "SKU"
              << std::setw(15) << "Faixa Etária"
              << std::setw(15) << "Tamanho"
              << std::setw(15) << "Sexo"
              << std::setw(15) << "Cor"
              << std::setw(15) << "Gramatura"
              << std::setw(15) << "Encolhimento"
              << std::setw(15) << "Forma" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    for (Kimono &kimono : listKimono)
    {
        kimono.kimonoToString();
    }
}

void KimonoController::listarPorId()
{
    int idProduto;

    std::cout << "Insira o id do seu kimono: ";
    std::cin >> idProduto;

    KimonoDao kimonoDao("NovoBanco.db");
    Kimono kimono = kimonoDao.findById(idProduto);

    std::cout << std::left
              << std::setw(15) << "ID Produto"
              << std::setw(15) << "Marca"
              << std::setw(15) << "Modelo"
              << std::setw(15) << "SKU"
              << std::setw(15) << "Faixa Etária"
              << std::setw(15) << "Tamanho"
              << std::setw(15) << "Sexo"
              << std::setw(15) << "Cor"
              << std::setw(15) << "Gramatura"
              << std::setw(15) << "Encolhimento"
              << std::setw(15) << "Forma" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    kimono.kimonoToString();
}

void KimonoController::deletar()
{
    listarTodos();
    int idProduto;

    std::cout << "Insira o id do kimono a ser deletado: ";
    std::cin >> idProduto;

    KimonoDao kimonoDao("NovoBanco.db");
    kimonoDao.deleteById(idProduto);

    std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    listarTodos();
    std::cout << "\n\n EXCLUSÃO REALIZADA COM SUCESSO.";
}
