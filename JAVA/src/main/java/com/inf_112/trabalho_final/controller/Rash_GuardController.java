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

import com.inf_112.trabalho_final.model.Rash_Guard;
import com.inf_112.trabalho_final.service.Rash_GuardService;

@RestController
@RequestMapping("/armor/produtos/rash_guard")
@CrossOrigin(origins = "*")
public class Rash_GuardController {

    private final Rash_GuardService rash_GuardService;

    public Rash_GuardController(Rash_GuardService rash_GuardService) {
        this.rash_GuardService = rash_GuardService;
    }

    @GetMapping({ "/", "" })
    public List<Rash_Guard> getAllRash_Guards() {
        return rash_GuardService.getAll();
    }

    @GetMapping("/{idRash_Guard}")
    public Rash_Guard getRash_GuardById(@PathVariable("idRash_Guard") int idRash_Guard) {
        return rash_GuardService.getById(idRash_Guard);
    }

    @PostMapping({ "", "/" })
    public Rash_Guard createRash_Guard(@RequestBody Rash_Guard rash_Guard) {
        try {
            rash_GuardService.insert(rash_Guard);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return rash_Guard;
    }

    @PutMapping({ "", "/" })
    public Rash_Guard updateRash_Guard(@RequestBody Rash_Guard rash_Guard) {
        try {
            rash_GuardService.update(rash_Guard);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return rash_Guard;
    }

    @DeleteMapping("/{idRash_Guard}")
    public Rash_Guard deleteRash_Guard(@PathVariable("idRash_Guard") int idRash_Guard) {
        Rash_Guard rash_Guard = rash_GuardService.getById(idRash_Guard);
        if (rash_Guard == null) {
            throw new RuntimeException("Nao existe Rash_Guard com este id para ser excluido....");
        }
        rash_GuardService.delete(idRash_Guard);
        return rash_Guard;
    }
}