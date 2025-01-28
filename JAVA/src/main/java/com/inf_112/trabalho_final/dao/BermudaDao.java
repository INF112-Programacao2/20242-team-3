package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Bermuda;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class BermudaDao {
    private final JdbcClient jdbcClient;

    public BermudaDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Bermuda pelo ID
    public Bermuda findById(int idBermuda) {
        Optional<Bermuda> optionalBermuda = jdbcClient
                .sql("SELECT * FROM Bermuda WHERE idBermuda = :idBermuda")
                .param("idBermuda", idBermuda)
                .query(Bermuda.class)
                .optional();

        if (optionalBermuda.isPresent()) {
            return optionalBermuda.get(); // Retorna o valor presente
        }
        return null; // Ou lance uma exceção, se desejar
    }

    // Buscar todos os Bermudas
    public List<Bermuda> findAll() {
        return jdbcClient
                .sql("SELECT *, idBermuda AS idProduto FROM Bermuda")
                .query(Bermuda.class)
                .list();
    }

    // Inserir um novo Bermuda
    public void insert(Bermuda bermuda) {
        jdbcClient
                .sql("INSERT INTO Bermuda (ajuste, comprimento) VALUES (:ajuste, :comprimento)")
                .param("ajuste", bermuda.getAjuste().name())
                .param("comprimento", bermuda.getComprimento().name())
                .update();
    }

    // Atualizar uma Bermuda existente
    public void update(Bermuda bermuda) {
        jdbcClient
                .sql("UPDATE Bermuda SET ajuste = :ajuste, comprimento = :comprimento WHERE idBermuda = :idBermuda")
                .param("ajuste", bermuda.getAjuste().name())
                .param("comprimento", bermuda.getComprimento().name())
                .param("idBermuda", bermuda.getIdProduto())
                .update();
    }

    // Deletar uma Bermuda pelo ID
    public void delete(int idBermuda) {
        jdbcClient
                .sql("DELETE FROM Bermuda WHERE idBermuda = :idBermuda")
                .param("idBermuda", idBermuda)
                .update();
    }
}