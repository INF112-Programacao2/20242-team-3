package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Cor;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class CorDao {
        private final JdbcClient jdbcClient;

        public CorDao(JdbcClient jdbcClient) {
                this.jdbcClient = jdbcClient;
        }

        // Buscar uma Cor pelo ID
        public Cor findById(int idCor) {
                Optional<Cor> optionalCor = jdbcClient
                                .sql("SELECT * FROM Cor WHERE idCor = :idCor")
                                .param("idCor", idCor)
                                .query(Cor.class)
                                .optional();

                if (optionalCor.isPresent()) {
                        return optionalCor.get();
                }

                return null;
        }

        // Buscar todas as Cores
        public List<Cor> findAll() {
                return jdbcClient
                                .sql("SELECT * FROM Cor")
                                .query(Cor.class)
                                .list();
        }

        // Inserir uma nova Cor
        public void insert(Cor cor) {
                jdbcClient
                                .sql("INSERT INTO Cor (nome) VALUES (:nome)")
                                .param("nome", cor.getNome())
                                .update();
        }

        // Atualizar uma Cor existente
        public void update(Cor cor) {
                jdbcClient
                                .sql("UPDATE Cor SET nome = :nome WHERE idCor = :idCor")
                                .param("nome", cor.getNome())
                                .param("idCor", cor.getIdCor())
                                .update();
        }

        // Deletar uma Cor pelo ID
        public void delete(int idCor) {
                jdbcClient
                                .sql("DELETE FROM Cor WHERE idCor = :idCor")
                                .param("idCor", idCor)
                                .update();
        }
}