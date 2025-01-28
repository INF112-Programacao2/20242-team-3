package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.ModeloDao;
import com.inf_112.trabalho_final.model.Modelo;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ModeloService {

    private final ModeloDao ModeloDao;

    public ModeloService(ModeloDao ModeloDao) {
        this.ModeloDao = ModeloDao;
    }

    public Modelo getById(int id) {
        return ModeloDao.findById(id);
    }

    public List<Modelo> getAll() {
        return ModeloDao.findAll();
    }

    public List<Modelo> getAllByMarca(int idMarca) {
        return ModeloDao.findAllByMarca(idMarca);
    }

    public void insert(Modelo Modelo) {
        ModeloDao.insert(Modelo);
    }

    public void update(Modelo Modelo) {
        ModeloDao.update(Modelo);
    }

    public void delete(int id) {
        ModeloDao.delete(id);
    }
}
