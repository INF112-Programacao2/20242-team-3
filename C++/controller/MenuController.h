#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <iostream>
#include <string>
#include "KimonoController.h"
#include "BermudaController.h"
#include "LoginController.h"

class MenuController {
private:
    KimonoController kimonoController;
    BermudaController bermudaController;

public:
    void exibirMenu();
    void menu();
};

#endif
