package com.inf_112.trabalho_final.model;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
public class Bermuda extends Produto {
    public enum Ajuste {
        ELASTICO, BOTAO, AMARRACAO
    }

    public enum Comprimento {
        CURTO, MEDIO, LONGO
    }

    private Ajuste ajuste;
    private Comprimento comprimento;
}
