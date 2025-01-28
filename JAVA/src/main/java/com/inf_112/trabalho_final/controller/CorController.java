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

import com.inf_112.trabalho_final.model.Cor;
import com.inf_112.trabalho_final.service.CorService;

@RestController
@RequestMapping("/armor/cor")
@CrossOrigin(origins = "*")
public class CorController {

    private final CorService corService;

    public CorController(CorService CorService) {
        this.corService = CorService;
    }

    @GetMapping({ "/", "" })
    public List<Cor> getAllCores() {
        return corService.getAll();
    }

    @GetMapping("/{idCor}")
    public Cor getCorById(@PathVariable("idCor") int idCor) {
        return corService.getById(idCor);
    }

    @PostMapping({ "", "/" })
    public Cor createCor(@RequestBody Cor cor) {
        corService.insert(cor);
        return cor;
    }

    @PutMapping({ "", "/" })
    public Cor updateCor(@RequestBody Cor cor) {
        corService.update(cor);
        return cor;
    }

    @DeleteMapping("/{idCor}")
    public Cor deleteCor(@PathVariable("idCor") int idCor) {
        Cor Cor = corService.getById(idCor);
        if (Cor == null) {
            throw new RuntimeException("Nao existe Cor com este id para ser excluido....");
        }
        corService.delete(idCor);
        return Cor;
    }
}