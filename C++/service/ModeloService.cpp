#include "ModeloDao.h"
#include "Modelo.h"
#include <vector>
#include <memory>

class ModeloService {
private:
    std::shared_ptr<ModeloDao> modeloDao; // Uso de ponteiro inteligente para gerenciar a instância de ModeloDao

public:
    // Construtor
    explicit ModeloService(std::shared_ptr<ModeloDao> dao) : modeloDao(std::move(dao)) {}

    // Buscar um modelo pelo ID
    Modelo getById(int id) {
        return modeloDao->findById(id);
    }

    // Buscar todos os modelos
    std::vector<Modelo> getAll() {
        return modeloDao->findAll();
    }

    // Buscar todos os modelos por ID da marca
    std::vector<Modelo> getAllByMarca(int idMarca) {
        return modeloDao->findAllByMarca(idMarca);
    }

    // Inserir um novo modelo
    void insert(const Modelo& modelo) {
        modeloDao->insert(modelo);
    }

    // Atualizar um modelo existente
    void update(const Modelo& modelo) {
        modeloDao->update(modelo);
    }

    // Deletar um modelo pelo ID
    void deleteById(int id) {
        modeloDao->deleteById(id);
    }
};
