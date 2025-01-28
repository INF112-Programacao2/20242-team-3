package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.TamanhoDao;
import com.inf_112.trabalho_final.model.Tamanho;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class TamanhoService {

    private final TamanhoDao TamanhoDao;

    public TamanhoService(TamanhoDao TamanhoDao) {
        this.TamanhoDao = TamanhoDao;
    }

    public Tamanho getById(int id) {
        return TamanhoDao.findById(id);
    }

    public List<Tamanho> getAll() {
        return TamanhoDao.findAll();
    }

    public List<Tamanho> getAllByTipoProduto(String tipoProduto) {
        return TamanhoDao.findAllByTipoProduto(tipoProduto);
    }

    public void insert(Tamanho Tamanho) {
        TamanhoDao.insert(Tamanho);
    }

    public void update(Tamanho Tamanho) {
        TamanhoDao.update(Tamanho);
    }

    public void delete(int id) {
        TamanhoDao.delete(id);
    }
}
