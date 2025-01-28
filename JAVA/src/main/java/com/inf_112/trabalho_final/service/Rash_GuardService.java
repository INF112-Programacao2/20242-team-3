package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.CorDao;
import com.inf_112.trabalho_final.dao.Rash_GuardDao;
import com.inf_112.trabalho_final.dao.MarcaDao;
import com.inf_112.trabalho_final.dao.ModeloDao;
import com.inf_112.trabalho_final.dao.ProdutoDao;
import com.inf_112.trabalho_final.dao.TamanhoDao;
import com.inf_112.trabalho_final.model.Rash_Guard;
import com.inf_112.trabalho_final.model.Produto;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class Rash_GuardService {

    private final Rash_GuardDao rash_GuardDao;
    private final ProdutoDao produtoDao;
    private final MarcaDao marcaDao;
    private final ModeloDao modeloDao;
    private final TamanhoDao tamanhoDao;
    private final CorDao corDao;

    public Rash_GuardService(Rash_GuardDao rash_GuardDao, ProdutoDao produtoDao, MarcaDao marcaDao,
            ModeloDao modeloDao, TamanhoDao tamanhoDao, CorDao corDao) {
        this.rash_GuardDao = rash_GuardDao;
        this.produtoDao = produtoDao;
        this.marcaDao = marcaDao;
        this.modeloDao = modeloDao;
        this.tamanhoDao = tamanhoDao;
        this.corDao = corDao;
    }

    public Rash_Guard getById(int idProduto) {
        // Recupera a Pessoa associada ao ID
        Produto produto = produtoDao.findById(idProduto);

        if (produto == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        Rash_Guard rash_Guard = rash_GuardDao.findById(idProduto);

        if (rash_Guard == null){
            return null;
        }

        rash_Guard.setIdProduto(produto.getIdProduto());

        rash_Guard.setIdMarca(produto.getIdMarca());
        rash_Guard.setMarca(marcaDao.findById(rash_Guard.getIdMarca()));

        rash_Guard.setIdModelo(produto.getIdModelo());
        rash_Guard.setModelo(modeloDao.findById(rash_Guard.getIdModelo()));

        rash_Guard.setSKU(produto.getSKU());

        rash_Guard.setFaixaEtaria(produto.getFaixaEtaria());

        rash_Guard.setIdTamanho(produto.getIdTamanho());
        rash_Guard.setTamanho(tamanhoDao.findById(rash_Guard.getIdTamanho()));

        rash_Guard.setSexo(produto.getSexo());

        rash_Guard.setIdCor(produto.getIdCor());
        rash_Guard.setCor(corDao.findById(rash_Guard.getIdCor()));

        System.out.println(rash_Guard.toString());

        return rash_Guard;
    }

    public List<Rash_Guard> getAll() {
        List<Rash_Guard> rash_Guards = rash_GuardDao.findAll();

        for (Rash_Guard aux : rash_Guards) {
            Produto produto = produtoDao.findById(aux.getIdProduto());

            if (produto != null) {
                aux.setIdProduto(produto.getIdProduto());

                aux.setIdMarca(produto.getIdMarca());
                aux.setMarca(marcaDao.findById(aux.getIdMarca()));

                aux.setIdModelo(produto.getIdModelo());
                aux.setModelo(modeloDao.findById(aux.getIdModelo()));

                aux.setSKU(produto.getSKU());

                aux.setFaixaEtaria(produto.getFaixaEtaria());

                aux.setIdTamanho(produto.getIdTamanho());
                aux.setTamanho(tamanhoDao.findById(aux.getIdTamanho()));

                aux.setSexo(produto.getSexo());

                aux.setIdCor(produto.getIdCor());
                aux.setCor(corDao.findById(aux.getIdCor()));
            }
        }

        return rash_Guards;
    }

    @Transactional
    public void insert(Rash_Guard rash_Guard) throws Exception {
        // Salva a parte de Pessoa

        Produto produtoSalvo = produtoDao.insert(rash_Guard);

        // Salva os dados específicos de Rash_Guard (implementação separada)
        rash_Guard.setIdProduto(produtoSalvo.getIdProduto());
        rash_GuardDao.insert(rash_Guard);
    }

    public void update(Rash_Guard rash_Guard) throws Exception {
        // atualiza os dados da pessoa
        produtoDao.update(rash_Guard);

        // atualiza os dados do Rash_Guard
        rash_GuardDao.update(rash_Guard);
    }

    public void delete(int idProduto) {
        rash_GuardDao.delete(idProduto);
        produtoDao.delete(idProduto);
    }
}
