package com.inf_112.trabalho_final.model;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
public class Faixa extends Produto {
    public enum Espessura {
        CLASSICA, ROBUSTA
    }
    
    private Espessura espessura;
}
