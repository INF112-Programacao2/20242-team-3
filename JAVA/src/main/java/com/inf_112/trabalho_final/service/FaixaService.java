package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.CorDao;
import com.inf_112.trabalho_final.dao.FaixaDao;
import com.inf_112.trabalho_final.dao.MarcaDao;
import com.inf_112.trabalho_final.dao.ModeloDao;
import com.inf_112.trabalho_final.dao.ProdutoDao;
import com.inf_112.trabalho_final.dao.TamanhoDao;
import com.inf_112.trabalho_final.model.Faixa;
import com.inf_112.trabalho_final.model.Produto;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class FaixaService {

    private final FaixaDao faixaDao;
    private final ProdutoDao produtoDao;
    private final MarcaDao marcaDao;
    private final ModeloDao modeloDao;
    private final TamanhoDao tamanhoDao;
    private final CorDao corDao;

    public FaixaService(FaixaDao faixaDao, ProdutoDao produtoDao, MarcaDao marcaDao,
            ModeloDao modeloDao, TamanhoDao tamanhoDao, CorDao corDao) {
        this.faixaDao = faixaDao;
        this.produtoDao = produtoDao;
        this.marcaDao = marcaDao;
        this.modeloDao = modeloDao;
        this.tamanhoDao = tamanhoDao;
        this.corDao = corDao;
    }

    public Faixa getById(int idProduto) {
        // Recupera a Pessoa associada ao ID
        Produto produto = produtoDao.findById(idProduto);

        if (produto == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        Faixa faixa = faixaDao.findById(idProduto);

        if (faixa == null){
            return null;
        }

        faixa.setIdProduto(produto.getIdProduto());

        faixa.setIdMarca(produto.getIdMarca());
        faixa.setMarca(marcaDao.findById(faixa.getIdMarca()));

        faixa.setIdModelo(produto.getIdModelo());
        faixa.setModelo(modeloDao.findById(faixa.getIdModelo()));

        faixa.setSKU(produto.getSKU());

        faixa.setFaixaEtaria(produto.getFaixaEtaria());

        faixa.setIdTamanho(produto.getIdTamanho());
        faixa.setTamanho(tamanhoDao.findById(faixa.getIdTamanho()));

        faixa.setSexo(produto.getSexo());

        faixa.setIdCor(produto.getIdCor());
        faixa.setCor(corDao.findById(faixa.getIdCor()));

        System.out.println(faixa.toString());

        return faixa;
    }

    public List<Faixa> getAll() {
        List<Faixa> faixas = faixaDao.findAll();

        for (Faixa aux : faixas) {
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

        return faixas;
    }

    @Transactional
    public void insert(Faixa faixa) throws Exception {
        // Salva a parte de Pessoa

        Produto produtoSalvo = produtoDao.insert(faixa);

        // Salva os dados específicos de Faixa (implementação separada)
        faixa.setIdProduto(produtoSalvo.getIdProduto());
        faixaDao.insert(faixa);
    }

    public void update(Faixa faixa) throws Exception {
        // atualiza os dados da pessoa
        produtoDao.update(faixa);

        // atualiza os dados do Faixa
        faixaDao.update(faixa);
    }

    public void delete(int idProduto) {
        faixaDao.delete(idProduto);
        produtoDao.delete(idProduto);
    }
}
