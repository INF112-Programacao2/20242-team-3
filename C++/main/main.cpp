#include <iostream>
#include "../controller/LoginController.h"
#include "../controller/MenuController.h"

int main() {
    LoginController loginController;
    MenuController menuController;

    //loginController.fazerLogin();
    menuController.menu();
       
    return 0;
}