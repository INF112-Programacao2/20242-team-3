package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.*;
import com.inf_112.trabalho_final.model.Pesquisa;
import com.inf_112.trabalho_final.model.Produto;
import com.inf_112.trabalho_final.model.Venda;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class VendaService {

    private final ProdutoDao produtoDao;
    private final VendaDao vendaDao;
    private final ClienteDao clienteDao;
    private final KimonoService kimonoService;
    private final FaixaService faixaService;
    private final BermudaService bermudaService;
    private final Rash_GuardService rash_GuardService;

    public VendaService(VendaDao vendaDao, ClienteDao clienteDao, ProdutoDao produtoDao,
            KimonoService kimonoService, FaixaService faixaService, BermudaService bermudaService,
            Rash_GuardService rash_GuardService) {
        this.vendaDao = vendaDao;
        this.clienteDao = clienteDao;
        this.produtoDao = produtoDao;
        this.kimonoService = kimonoService;
        this.faixaService = faixaService;
        this.bermudaService = bermudaService;
        this.rash_GuardService = rash_GuardService;
    }

    public Venda getById(int idVenda) {
        // Recupera a Pessoa associada ao ID
        Venda venda = vendaDao.findById(idVenda);
        venda.setCliente(clienteDao.findByCpf(venda.getCpf()));

        Produto aux = produtoDao.findBySKU(venda.getSKU());
        String tipoProduto = produtoDao.searchTipoProduto(aux.getIdProduto());
        Produto produto;

        switch (tipoProduto) {
            case "Kimono":
                produto = kimonoService.getById(aux.getIdProduto());
                break;
            case "Faixa":
                produto = faixaService.getById(aux.getIdProduto());
                break;
            case "Bermuda":
                produto = bermudaService.getById(aux.getIdProduto());
                break;
            case "Rash_Guard":
                produto = rash_GuardService.getById(aux.getIdProduto());
                break;
            default:
                throw new IllegalStateException("Tipo de produto desconhecido: " + tipoProduto);
        }

        venda.setProduto(produto);
        return venda;
    }

    public List<Venda> getAll() {
        List<Venda> vendas = vendaDao.findAll();

        for (Venda aux : vendas) {
            aux.setCliente(clienteDao.findByCpf(aux.getCpf()));
            Produto produtoAux = produtoDao.findBySKU(aux.getSKU());
            String tipoProduto = produtoDao.searchTipoProduto(produtoAux.getIdProduto());
            Produto produto;

            switch (tipoProduto) {
                case "Kimono":
                    produto = kimonoService.getById(produtoAux.getIdProduto());
                    break;
                case "Faixa":
                    produto = faixaService.getById(produtoAux.getIdProduto());
                    break;
                case "Bermuda":
                    produto = bermudaService.getById(produtoAux.getIdProduto());
                    break;
                case "Rash_Guard":
                    produto = rash_GuardService.getById(produtoAux.getIdProduto());
                    break;
                default:
                    throw new IllegalStateException("Tipo de produto desconhecido: " + tipoProduto);
            }

            aux.setProduto(produto);
        }

        return vendas;
    }

    @Transactional
    public void insert(Venda venda) throws Exception {
        vendaDao.insert(venda);
    }

    public void update(Venda Venda) throws Exception {
        vendaDao.update(Venda);
    }

    public void delete(int idVenda) {
        vendaDao.delete(idVenda);
    }

    public List<Venda> buscarVendasPorFaixa(Pesquisa pesquisa) {
        List<Venda> vendas = vendaDao.searchVendas(pesquisa);

        for (Venda aux : vendas) {
            aux.setCliente(clienteDao.findByCpf(aux.getCpf()));
            Produto produtoAux = produtoDao.findBySKU(aux.getSKU());
            String tipoProduto = produtoDao.searchTipoProduto(produtoAux.getIdProduto());
            Produto produto;

            switch (tipoProduto) {
                case "Kimono":
                    produto = kimonoService.getById(produtoAux.getIdProduto());
                    break;
                case "Faixa":
                    produto = faixaService.getById(produtoAux.getIdProduto());
                    break;
                case "Bermuda":
                    produto = bermudaService.getById(produtoAux.getIdProduto());
                    break;
                case "Rash_Guard":
                    produto = rash_GuardService.getById(produtoAux.getIdProduto());
                    break;
                default:
                    throw new IllegalStateException("Tipo de produto desconhecido: " + tipoProduto);
            }

            aux.setProduto(produto);
        }

        return vendas;
    }
}