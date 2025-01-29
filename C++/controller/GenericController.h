#ifndef GENERIC_CONTROLLER_H
#define GENERIC_CONTROLLER_H

class GenericController {
public:
    virtual void inserir() = 0;
    virtual void atualizar() = 0;
    virtual void listarTodos() = 0;
    virtual void listarPorId() = 0;
    virtual void deletar() = 0;
    virtual void exibirMenu() = 0;
    virtual void menu() = 0;
    virtual ~GenericController() = default;
};

#endif
