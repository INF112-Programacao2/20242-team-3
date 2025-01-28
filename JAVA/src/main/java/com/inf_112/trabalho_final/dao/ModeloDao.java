package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Modelo;
import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class ModeloDao {
        private final JdbcClient jdbcClient;

        public ModeloDao(JdbcClient jdbcClient) {
                this.jdbcClient = jdbcClient;
        }

        // Buscar uma Modelo pelo ID
        public Modelo findById(int idModelo) {
                Optional<Modelo> optionalModelo = jdbcClient
                                .sql("SELECT * FROM Modelo WHERE idModelo = :idModelo")
                                .param("idModelo", idModelo)
                                .query(Modelo.class)
                                .optional();

                if (optionalModelo.isPresent()) {
                        return optionalModelo.get();
                }

                return null;
        }

        // Buscar todas as Modeloes
        public List<Modelo> findAllByMarca(int idMarca) {
                return jdbcClient
                                .sql("SELECT * FROM Modelo WHERE idMarca = :idMarca")
                                .param("idMarca", idMarca)
                                .query(Modelo.class)
                                .list();
        }

        // Buscar todas as Modeloes
        public List<Modelo> findAll() {
                return jdbcClient
                                .sql("SELECT * FROM Modelo")
                                .query(Modelo.class)
                                .list();
        }

        // Inserir uma nova Modelo
        public void insert(Modelo modelo) {
                jdbcClient
                                .sql("INSERT INTO Modelo (nome, idMarca) VALUES (:nome, :idMarca)")
                                .param("nome", modelo.getNome())
                                .param("idMarca", modelo.getIdMarca())
                                .update();
        }

        // Atualizar uma Modelo existente
        public void update(Modelo Modelo) {
                jdbcClient
                                .sql("UPDATE Modelo SET nome = :nome, idMarca = :idMarca WHERE idModelo = :idModelo")
                                .param("nome", Modelo.getNome())
                                .param("idMarca", Modelo.getIdMarca())
                                .param("idModelo", Modelo.getIdModelo())
                                .update();
        }

        // Deletar uma Modelo pelo ID
        public void delete(int idModelo) {
                jdbcClient
                                .sql("DELETE FROM Modelo WHERE idModelo = :idModelo")
                                .param("idModelo", idModelo)
                                .update();
        }
}