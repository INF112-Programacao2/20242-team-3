package com.inf_112.trabalho_final.model;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
public class Cliente extends Pessoa {
    private double envergadura;
    private double peso;
    private double altura;
    private double torax;
    private double cintura;
}