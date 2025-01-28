#include <crow.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "BermudaService.h" // Inclua seu serviço de Bermuda

class BermudaController {
private:
    BermudaService bermudaService;

public:
    BermudaController(BermudaService service) : bermudaService(service) {}

    void setupRoutes(crow::SimpleApp& app) {
        // Endpoint para obter todas as bermudas
        CROW_ROUTE(app, "/armor/produtos/bermuda/").methods(crow::HTTPMethod::GET)([this]() {
            auto bermudas = bermudaService.getAll();
            return crow::response(200, crow::json::wvalue(bermudas));
        });

        // Endpoint para obter uma bermuda por ID
        CROW_ROUTE(app, "/armor/produtos/bermuda/<int>").methods(crow::HTTPMethod::GET)([this](int idBermuda) {
            auto bermuda = bermudaService.getById(idBermuda);
            if (!bermuda.has_value()) {
                return crow::response(404, "Bermuda not found");
            }
            return crow::response(200, crow::json::wvalue(bermuda.value()));
        });

        // Endpoint para criar uma nova bermuda
        CROW_ROUTE(app, "/armor/produtos/bermuda/").methods(crow::HTTPMethod::POST)([this](const crow::request& req) {
            try {
                auto bermuda = crow::json::load(req.body);
                bermudaService.insert(bermuda);
                return crow::response(201, "Bermuda created successfully");
            } catch (const std::exception& e) {
                return crow::response(400, e.what());
            }
        });

        // Endpoint para atualizar uma bermuda
        CROW_ROUTE(app, "/armor/produtos/bermuda/").methods(crow::HTTPMethod::PUT)([this](const crow::request& req) {
            try {
                auto bermuda = crow::json::load(req.body);
                bermudaService.update(bermuda);
                return crow::response(200, "Bermuda updated successfully");
            } catch (const std::exception& e) {
                return crow::response(400, e.what());
            }
        });

        // Endpoint para deletar uma bermuda
        CROW_ROUTE(app, "/armor/produtos/bermuda/<int>").methods(crow::HTTPMethod::DELETE)([this](int idBermuda) {
            auto bermuda = bermudaService.getById(idBermuda);
            if (!bermuda.has_value()) {
                return crow::response(404, "Bermuda not found");
            }
            bermudaService.deleteById(idBermuda);
            return crow::response(200, "Bermuda deleted successfully");
        });
    }
};

int main() {
    crow::SimpleApp app;

    BermudaService bermudaService; // Implementação do serviço
    BermudaController controller(bermudaService);
    controller.setupRoutes(app);

    app.port(8080).multithreaded().run();
    return 0;
}
