package com.inf_112.trabalho_final.interfaces;

import com.inf_112.trabalho_final.model.Funcionario;

public interface Login {
    Funcionario fazerLogin(String email, String senha) throws Exception;   
}
