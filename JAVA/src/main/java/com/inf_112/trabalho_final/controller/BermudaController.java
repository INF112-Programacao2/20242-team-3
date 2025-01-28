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

import com.inf_112.trabalho_final.model.Bermuda;
import com.inf_112.trabalho_final.service.BermudaService;

@RestController
@RequestMapping("/armor/produtos/bermuda")
@CrossOrigin(origins = "*")
public class BermudaController {

    private final BermudaService bermudaService;

    public BermudaController(BermudaService bermudaService) {
        this.bermudaService = bermudaService;
    }

    @GetMapping({ "/", "" })
    public List<Bermuda> getAllBermudas() {
        return bermudaService.getAll();
    }

    @GetMapping("/{idBermuda}")
    public Bermuda getBermudaById(@PathVariable("idBermuda") int idBermuda) {
        return bermudaService.getById(idBermuda);
    }

    @PostMapping({ "", "/" })
    public Bermuda createBermuda(@RequestBody Bermuda bermuda) {
        try {
            bermudaService.insert(bermuda);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return bermuda;
    }

    @PutMapping({ "", "/" })
    public Bermuda updateBermuda(@RequestBody Bermuda bermuda) {
        try {
            bermudaService.update(bermuda);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return bermuda;
    }

    @DeleteMapping("/{idBermuda}")
    public Bermuda deleteBermuda(@PathVariable("idBermuda") int idBermuda) {
        Bermuda bermuda = bermudaService.getById(idBermuda);
        if (bermuda == null) {
            throw new RuntimeException("Nao existe Bermuda com este id para ser excluido....");
        }
        bermudaService.delete(idBermuda);
        return bermuda;
    }
}