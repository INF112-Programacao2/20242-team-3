package com.inf_112.trabalho_final.model;

import lombok.Data;

@Data
public class Produto {
    public enum Sexo {
        MASCULINO, FEMININO, UNISSEX
    }

    public enum FaixaEtaria {
        ADULTO, INFANTIL, JUVENIL
    }

    protected int idProduto;

    protected int idMarca;
    protected Marca marca;

    protected int idModelo;
    protected Modelo modelo;

    protected String SKU;
    protected FaixaEtaria faixaEtaria;
    
    protected int idTamanho;
    protected Tamanho tamanho;

    protected Sexo sexo;
    
    protected int idCor;
    protected Cor cor;
}
