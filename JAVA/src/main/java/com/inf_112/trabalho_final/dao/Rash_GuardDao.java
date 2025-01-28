package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Rash_Guard;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class Rash_GuardDao {
    private final JdbcClient jdbcClient;

    public Rash_GuardDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Rash_Guard pelo ID
    public Rash_Guard findById(int idRash_Guard) {
        Optional<Rash_Guard> optionalRash_Guard =  jdbcClient
                .sql("SELECT * FROM Rash_Guard WHERE idRash_Guard = :idRash_Guard")
                .param("idRash_Guard", idRash_Guard)
                .query(Rash_Guard.class)
                .optional();

        if (optionalRash_Guard.isPresent()){
            return optionalRash_Guard.get();
        }

        return null;
    }

    // Buscar todos os Rash_Guards
    public List<Rash_Guard> findAll() {
        return jdbcClient
                .sql("SELECT *, idRash_Guard AS idProduto FROM Rash_Guard")
                .query(Rash_Guard.class)
                .list();
    }

    // Inserir um novo Rash_Guard
    public void insert(Rash_Guard rash_Guard) {
        jdbcClient
                .sql("INSERT INTO Rash_Guard (fps) VALUES (:fps)")
                .param("ajuste", rash_Guard.getFps())
                .update();
    }

    // Atualizar uma Rash_Guard existente
    public void update(Rash_Guard rash_Guard) {
        jdbcClient
                .sql("UPDATE Rash_Guard SET fps = :fps WHERE idRash_Guard = :idRash_Guard")
                .param("ajuste", rash_Guard.getFps())
                .update();
    }

    // Deletar uma Rash_Guard pelo ID
    public void delete(int idRash_Guard) {
        jdbcClient
                .sql("DELETE FROM Rash_Guard WHERE idRash_Guard = :idRash_Guard")
                .param("idRash_Guard", idRash_Guard)
                .update();
    }
}