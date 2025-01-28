package com.inf_112.trabalho_final.model;

import java.sql.Date;

import lombok.Data;

@Data
public class Venda {
    public enum Satisfacao {
        MUITO_RUIM, RUIM, REGULAR, BOM, MUITO_BOM
    }

    public enum Ajuste {
        JUSTO, LEVEMENTE_JUSTO, BOM, LEVEMENTE_FOLGADO, FOLGADO
    }
   
    private int idVenda;
    private String cpf;
    private Cliente cliente;

    private String SKU;
    private Produto produto;

    private Date dataVenda;
    private Satisfacao satisfacao;
    private Ajuste ajuste;
}