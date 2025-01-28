package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.CorDao;
import com.inf_112.trabalho_final.dao.KimonoDao;
import com.inf_112.trabalho_final.dao.MarcaDao;
import com.inf_112.trabalho_final.dao.ModeloDao;
import com.inf_112.trabalho_final.dao.ProdutoDao;
import com.inf_112.trabalho_final.dao.TamanhoDao;
import com.inf_112.trabalho_final.model.Kimono;
import com.inf_112.trabalho_final.model.Produto;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class KimonoService {

    private final KimonoDao kimonoDao;
    private final ProdutoDao produtoDao;
    private final MarcaDao marcaDao;
    private final ModeloDao modeloDao;
    private final TamanhoDao tamanhoDao;
    private final CorDao corDao;

    public KimonoService(KimonoDao kimonoDao, ProdutoDao produtoDao, MarcaDao marcaDao,
            ModeloDao modeloDao, TamanhoDao tamanhoDao, CorDao corDao) {
        this.kimonoDao = kimonoDao;
        this.produtoDao = produtoDao;
        this.marcaDao = marcaDao;
        this.modeloDao = modeloDao;
        this.tamanhoDao = tamanhoDao;
        this.corDao = corDao;
    }

    public Kimono getById(int idProduto) {
        // Recupera a Pessoa associada ao ID
        Produto produto = produtoDao.findById(idProduto);

        if (produto == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        Kimono kimono = kimonoDao.findById(idProduto);

        if (kimono == null){
            return null;
        }

        kimono.setIdProduto(produto.getIdProduto());

        kimono.setIdMarca(produto.getIdMarca());
        kimono.setMarca(marcaDao.findById(kimono.getIdMarca()));

        kimono.setIdModelo(produto.getIdModelo());
        kimono.setModelo(modeloDao.findById(kimono.getIdModelo()));

        kimono.setSKU(produto.getSKU());

        kimono.setFaixaEtaria(produto.getFaixaEtaria());

        kimono.setIdTamanho(produto.getIdTamanho());
        kimono.setTamanho(tamanhoDao.findById(kimono.getIdTamanho()));

        kimono.setSexo(produto.getSexo());

        kimono.setIdCor(produto.getIdCor());
        kimono.setCor(corDao.findById(kimono.getIdCor()));

        System.out.println(kimono.toString());

        return kimono;
    }

    public List<Kimono> getAll() {
        List<Kimono> kimonos = kimonoDao.findAll();

        for (Kimono aux : kimonos) {
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

        return kimonos;
    }

    @Transactional
    public void insert(Kimono kimono) throws Exception {
        // Salva a parte de Pessoa

        Produto produtoSalvo = produtoDao.insert(kimono);

        // Salva os dados específicos de Kimono (implementação separada)
        kimono.setIdProduto(produtoSalvo.getIdProduto());
        kimonoDao.insert(kimono);
    }

    public void update(Kimono Kimono) throws Exception {
        // atualiza os dados da pessoa
        produtoDao.update(Kimono);

        // atualiza os dados do Kimono
        kimonoDao.update(Kimono);
    }

    public void delete(int idProduto) {
        kimonoDao.delete(idProduto);
        produtoDao.delete(idProduto);
    }
}
