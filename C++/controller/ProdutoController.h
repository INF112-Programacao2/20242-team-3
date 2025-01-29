#ifndef PRODUTO_CONTROLLER_H
#define PRODUTO_CONTROLLER_H

#include <iostream>
// #include "BermudaController.h"
#include "KimonoController.h"

class ProdutoController {
private:
    // BermudaController bermudaController;
    KimonoController kimonoController;

public:
    void exibirMenu();
    void menu();
};
#endif 
