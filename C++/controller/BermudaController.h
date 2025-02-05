#ifndef BERMUDA_CONTROLLER_H
#define BERMUDA_CONTROLLER_H

#include <iostream>
#include "../model/Bermuda.h"
#include "GenericController.h"
#include "../dao/BermudaDao.h"

class BermudaController : public GenericController {
public:
    void exibirMenu() override;
    void menu() override;
    void inserir() override;
    void atualizar() override;
    void listarTodos() override;
    void listarPorId() override;
    void deletar() override;
};

#endif // BERMUDA_CONTROLLER_H
