package com.inf_112.trabalho_final.model;

import java.sql.Date;
import lombok.Data;

@Data
public class Pessoa {
    public enum Sexo {
        MASCULINO, FEMININO
    }

    private int idPessoa;
    private String nome;
    private Date nascimento;
    private String telefone;
    private String cpf;
    private int idade;
    private Sexo sexo;
}
