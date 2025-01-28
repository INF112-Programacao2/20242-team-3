// Includes como <vector>, <iostream> etc. já estão no ProdutoDao.h
#include "ProdutoDao.h"

int main() {
    try {
        int id = 6;

        ProdutoDao produtoDao("BANCO.db");

        // Inserir um novo produto
        Produto produto(id, 3, nullptr, 3, nullptr, "String SKU6", FaixaEtaria::ADULTO, 3, nullptr, Sexo::FEMININO, 6, nullptr);
        produtoDao.insert(produto);

        // Buscar e exibir a produto pelo ID
        Produto retrievedProduto = produtoDao.findById(id);
        std::cout << "Exibindo o produto buscado pelo id:" << std::endl;
        std::cout << "Produto ID: " << retrievedProduto.getIdProduto()
                  << ", Marca ID: " << retrievedProduto.getIdMarca()
                  << ", Modelo ID: " << retrievedProduto.getIdModelo()
                  << ", SKU: " << retrievedProduto.getSKU()
                  << ", Faixa etaria: " << produtoDao.faixaEtariaToString(retrievedProduto.getFaixaEtaria())
                  << ", Tamanho ID: " << retrievedProduto.getIdTamanho()
                  << ", Sexo: " << produtoDao.sexoToString(retrievedProduto.getSexo())
                  << ", Cor ID: " << retrievedProduto.getIdCor() << std::endl;

        // Atualizar a produto
        retrievedProduto.setIdMarca(14);
        retrievedProduto.setIdModelo(4);
        retrievedProduto.setSKU("Novo SKU6");
        retrievedProduto.setFaixaEtaria(FaixaEtaria::JUVENIL);
        retrievedProduto.setIdTamanho(1);
        retrievedProduto.setSexo(Sexo::MASCULINO);
        retrievedProduto.setIdCor(2);

        produtoDao.update(retrievedProduto);

        // Buscar e exibir novamente
        retrievedProduto = produtoDao.findById(id);
        std::cout << "Exibindo a produto buscada pelo id:" << std::endl;
        std::cout << "Produto ID: " << retrievedProduto.getIdProduto()
                  << ", Marca ID: " << retrievedProduto.getIdMarca()
                  << ", Modelo ID: " << retrievedProduto.getIdModelo()
                  << ", SKU: " << retrievedProduto.getSKU()
                  << ", Faixa etaria: " << produtoDao.faixaEtariaToString(retrievedProduto.getFaixaEtaria())
                  << ", Tamanho ID: " << retrievedProduto.getIdTamanho()
                  << ", Sexo: " << produtoDao.sexoToString(retrievedProduto.getSexo())
                  << ", Cor ID: " << retrievedProduto.getIdCor() << std::endl;

        // Buscar e exibir todas as produtos
        std::vector<Produto> allProduto = produtoDao.findAll();

        std::cout << "Exibindo todas as produtos:" << std::endl;
        for(int i = 0; i < allProduto.size(); i++){
            std::cout << "Produto ID: " << allProduto[i].getIdProduto()
                  << ", Marca ID: " << allProduto[i].getIdMarca()
                  << ", Modelo ID: " << allProduto[i].getIdModelo()
                  << ", SKU: " << allProduto[i].getSKU()
                  << ", Faixa etaria: " << produtoDao.faixaEtariaToString(allProduto[i].getFaixaEtaria())
                  << ", Tamanho ID: " << allProduto[i].getIdTamanho()
                  << ", Sexo: " << produtoDao.sexoToString(allProduto[i].getSexo())
                  << ", Cor ID: " << allProduto[i].getIdCor() << std::endl;
        }

        // Deletar a produto
        produtoDao.deleteById(id);
        std::cout << "Produto deletada." << std::endl;

        // Buscar e exibir todas as produtos
        std::vector<Produto> allProduto2 = produtoDao.findAll();

        std::cout << "Exibindo todas as produtos:" << std::endl;
        for(int i = 0; i < allProduto2.size(); i++){
            std::cout << "Produto ID: " << allProduto2[i].getIdProduto()
                  << ", Marca ID: " << allProduto2[i].getIdMarca()
                  << ", Modelo ID: " << allProduto2[i].getIdModelo()
                  << ", SKU: " << allProduto2[i].getSKU()
                  << ", Faixa etaria: " << produtoDao.faixaEtariaToString(allProduto2[i].getFaixaEtaria())
                  << ", Tamanho ID: " << allProduto2[i].getIdTamanho()
                  << ", Sexo: " << produtoDao.sexoToString(allProduto2[i].getSexo())
                  << ", Cor ID: " << allProduto2[i].getIdCor() << std::endl;
        }

        // Buscar pelo SKU
        Produto produtoBySKU = produtoDao.findBySKU("Novo SKU3");
        std::cout << "Exibindo a produto buscada pelo SKU:" << std::endl;
        std::cout << "Produto ID: " << produtoBySKU.getIdProduto()
                  << ", Marca ID: " << produtoBySKU.getIdMarca()
                  << ", Modelo ID: " << produtoBySKU.getIdModelo()
                  << ", SKU: " << produtoBySKU.getSKU()
                  << ", Faixa etaria: " << produtoDao.faixaEtariaToString(produtoBySKU.getFaixaEtaria())
                  << ", Tamanho ID: " << produtoBySKU.getIdTamanho()
                  << ", Sexo: " << produtoDao.sexoToString(produtoBySKU.getSexo())
                  << ", Cor ID: " << produtoBySKU.getIdCor() << std::endl;

        // Buscar como Tipo de Produto Tem que fazer dos outros Produtos ainda
        // try {
        //     std::string tipo = produtoDao.searchTipoProduto(1); // Exemplo de ID
        //     std::cout << "Tipo do Produto: " << tipo << std::endl;
        // } catch (const std::exception& e) {
        //     std::cerr << "Erro: " << e.what() << std::endl;
        // }

    } catch (const std::exception& ex) {
        std::cerr << "Erro: " << ex.what() << std::endl;
    }

    return 0;
}