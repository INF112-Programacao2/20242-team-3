// Includes como <vector>, <iostream> etc. já estão no KimonoDao.h
#include <iostream>
#include "KimonoDao.h"

int main() {
    try {
        int id = 13;

        KimonoDao kimonoDao("NovoBanco.db");

        // Inserir um novo kimono
        Kimono kimono(id, Marca::DUBAI, Modelo::COMUM, "Kimono SKU13", FaixaEtaria::ADULTO,
                      Tamanho::G, Sexo::FEMININO, Cor::AZUL, 20.5, 5, Forma::SLIM);
        kimonoDao.insert(kimono);

        // Buscar e exibir a kimono pelo ID
        Kimono retrievedKimono = kimonoDao.findById(id);
        std::cout << "Exibindo o kimono buscado pelo id:" << std::endl;
        std::cout << "Kimono ID: " << retrievedKimono.getIdProduto()
                  << ", Gramatura: " << retrievedKimono.getGramaturaTecido()
                  << ", Encolhimento: " << retrievedKimono.getEncolhimento()
                  << ", Forma: " << kimonoDao.formaToString(retrievedKimono.getForma()) << std::endl; 

        // Atualizar a kimono
        retrievedKimono.setGramaturaTecido(55);
        retrievedKimono.setEncolhimento(10);
        retrievedKimono.setForma(Forma::TRADICIONAL);

        kimonoDao.update(retrievedKimono);

        // Buscar e exibir novamente
        retrievedKimono = kimonoDao.findById(id);
        std::cout << "Exibindo o kimono buscada pelo id:" << std::endl;
        std::cout << "Kimono ID: " << retrievedKimono.getIdProduto()
                  << ", Gramatura: " << retrievedKimono.getGramaturaTecido()
                  << ", Encolhimento: " << retrievedKimono.getEncolhimento()
                  << ", Forma: " << kimonoDao.formaToString(retrievedKimono.getForma()) << std::endl;

        // Buscar e exibir todas as kimonos
        std::vector<Kimono> allKimono = kimonoDao.findAll();

        std::cout << "Exibindo todas as kimonos:" << std::endl;
        for(int i = 0; i < allKimono.size(); i++){
            std::cout << "Kimono ID: " << allKimono[i].getIdProduto()
                  << ", Gramatura: " << allKimono[i].getGramaturaTecido()
                  << ", Encolhimento " << allKimono[i].getEncolhimento()
                  << ", Forma: " << kimonoDao.formaToString(allKimono[i].getForma()) << std::endl;
        }

        // // Deletar a kimono
        // // kimonoDao.deleteById(id);
        // // std::cout << "Kimono deletado." << std::endl;

        // Buscar e exibir todas as kimonos
        std::vector<Kimono> allKimono2 = kimonoDao.findAll();

        std::cout << "Exibindo todas as kimonos:" << std::endl;
        for(int i = 0; i < allKimono2.size(); i++){
            std::cout << "Kimono ID: " << allKimono2[i].getIdProduto()
                  << ", Gramatura: " << allKimono2[i].getGramaturaTecido()
                  << ", Encolhimento " << allKimono2[i].getEncolhimento()
                  << ", Forma: " << kimonoDao.formaToString(allKimono2[i].getForma()) << std::endl;
        }

        // Buscar pelo SKU
        // Kimono kimonoBySKU = kimonoDao.findBySKU("Novo SKU3");
        // std::cout << "Exibindo a kimono buscada pelo SKU:" << std::endl;
        // std::cout << "Kimono ID: " << kimonoBySKU.getIdKimono()
        //           << ", Marca ID: " << kimonoBySKU.getIdMarca()
        //           << ", Modelo ID: " << kimonoBySKU.getIdModelo()
        //           << ", SKU: " << kimonoBySKU.getSKU()
        //           << ", Faixa etaria: " << kimonoDao.faixaEtariaToString(kimonoBySKU.getFaixaEtaria())
        //           << ", Tamanho ID: " << kimonoBySKU.getIdTamanho()
        //           << ", Sexo: " << kimonoDao.sexoToString(kimonoBySKU.getSexo())
        //           << ", Cor ID: " << kimonoBySKU.getIdCor() << std::endl;

        // Buscar como Tipo de Kimono Tem que fazer dos outros Kimonos ainda
        // try {
        //     std::string tipo = produtoDao.searchTipoKimono(1); // Exemplo de ID
        //     std::cout << "Tipo do Kimono: " << tipo << std::endl;
        // } catch (const std::exception& e) {
        //     std::cerr << "Erro: " << e.what() << std::endl;
        // }

    } catch (const std::exception& ex) {
        std::cerr << "Erro: " << ex.what() << std::endl;
    }

    return 0;
}