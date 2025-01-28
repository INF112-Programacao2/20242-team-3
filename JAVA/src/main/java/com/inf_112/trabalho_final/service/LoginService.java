package com.inf_112.trabalho_final.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.inf_112.trabalho_final.dao.FuncionarioDao;
import com.inf_112.trabalho_final.dao.PessoaDao;
import com.inf_112.trabalho_final.interfaces.*;
import com.inf_112.trabalho_final.model.Funcionario;
import com.inf_112.trabalho_final.model.Pessoa;
import com.inf_112.trabalho_final.util.EncryptionUtil;;

@Service
public class LoginService implements Login {

    @Autowired
    private FuncionarioDao funcionarioDao;

    @Autowired
    private PessoaDao pessoaDao;

    @Override
    public Funcionario fazerLogin(String email, String senha) throws Exception {
        // Busca o funcionário pelo email criptografado
        Funcionario funcionario = funcionarioDao.findByEmail(EncryptionUtil.encrypt(email));

        if (funcionario == null) {
            return null; // Email não encontrado
        }

        // Verifica a senha
        if (!funcionario.verificarSenha(senha)) {
            return null; // Senha incorreta
        }

        Pessoa pessoa = pessoaDao.findById(funcionario.getIdPessoa());

        if (pessoa != null) {
            funcionario.setIdPessoa(pessoa.getIdPessoa());
            funcionario.setNome(pessoa.getNome());
            funcionario.setNascimento(pessoa.getNascimento());
            funcionario.setTelefone(pessoa.getTelefone());
            funcionario.setCpf(pessoa.getCpf());
            funcionario.setIdade(pessoa.getIdade());
            funcionario.setSexo(pessoa.getSexo());
        }

        return funcionario; // Retorna o funcionário se login for bem-sucedido
    }
}
