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

import com.inf_112.trabalho_final.model.Faixa;
import com.inf_112.trabalho_final.service.FaixaService;

@RestController
@RequestMapping("/armor/produtos/faixa")
@CrossOrigin(origins = "*")
public class FaixaController {

    private final FaixaService faixaService;

    public FaixaController(FaixaService faixaService) {
        this.faixaService = faixaService;
    }

    @GetMapping({ "/", "" })
    public List<Faixa> getAllFaixas() {
        return faixaService.getAll();
    }

    @GetMapping("/{idFaixa}")
    public Faixa getFaixaById(@PathVariable("idFaixa") int idFaixa) {
        return faixaService.getById(idFaixa);
    }

    @PostMapping({ "", "/" })
    public Faixa createFaixa(@RequestBody Faixa faixa) {
        try {
            faixaService.insert(faixa);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return faixa;
    }

    @PutMapping({ "", "/" })
    public Faixa updateFaixa(@RequestBody Faixa faixa) {
        try {
            faixaService.update(faixa);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return faixa;
    }

    @DeleteMapping("/{idFaixa}")
    public Faixa deleteFaixa(@PathVariable("idFaixa") int idFaixa) {
        Faixa Faixa = faixaService.getById(idFaixa);
        if (Faixa == null) {
            throw new RuntimeException("Nao existe Faixa com este id para ser excluido....");
        }
        faixaService.delete(idFaixa);
        return Faixa;
    }
}