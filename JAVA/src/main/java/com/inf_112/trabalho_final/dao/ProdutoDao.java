package com.inf_112.trabalho_final.dao;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

import com.inf_112.trabalho_final.model.Produto;

@Repository
public class ProdutoDao {
    private final JdbcClient jdbcClient;

    public ProdutoDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Produto pelo ID
    public Produto findById(int idProduto) {
        Optional<Produto> optionalProduto = jdbcClient
                .sql("SELECT * FROM Produto WHERE idProduto = :idProduto")
                .param("idProduto", idProduto)
                .query(Produto.class)
                .optional();

        if (optionalProduto.isPresent()) {
            return optionalProduto.get(); // Retorna o valor presente
        }
        return null; // Ou lance uma exceção, se desejar
    }

    // Buscar todas as Produtos
    public List<Produto> findAll() {
        return jdbcClient
                .sql("SELECT * FROM Produto")
                .query(Produto.class)
                .list();
    }

    // Inserir uma nova Produto
    public Produto insert(Produto produto) {

        jdbcClient
                .sql("INSERT INTO Produto (idMarca, idModelo, SKU, faixaEtaria, idTamanho, sexo, idCor) VALUES (:idMarca, :idModelo, :SKU, :faixaEtaria, :idTamanho, :sexo, :idCor)")
                .param("idMarca", produto.getIdMarca())
                .param("idModelo", produto.getIdModelo())
                .param("SKU", produto.getSKU())
                .param("faixaEtaria", produto.getFaixaEtaria().name())
                .param("idTamanho", produto.getIdTamanho())
                .param("sexo", produto.getSexo().name()) // Converte enum para String
                .param("idCor", produto.getIdCor())
                .update(); // Retorna o ID gerado

        produto
                .setIdProduto(jdbcClient.sql("SELECT LAST_INSERT_ID()")
                        .query(Integer.class)
                        .single());

        return produto;
    }

    // Atualizar uma Produto existente
    public Produto update(Produto produto) {
        jdbcClient
                .sql("UPDATE Produto SET idMarca = :idMarca, idModelo = :idModelo, SKU = :SKU, faixaEtaria = :faixaEtaria, idTamanho = :idTamanho, sexo = :sexo, idCor = :idCor WHERE idProduto = :idProduto")
                .param("idMarca", produto.getIdMarca())
                .param("idModelo", produto.getIdModelo())
                .param("SKU", produto.getSKU())
                .param("faixaEtaria", produto.getFaixaEtaria().name())
                .param("idTamanho", produto.getIdTamanho())
                .param("sexo", produto.getSexo().name()) // Converte enum para String
                .param("idCor", produto.getIdCor())
                .param("idProduto", produto.getIdProduto())
                .update();

        return produto;
    }

    // Deletar uma Produto pelo ID
    public void delete(int idProduto) {
        jdbcClient
                .sql("DELETE FROM Produto WHERE idProduto = :idProduto")
                .param("idProduto", idProduto)
                .update();
    }

    public Produto findBySKU(String SKU) {
        return jdbcClient
                .sql("SELECT * FROM Produto WHERE SKU = :SKU")
                .param("SKU", SKU)
                .query(Produto.class)
                .single();
    }

    public String searchTipoProduto(int idProduto) {
        return jdbcClient
                .sql("SELECT 'Kimono' AS tipo FROM Kimono WHERE idKimono = :idProduto "
                        + "UNION ALL SELECT 'Faixa' AS tipo FROM Faixa WHERE idFaixa = :idProduto "
                        + "UNION ALL SELECT 'Bermuda' AS tipo FROM Bermuda WHERE idBermuda = :idProduto"
                        + "UNION ALL SELECT 'Rash_Guard' AS tipo FROM Rash_Guard WHERE idRash_Guard = :idProduto")
                .param("idProduto", idProduto)
                .query(String.class)
                .single();
    }
}
