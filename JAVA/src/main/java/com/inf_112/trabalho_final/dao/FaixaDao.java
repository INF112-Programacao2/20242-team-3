package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Faixa;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class FaixaDao {
    private final JdbcClient jdbcClient;

    public FaixaDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Faixa pelo ID
    public Faixa findById(int idFaixa) {
        Optional<Faixa> optionalFaixa = jdbcClient
                .sql("SELECT * FROM Faixa WHERE idFaixa = :idFaixa")
                .param("idFaixa", idFaixa)
                .query(Faixa.class)
                .optional();

        if (optionalFaixa.isPresent()) {
            return optionalFaixa.get();
        }

        return null;
    }

    // Buscar todos os Faixas
    public List<Faixa> findAll() {
        return jdbcClient
                .sql("SELECT *, idFaixa AS idProduto FROM Faixa")
                .query(Faixa.class)
                .list();
    }

    // Inserir um novo Faixa
    public void insert(Faixa faixa) {
        jdbcClient
                .sql("INSERT INTO Faixa (espessura) VALUES (:espessura)")
                .param("espessura", faixa.getEspessura().name())
                .update();
    }

    // Atualizar uma Faixa existente
    public void update(Faixa faixa) {
        jdbcClient
                .sql("UPDATE Faixa SET espessura = :espessura WHERE idFaixa = :idFaixa")
                .param("espessura", faixa.getEspessura().name())
                .param("idFaixa", faixa.getIdProduto())
                .update();
    }

    // Deletar uma Faixa pelo ID
    public void delete(int idFaixa) {
        jdbcClient
                .sql("DELETE FROM Faixa WHERE idFaixa = :idFaixa")
                .param("idFaixa", idFaixa)
                .update();
    }
}