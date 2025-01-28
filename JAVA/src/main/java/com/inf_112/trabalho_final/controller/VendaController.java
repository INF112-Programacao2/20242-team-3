package com.inf_112.trabalho_final.controller;

import java.util.List;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.inf_112.trabalho_final.model.Pesquisa;
import com.inf_112.trabalho_final.model.Venda;
import com.inf_112.trabalho_final.service.VendaService;

@RestController
@RequestMapping("/armor/venda")
@CrossOrigin(origins = "*")
public class VendaController {

    private final VendaService vendaService;

    public VendaController(VendaService vendaService) {
        this.vendaService = vendaService;
    }

    @GetMapping({ "/", "" })
    public List<Venda> getAllVendaes() {
        return vendaService.getAll();
    }

    @GetMapping("/{idVenda}")
    public Venda getVendaById(@PathVariable("idVenda") int idVenda) {

        return vendaService.getById(idVenda);
    }

    @PostMapping({ "", "/" })
    public Venda createVenda(@RequestBody Venda venda) {
        try {
            vendaService.insert(venda);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return venda;
    }

    @PutMapping({ "", "/" })
    public Venda updateVenda(@RequestBody Venda venda) {
        try {
            vendaService.update(venda);
        } catch (Exception e) {
            throw new RuntimeException(e.getMessage());
        }

        return venda;
    }

    @DeleteMapping("/{idVenda}")
    public Venda deleteVenda(@PathVariable("idVenda") int idVenda) {
        Venda venda = vendaService.getById(idVenda);
        if (venda == null) {
            throw new RuntimeException("Nao existe Venda com este id para ser excluido....");
        }
        vendaService.delete(idVenda);
        return venda;
    }

    @PostMapping("/pesquisar")
    public ResponseEntity<List<Venda>> buscarVendasPorFaixa(@RequestBody Pesquisa pesquisa) {
        List<Venda> vendas = vendaService.buscarVendasPorFaixa(pesquisa);

        if (vendas.isEmpty()) {
            return ResponseEntity.noContent().build();
        }

        return ResponseEntity.ok(vendas);
    }
}