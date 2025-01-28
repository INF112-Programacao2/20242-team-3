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

import com.inf_112.trabalho_final.model.Marca;
import com.inf_112.trabalho_final.service.MarcaService;

@RestController
@RequestMapping("/armor/marca")
@CrossOrigin(origins = "*")
public class MarcaController {

    private final MarcaService MarcaService;

    public MarcaController(MarcaService MarcaService) {
        this.MarcaService = MarcaService;
    }

    @GetMapping({ "/", "" })
    public List<Marca> getAllMarcaes() {
        return MarcaService.getAll();
    }

    @GetMapping("/{idMarca}")
    public Marca getMarcaById(@PathVariable("idMarca") int idMarca) {
        return MarcaService.getById(idMarca);
    }

    @PostMapping({ "", "/" })
    public Marca createMarca(@RequestBody Marca Marca) {
        MarcaService.insert(Marca);
        return Marca;
    }

    @PutMapping({ "", "/" })
    public Marca updateMarca(@RequestBody Marca Marca) {
        MarcaService.update(Marca);
        return Marca;
    }

    @DeleteMapping("/{idMarca}")
    public Marca deleteMarca(@PathVariable("idMarca") int idMarca) {
        Marca Marca = MarcaService.getById(idMarca);
        if (Marca == null) {
            throw new RuntimeException("Nao existe Marca com este id para ser excluido....");
        }
        MarcaService.delete(idMarca);
        return Marca;
    }
}