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

import com.inf_112.trabalho_final.model.Funcionario;
import com.inf_112.trabalho_final.service.FuncionarioService;

@RestController
@RequestMapping("/armor/funcionario")
@CrossOrigin(origins = "*")
public class FuncionarioController {

    private final FuncionarioService funcionarioService;

    public FuncionarioController(FuncionarioService funcionarioService) {
        this.funcionarioService = funcionarioService;
    }

    @GetMapping({ "/", "" })
    public List<Funcionario> getAllFuncionarios() {
        return funcionarioService.getAll();
    }

    @GetMapping("/{idFuncionario}")
    public Funcionario getFuncionarioById(@PathVariable("idFuncionario") int idFuncionario) {
        return funcionarioService.getById(idFuncionario);
    }

    @PostMapping({ "", "/" })
    public Funcionario createFuncionario(@RequestBody Funcionario funcionario) {
        try {
            funcionarioService.insert(funcionario);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return funcionario;
    }

    @PutMapping({ "", "/" })
    public Funcionario updateFuncionario(@RequestBody Funcionario Funcionario) {
        try {
            funcionarioService.update(Funcionario);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return Funcionario;
    }

    @DeleteMapping("/{idFuncionario}")
    public Funcionario deleteFuncionario(@PathVariable("idFuncionario") int idFuncionario) {
        Funcionario Funcionario = funcionarioService.getById(idFuncionario);
        if (Funcionario == null) {
            throw new RuntimeException("Nao existe Funcionario com este id para ser excluido....");
        }
        funcionarioService.delete(idFuncionario);
        return Funcionario;
    }
}