package com.inf_112.trabalho_final.model;

import com.inf_112.trabalho_final.util.EncryptionUtil;
import com.inf_112.trabalho_final.util.PasswordUtil;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)

// class Funcionario : public Pessoa {}

public class Funcionario extends Pessoa {
    private String email;
    private String senha;

    public void setEmailEncrypted(String email) throws Exception {
        this.email = EncryptionUtil.encrypt(email);
    }

    public String getEmailDecrypted() throws Exception {
        return EncryptionUtil.decrypt(this.email);
    }

    public void setHashedSenha(String senha) {
        this.senha = PasswordUtil.hashPassword(senha);
    }

    public boolean verificarSenha(String senha) {
        return PasswordUtil.checkPassword(senha, this.senha);
    }
}
