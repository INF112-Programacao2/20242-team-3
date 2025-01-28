package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Kimono;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class KimonoDao {
    private final JdbcClient jdbcClient;

    public KimonoDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Kimono pelo ID
    public Kimono findById(int idKimono) {
        Optional<Kimono> optionalKimono = jdbcClient
                .sql("SELECT * FROM Kimono WHERE idKimono = :idKimono")
                .param("idKimono", idKimono)
                .query(Kimono.class)
                .optional();

        if (optionalKimono.isPresent()) {
            return optionalKimono.get();
        }

        return null;
    }

    // Buscar todos os Kimonos
    public List<Kimono> findAll() {
        return jdbcClient
                .sql("SELECT *, idKimono AS idProduto FROM Kimono")
                .query(Kimono.class)
                .list();
    }

    // Inserir um novo Kimono
    public void insert(Kimono kimono) {
        jdbcClient
                .sql("INSERT INTO Kimono (gramaturaTecido, encolhimento, forma) VALUES (:gramaturaTecido, :encolhimento, :forma)")
                .param("gramaturaTecido", kimono.getGramaturaTecido())
                .param("encolhimento", kimono.getEncolhimento())
                .param("forma", kimono.getForma().name())
                .update();
    }

    // Atualizar uma Kimono existente
    public void update(Kimono kimono) {
        jdbcClient
                .sql("UPDATE Kimono SET gramaturaTecido = :gramaturaTecido, encolhimento = :encolhimento, forma = :forma WHERE idKimono = :idKimono")
                .param("gramaturaTecido", kimono.getGramaturaTecido())
                .param("encolhimento", kimono.getEncolhimento())
                .param("forma", kimono.getForma().name())
                .param("idKimono", kimono.getIdProduto())
                .update();
    }

    // Deletar uma Kimono pelo ID
    public void delete(int idKimono) {
        jdbcClient
                .sql("DELETE FROM Kimono WHERE idKimono = :idKimono")
                .param("idKimono", idKimono)
                .update();
    }
}