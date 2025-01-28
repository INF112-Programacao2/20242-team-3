package com.inf_112.trabalho_final.model;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
public class Kimono extends Produto {
    public enum Forma {
        TRADICIONAL, SLIM, ULTRASLIM
    }
   
    private double gramaturaTecido;
    private int encolhimento;
    private Forma forma;
}
