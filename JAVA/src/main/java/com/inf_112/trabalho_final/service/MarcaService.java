package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.MarcaDao;
import com.inf_112.trabalho_final.model.Marca;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MarcaService {

    private final MarcaDao MarcaDao;

    public MarcaService(MarcaDao MarcaDao) {
        this.MarcaDao = MarcaDao;
    }

    public Marca getById(int id) {
        return MarcaDao.findById(id);
    }

    public List<Marca> getAll() {
        return MarcaDao.findAll();
    }

    public void insert(Marca Marca) {
        MarcaDao.insert(Marca);
    }

    public void update(Marca Marca) {
        MarcaDao.update(Marca);
    }

    public void delete(int id) {
        MarcaDao.delete(id);
    }
}
