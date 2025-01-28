package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Funcionario;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class FuncionarioDao {
    private final JdbcClient jdbcClient;

    public FuncionarioDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Funcionario pelo ID
    public Funcionario findById(int idFuncionario) {
        Optional<Funcionario> optionalFuncionario = jdbcClient
                .sql("SELECT * FROM Funcionario WHERE idFuncionario = :idFuncionario")
                .param("idFuncionario", idFuncionario)
                .query(Funcionario.class)
                .optional();

        if (optionalFuncionario.isPresent()) {
            return optionalFuncionario.get();
        }

        return null;
    }

    // Buscar uma Funcionario pelo email
    public Funcionario findByEmail(String email) {
        return jdbcClient
                .sql("SELECT *, idFuncionario AS idPessoa FROM Funcionario WHERE email = :email")
                .param("email", email)
                .query(Funcionario.class)
                .single();
    }

    // Buscar todas as Funcionarioes
    public List<Funcionario> findAll() {
        return jdbcClient
                .sql("SELECT *, idFuncionario AS idPessoa FROM Funcionario")
                .query(Funcionario.class)
                .list();
    }

    // Inserir uma nova Funcionario
    public void insert(Funcionario funcionario) {
        jdbcClient
                .sql("INSERT INTO Funcionario (email, senha, idFuncionario) VALUES (:email, :senha, :idFuncionario)")
                .param("email", funcionario.getEmail())
                .param("senha", funcionario.getSenha())
                .param("idFuncionario", funcionario.getIdPessoa())
                .update();
    }

    // Atualizar uma Funcionario existente
    public void update(Funcionario funcionario) {
        jdbcClient
                .sql("UPDATE Funcionario SET email = :email, senha = :senha WHERE idFuncionario = :idFuncionario")
                .param("email", funcionario.getEmail())
                .param("senha", funcionario.getSenha())
                .param("idFuncionario", funcionario.getIdPessoa())
                .update();
    }

    // Deletar uma Funcionario pelo ID
    public void delete(int idFuncionario) {
        jdbcClient
                .sql("DELETE FROM Funcionario WHERE idFuncionario = :idFuncionario")
                .param("idFuncionario", idFuncionario)
                .update();
    }
}