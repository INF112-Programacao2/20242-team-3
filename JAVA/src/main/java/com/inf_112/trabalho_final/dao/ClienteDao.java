package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Cliente;

import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class ClienteDao {
    private final JdbcClient jdbcClient;

    public ClienteDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Cliente pelo ID
    public Cliente findById(int idCliente) {
        Optional<Cliente> optionalCliente = jdbcClient
                .sql("SELECT * FROM Cliente WHERE idCliente = :idCliente")
                .param("idCliente", idCliente)
                .query(Cliente.class)
                .optional();

        if (optionalCliente.isPresent()){
            return optionalCliente.get();
        }

        return null;
    }

    // Buscar todas as Clientees
    public List<Cliente> findAll() {
        return jdbcClient
                .sql("SELECT *, idCliente AS idPessoa FROM Cliente")
                .query(Cliente.class)
                .list();
    }

    // Inserir uma nova Cliente
    public void insert(Cliente cliente) {
        jdbcClient
                .sql("INSERT INTO Cliente (envergadura, peso, altura, torax, cintura) VALUES (:envergadura, :peso, :altura, :torax, :cintura)")
                .param("envergadura", cliente.getEnvergadura())
                .param("peso", cliente.getPeso())
                .param("altura", cliente.getAltura())
                .param("torax", cliente.getTorax())
                .param("cintura", cliente.getCintura())
                .update();
    }

    // Atualizar uma Cliente existente
    public void update(Cliente cliente) {
        jdbcClient
                .sql("UPDATE Cliente SET envergadura = :envergadura, peso = :peso, altura = :altura, torax = :torax, cintura = :cintura  WHERE idCliente = :idCliente")
                .param("envergadura", cliente.getEnvergadura())
                .param("peso", cliente.getPeso())
                .param("altura", cliente.getAltura())
                .param("torax", cliente.getTorax())
                .param("cintura", cliente.getCintura())
                .param("idCliente", cliente.getIdPessoa())
                .update();
    }

    // Deletar uma Cliente pelo ID
    public void delete(int idCliente) {
        jdbcClient
                .sql("DELETE FROM Cliente WHERE idCliente = :idCliente")
                .param("idCliente", idCliente)
                .update();
    }

    public Cliente findByCpf(String cpf) {
        return jdbcClient
                .sql("SELECT * FROM Cliente WHERE cpf = :cpf")
                .param("cpf", cpf)
                .query(Cliente.class)
                .single();
    }
}