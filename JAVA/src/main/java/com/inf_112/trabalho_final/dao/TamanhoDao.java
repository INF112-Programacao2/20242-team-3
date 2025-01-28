package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Tamanho;
import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class TamanhoDao {
        private final JdbcClient jdbcClient;

        public TamanhoDao(JdbcClient jdbcClient) {
                this.jdbcClient = jdbcClient;
        }

        // Buscar uma Tamanho pelo ID
        public Tamanho findById(int idTamanho) {
                Optional<Tamanho> optionalTamanho = jdbcClient
                                .sql("SELECT * FROM Tamanho WHERE idTamanho = :idTamanho")
                                .param("idTamanho", idTamanho)
                                .query(Tamanho.class)
                                .optional();

                if (optionalTamanho.isPresent()) {
                        return optionalTamanho.get();
                }

                return null;
        }

        // Buscar todas as Tamanhoes
        public List<Tamanho> findAllByTipoProduto(String tipoProduto) {
                return jdbcClient
                                .sql("SELECT * FROM Tamanho WHERE tipoProduto = :tipoProduto")
                                .param("tipoProduto", tipoProduto)
                                .query(Tamanho.class)
                                .list();
        }

        // Buscar todas as Tamanhoes
        public List<Tamanho> findAll() {
                return jdbcClient
                                .sql("SELECT * FROM Tamanho")
                                .query(Tamanho.class)
                                .list();
        }

        // Inserir uma nova Tamanho
        public void insert(Tamanho tamanho) {
                jdbcClient
                                .sql("INSERT INTO Tamanho (tipoProduto, nome) VALUES (:tipoProduto, :nome)")
                                .param("tipoProduto", tamanho.getTipoProduto().name()) // Converte enum para String
                                .param("nome", tamanho.getNome())
                                .update();
        }

        // Atualizar uma Tamanho existente
        public void update(Tamanho tamanho) {
                jdbcClient
                                .sql("UPDATE Tamanho SET tipoProduto = :tipoProduto, nome = :nome WHERE idTamanho = :idTamanho")
                                .param("tipoProduto", tamanho.getTipoProduto().name()) // Converte enum para String
                                .param("nome", tamanho.getNome())
                                .param("idTamanho", tamanho.getIdTamanho())
                                .update();
        }

        // Deletar uma Tamanho pelo ID
        public void delete(int idTamanho) {
                jdbcClient
                                .sql("DELETE FROM Tamanho WHERE idTamanho = :idTamanho")
                                .param("idTamanho", idTamanho)
                                .update();
        }
}