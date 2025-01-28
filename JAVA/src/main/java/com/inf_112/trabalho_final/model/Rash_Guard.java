package com.inf_112.trabalho_final.model;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
public class Rash_Guard extends Produto {
    private int fps;
}