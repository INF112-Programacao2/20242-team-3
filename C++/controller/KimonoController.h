#ifndef KIMONO_CONTROLLER_H
#define KIMONO_CONTROLLER_H

#include <iostream>
#include "../model/Kimono.h"
#include "GenericController.h"

class KimonoController : public GenericController {
public:
    void exibirMenu() override;
    void menu() override;
    void inserir() override;
    void atualizar() override;
    void listarTodos() override;
    void listarPorId() override;
    void deletar() override;
};

#endif // KIMONO_CONTROLLER_H
