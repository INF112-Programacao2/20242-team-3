package com.inf_112.trabalho_final.dao;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

import com.inf_112.trabalho_final.model.Pessoa;

@Repository
public class PessoaDao {
    private final JdbcClient jdbcClient;

    public PessoaDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Pessoa pelo ID
    public Pessoa findById(int idPessoa) {
        Optional<Pessoa> optionalPessoa = jdbcClient
                .sql("SELECT * FROM Pessoa WHERE idPessoa = :idPessoa")
                .param("idPessoa", idPessoa)
                .query(Pessoa.class)
                .optional();

        if (optionalPessoa.isPresent()){
            return optionalPessoa.get();
        }

        return null;
    }

    // Buscar todas as Pessoas
    public List<Pessoa> findAll() {
        return jdbcClient
                .sql("SELECT * FROM Pessoa")
                .query(Pessoa.class)
                .list();
    }

    // Inserir uma nova Pessoa
    public Pessoa insert(Pessoa pessoa) {

        jdbcClient
                .sql("INSERT INTO Pessoa (nome, nascimento, telefone, cpf, idade, sexo) VALUES (:nome, :nascimento, :telefone, :cpf, :idade, :sexo)")
                .param("nome", pessoa.getNome())
                .param("nascimento", pessoa.getNascimento())
                .param("telefone", pessoa.getTelefone())
                .param("cpf", pessoa.getCpf())
                .param("idade", pessoa.getIdade())
                .param("sexo", pessoa.getSexo().name()) // Converte enum para String
                .update(); // Retorna o ID gerado

        pessoa.setIdPessoa(jdbcClient.sql("SELECT LAST_INSERT_ID()").query(Integer.class).single());

        return pessoa;
    }

    // Atualizar uma Pessoa existente
    public Pessoa update(Pessoa pessoa) {
        jdbcClient
                .sql("UPDATE Pessoa SET nome = :nome, nascimento = :nascimento, telefone = :telefone, cpf = :cpf, idade = :idade, sexo = :sexo WHERE idPessoa = :idPessoa")
                .param("nome", pessoa.getNome())
                .param("nascimento", pessoa.getNascimento())
                .param("telefone", pessoa.getTelefone())
                .param("cpf", pessoa.getCpf())
                .param("idade", pessoa.getIdade())
                .param("sexo", pessoa.getSexo().name()) // Converte enum para String
                .param("idPessoa", pessoa.getIdPessoa())
                .update();

        return pessoa;
    }

    // Deletar uma Pessoa pelo ID
    public void delete(int idPessoa) {
        jdbcClient
                .sql("DELETE FROM Pessoa WHERE idPessoa = :idPessoa")
                .param("idPessoa", idPessoa)
                .update();
    }
}
