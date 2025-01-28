package com.inf_112.trabalho_final.controller;


import java.util.List;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.inf_112.trabalho_final.model.Modelo;
import com.inf_112.trabalho_final.service.ModeloService;

@RestController
@RequestMapping("/armor/modelo")
@CrossOrigin(origins = "*")
public class ModeloController {

    private final ModeloService ModeloService;

    public ModeloController(ModeloService ModeloService) {
        this.ModeloService = ModeloService;
    }

    @GetMapping({ "/", "" })
    public List<Modelo> getAllModelos() {
        return ModeloService.getAll();
    }

    @GetMapping("/{idModelo}")
    public Modelo getModeloById(@PathVariable("idModelo") int idModelo) {
        return ModeloService.getById(idModelo);
    }

    @GetMapping("/marca/{idMarca}")
    public  List<Modelo> getAllModelosByMarca(@PathVariable("idMarca") int idMarca) {
        return ModeloService.getAllByMarca(idMarca);
    }

    @PostMapping({ "", "/" })
    public Modelo createModelo(@RequestBody Modelo Modelo) {
        ModeloService.insert(Modelo);
        return Modelo;
    }

    @PutMapping({ "", "/" })
    public Modelo updateModelo(@RequestBody Modelo Modelo) {
        ModeloService.update(Modelo);
        return Modelo;
    }

    @DeleteMapping("/{idModelo}")
    public Modelo deleteModelo(@PathVariable("idModelo") int idModelo) {
        Modelo Modelo = ModeloService.getById(idModelo);
        if (Modelo == null) {
            throw new RuntimeException("Nao existe Modelo com este id para ser excluido....");
        }
        ModeloService.delete(idModelo);
        return Modelo;
    }
}