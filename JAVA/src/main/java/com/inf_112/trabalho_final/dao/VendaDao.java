package com.inf_112.trabalho_final.dao;

import com.inf_112.trabalho_final.model.Pesquisa;
import com.inf_112.trabalho_final.model.Venda;
import java.util.List;
import java.util.Optional;

import org.springframework.jdbc.core.simple.JdbcClient;
import org.springframework.stereotype.Repository;

@Repository
public class VendaDao {
    private final JdbcClient jdbcClient;

    public VendaDao(JdbcClient jdbcClient) {
        this.jdbcClient = jdbcClient;
    }

    // Buscar uma Venda pelo ID
    public Venda findById(int idVenda) {
        Optional<Venda> optionalVenda = jdbcClient
                .sql("SELECT * FROM Venda WHERE idVenda = :idVenda")
                .param("idVenda", idVenda)
                .query(Venda.class)
                .optional();

        if (optionalVenda.isPresent()){
            return optionalVenda.get();
        }

        return null;
    }

    // Buscar todas as Vendaes
    public List<Venda> findAll() {
        return jdbcClient
                .sql("SELECT * FROM Venda")
                .query(Venda.class)
                .list();
    }

    // Inserir uma nova Venda
    public void insert(Venda venda) {
        jdbcClient
                .sql("INSERT INTO Venda (cpf, SKU, dataVenda, satisfacao, ajuste) VALUES (:cpf, :SKU, :dataVenda, :satisfacao, :ajuste)")
                .param("cpf", venda.getCpf()) // Converte enum para String
                .param("SKU", venda.getSKU())
                .param("dataVenda", venda.getDataVenda())
                .param("satisfacao", venda.getSatisfacao().name())
                .param("ajuste", venda.getAjuste().name())
                .update();
    }

    // Atualizar uma Venda existente
    public void update(Venda venda) {
        jdbcClient
                .sql("UPDATE Venda SET cpf = :cpf, SKU = :SKU, dataVenda = :dataVenda, satisfacao = :satisfacao, ajuste = :ajuste WHERE idVenda = :idVenda")
                .param("cpf", venda.getCpf()) // Converte enum para String
                .param("SKU", venda.getSKU())
                .param("dataVenda", venda.getDataVenda())
                .param("satisfacao", venda.getSatisfacao().name())
                .param("ajuste", venda.getAjuste().name())
                .param("idVenda", venda.getIdVenda())
                .update();
    }

    // Deletar uma Venda pelo ID
    public void delete(int idVenda) {
        jdbcClient
                .sql("DELETE FROM Venda WHERE idVenda = :idVenda")
                .param("idVenda", idVenda)
                .update();
    }

    public List<Venda> searchVendas(Pesquisa pesquisa) {
        double pesoMin = pesquisa.getPeso() - pesquisa.getVariacaoPeso();
        double pesoMax = pesquisa.getPeso() + pesquisa.getVariacaoPeso();
        double alturaMin = pesquisa.getAltura() - pesquisa.getVariacaoAltura();
        double alturaMax = pesquisa.getAltura() + pesquisa.getVariacaoAltura();

        return jdbcClient
                .sql("SELECT v.* FROM Venda INNER JOIN Cliente c ON v.cpfCliente = c.cpf  WHERE c.peso BETWEEN :pesoMin AND :pesoMax AND c.altura BETWEEN :alturaMin AND :alturaMax")
                .param("pesoMin", pesoMin)
                .param("pesoMax", pesoMax)
                .param("alturaMin", alturaMin)
                .param("alturaMax", alturaMax)
                .query(Venda.class)
                .list();
    }
}