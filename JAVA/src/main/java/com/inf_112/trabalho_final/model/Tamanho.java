package com.inf_112.trabalho_final.model;

import lombok.Data;

@Data
public class Tamanho {
    public enum TipoProduto {
        BERMUDA, FAIXA, KIMONO, RASH_GUARD
    }
   
    private int idTamanho;
    private TipoProduto tipoProduto;
    private String nome;
}
