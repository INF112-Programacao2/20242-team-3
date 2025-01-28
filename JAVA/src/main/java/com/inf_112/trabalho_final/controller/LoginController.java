package com.inf_112.trabalho_final.controller;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.inf_112.trabalho_final.model.Funcionario;
import com.inf_112.trabalho_final.service.LoginService;

@RestController
@RequestMapping("/armor/login")
@CrossOrigin(origins = "*")
public class LoginController {
    private final LoginService loginService;

    public LoginController(LoginService loginService) {
        this.loginService = loginService;
    }

    @GetMapping("/email/{email}/senha/{senha}")
    public Funcionario fazerLogin(@PathVariable("email") String email, @PathVariable("senha") String senha) {
        try {
            return loginService.fazerLogin(email, senha);
        } catch (Exception e) {
            throw new RuntimeException("Erro: " + e.getMessage());
        }
    }
}