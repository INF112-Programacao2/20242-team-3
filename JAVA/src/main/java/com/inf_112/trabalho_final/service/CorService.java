package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.CorDao;
import com.inf_112.trabalho_final.model.Cor;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CorService {

    private final CorDao corDao;

    public CorService(CorDao corDao) {
        this.corDao = corDao;
    }

    public Cor getById(int id) {
        return corDao.findById(id);
    }

    public List<Cor> getAll() {
        return corDao.findAll();
    }

    public void insert(Cor cor) {
        corDao.insert(cor);
    }

    public void update(Cor cor) {
        corDao.update(cor);
    }

    public void delete(int id) {
        corDao.delete(id);
    }
}
