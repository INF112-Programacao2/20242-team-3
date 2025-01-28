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

import com.inf_112.trabalho_final.model.Cliente;
import com.inf_112.trabalho_final.service.ClienteService;

@RestController
@RequestMapping("/armor/cliente")
@CrossOrigin(origins = "*")
public class ClienteController {

    private final ClienteService clienteService;

    public ClienteController(ClienteService clienteService) {
        this.clienteService = clienteService;
    }

    @GetMapping({ "/", "" })
    public List<Cliente> getAllClientees() {
        return clienteService.getAll();
    }

    @GetMapping("/{idCliente}")
    public Cliente getClienteById(@PathVariable("idCliente") int idCliente) {

        return clienteService.getById(idCliente);
    }

    @PostMapping({ "", "/" })
    public Cliente createCliente(@RequestBody Cliente cliente) {
        try {
            clienteService.insert(cliente);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return cliente;
    }

    @PutMapping({ "", "/" })
    public Cliente updateCliente(@RequestBody Cliente cliente) {
        try {
            clienteService.update(cliente);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return cliente;
    }

    @DeleteMapping("/{idCliente}")
    public Cliente deleteCliente(@PathVariable("idCliente") int idCliente) {
        Cliente Cliente = clienteService.getById(idCliente);
        if (Cliente == null) {
            throw new RuntimeException("Nao existe Cliente com este id para ser excluido....");
        }
        clienteService.delete(idCliente);
        return Cliente;
    }
}