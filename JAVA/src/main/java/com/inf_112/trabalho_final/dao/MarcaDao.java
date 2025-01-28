package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Marca;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class MarcaDao {
        private final JdbcClient jdbcClient;

        public MarcaDao(JdbcClient jdbcClient) {
                this.jdbcClient = jdbcClient;
        }

        // Buscar uma Marca pelo ID
        public Marca findById(int idMarca) {
                Optional<Marca> optionalMarca = jdbcClient
                                .sql("SELECT * FROM Marca WHERE idMarca = :idMarca")
                                .param("idMarca", idMarca)
                                .query(Marca.class)
                                .optional();

                if (optionalMarca.isPresent()) {
                        return optionalMarca.get();
                }

                return null;
        }

        // Buscar todas as Marcaes
        public List<Marca> findAll() {
                return jdbcClient
                                .sql("SELECT * FROM Marca")
                                .query(Marca.class)
                                .list();
        }

        // Inserir uma nova Marca
        public void insert(Marca marca) {
                jdbcClient
                                .sql("INSERT INTO Marca (nome) VALUES (:nome)")
                                .param("nome", marca.getNome())
                                .update();
        }

        // Atualizar uma Marca existente
        public void update(Marca marca) {
                jdbcClient
                                .sql("UPDATE Marca SET nome = :nome WHERE idMarca = :idMarca")
                                .param("nome", marca.getNome())
                                .param("idMarca", marca.getIdMarca())
                                .update();
        }

        // Deletar uma Marca pelo ID
        public void delete(int idMarca) {
                jdbcClient
                                .sql("DELETE FROM Marca WHERE idMarca = :idMarca")
                                .param("idMarca", idMarca)
                                .update();
        }
}