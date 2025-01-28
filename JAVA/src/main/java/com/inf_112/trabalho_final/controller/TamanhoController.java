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

import com.inf_112.trabalho_final.model.Tamanho;
import com.inf_112.trabalho_final.service.TamanhoService;

@RestController
@RequestMapping("/armor/tamanho")
@CrossOrigin(origins = "*")
public class TamanhoController {

    private final TamanhoService TamanhoService;

    public TamanhoController(TamanhoService TamanhoService) {
        this.TamanhoService = TamanhoService;
    }

    @GetMapping({ "/", "" })
    public List<Tamanho> getAllTamanhos() {
        return TamanhoService.getAll();
    }

    @GetMapping("/{idTamanho}")
    public Tamanho getTamanhoById(@PathVariable("idTamanho") int idTamanho) {
        return TamanhoService.getById(idTamanho);
    }

    @GetMapping("/tipo-produto/{tipoProduto}")
    public  List<Tamanho> getAllByTipoProduto(@PathVariable("tipoProduto") String tipoProduto) {
        return TamanhoService.getAllByTipoProduto(tipoProduto);
    }

    @PostMapping({ "", "/" })
    public Tamanho createTamanho(@RequestBody Tamanho Tamanho) {
        TamanhoService.insert(Tamanho);
        return Tamanho;
    }

    @PutMapping({ "", "/" })
    public Tamanho updateTamanho(@RequestBody Tamanho Tamanho) {
        TamanhoService.update(Tamanho);
        return Tamanho;
    }

    @DeleteMapping("/{idTamanho}")
    public Tamanho deleteTamanho(@PathVariable("idTamanho") int idTamanho) {
        Tamanho Tamanho = TamanhoService.getById(idTamanho);
        if (Tamanho == null) {
            throw new RuntimeException("Nao existe Tamanho com este id para ser excluido....");
        }
        
        TamanhoService.delete(idTamanho);
        return Tamanho;
    }
}