package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.CorDao;
import com.inf_112.trabalho_final.dao.BermudaDao;
import com.inf_112.trabalho_final.dao.MarcaDao;
import com.inf_112.trabalho_final.dao.ModeloDao;
import com.inf_112.trabalho_final.dao.ProdutoDao;
import com.inf_112.trabalho_final.dao.TamanhoDao;
import com.inf_112.trabalho_final.model.Bermuda;
import com.inf_112.trabalho_final.model.Produto;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class BermudaService {

    private final BermudaDao bermudaDao;
    private final ProdutoDao produtoDao;
    private final MarcaDao marcaDao;
    private final ModeloDao modeloDao;
    private final TamanhoDao tamanhoDao;
    private final CorDao corDao;

    public BermudaService(BermudaDao bermudaDao, ProdutoDao produtoDao, MarcaDao marcaDao,
            ModeloDao modeloDao, TamanhoDao tamanhoDao, CorDao corDao) {
        this.bermudaDao = bermudaDao;
        this.produtoDao = produtoDao;
        this.marcaDao = marcaDao;
        this.modeloDao = modeloDao;
        this.tamanhoDao = tamanhoDao;
        this.corDao = corDao;
    }

    public Bermuda getById(int idProduto) {
        // Recupera a Pessoa associada ao ID
        Produto produto = produtoDao.findById(idProduto);

        if (produto == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        Bermuda bermuda = bermudaDao.findById(idProduto);

        if (bermuda == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        bermuda.setIdProduto(produto.getIdProduto());

        bermuda.setIdMarca(produto.getIdMarca());
        bermuda.setMarca(marcaDao.findById(bermuda.getIdMarca()));

        bermuda.setIdModelo(produto.getIdModelo());
        bermuda.setModelo(modeloDao.findById(bermuda.getIdModelo()));

        bermuda.setSKU(produto.getSKU());

        bermuda.setFaixaEtaria(produto.getFaixaEtaria());

        bermuda.setIdTamanho(produto.getIdTamanho());
        bermuda.setTamanho(tamanhoDao.findById(bermuda.getIdTamanho()));

        bermuda.setSexo(produto.getSexo());

        bermuda.setIdCor(produto.getIdCor());
        bermuda.setCor(corDao.findById(bermuda.getIdCor()));

        System.out.println(bermuda.toString());

        return bermuda;
    }

    public List<Bermuda> getAll() {
        List<Bermuda> Bermudas = bermudaDao.findAll();

        for (Bermuda aux : Bermudas) {
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

        return Bermudas;
    }

    @Transactional
    public void insert(Bermuda Bermuda) throws Exception {
        // Salva a parte de Pessoa

        Produto produtoSalvo = produtoDao.insert(Bermuda);

        // Salva os dados específicos de Bermuda (implementação separada)
        Bermuda.setIdProduto(produtoSalvo.getIdProduto());
        bermudaDao.insert(Bermuda);
    }

    public void update(Bermuda Bermuda) throws Exception {
        // atualiza os dados da pessoa
        produtoDao.update(Bermuda);

        // atualiza os dados do Bermuda
        bermudaDao.update(Bermuda);
    }

    public void delete(int idProduto) {
        bermudaDao.delete(idProduto);
        produtoDao.delete(idProduto);
    }
}
