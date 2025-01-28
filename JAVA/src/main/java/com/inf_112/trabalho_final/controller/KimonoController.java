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

import com.inf_112.trabalho_final.model.Kimono;
import com.inf_112.trabalho_final.service.KimonoService;

@RestController
@RequestMapping("/armor/produtos/kimono")
@CrossOrigin(origins = "*")
public class KimonoController {

    private final KimonoService kimonoService;

    public KimonoController(KimonoService kimonoService) {
        this.kimonoService = kimonoService;
    }

    @GetMapping({ "/", "" })
    public List<Kimono> getAllKimonos() {
        return kimonoService.getAll();
    }

    @GetMapping("/{idKimono}")
    public Kimono getKimonoById(@PathVariable("idKimono") int idKimono) {
        return kimonoService.getById(idKimono);
    }

    @PostMapping({ "", "/" })
    public Kimono createKimono(@RequestBody Kimono kimono) {
        try {
            kimonoService.insert(kimono);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return kimono;
    }

    @PutMapping({ "", "/" })
    public Kimono updateKimono(@RequestBody Kimono kimono) {
        try {
            kimonoService.update(kimono);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return kimono;
    }

    @DeleteMapping("/{idKimono}")
    public Kimono deleteKimono(@PathVariable("idKimono") int idKimono) {
        Kimono Kimono = kimonoService.getById(idKimono);
        if (Kimono == null) {
            throw new RuntimeException("Nao existe Kimono com este id para ser excluido....");
        }
        kimonoService.delete(idKimono);
        return Kimono;
    }
}