package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.FuncionarioDao;
import com.inf_112.trabalho_final.dao.PessoaDao;
import com.inf_112.trabalho_final.model.Funcionario;
import com.inf_112.trabalho_final.model.Pessoa;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class FuncionarioService {

    private final FuncionarioDao funcionarioDao;
    private final PessoaDao pessoaDao;

    public FuncionarioService(FuncionarioDao funcionarioDao, PessoaDao pessoaDao) {
        this.funcionarioDao = funcionarioDao;
        this.pessoaDao = pessoaDao;
    }

    public Funcionario getById(int id) {
        // Recupera a Pessoa associada ao ID
        Pessoa pessoa = pessoaDao.findById(id);

        if (pessoa == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        System.out.println(pessoa.toString());

        Funcionario funcionario = funcionarioDao.findById(id);

        if (funcionario == null){
            return null;
        }

        funcionario.setIdPessoa(pessoa.getIdPessoa());
        funcionario.setNome(pessoa.getNome());
        funcionario.setNascimento(pessoa.getNascimento());
        funcionario.setTelefone(pessoa.getTelefone());
        funcionario.setCpf(pessoa.getCpf());
        funcionario.setIdade(pessoa.getIdade());
        funcionario.setSexo(pessoa.getSexo());
        System.out.println(funcionario.toString());

        return funcionario;
    }

    public List<Funcionario> getAll() {
        List<Funcionario> funcionarios = funcionarioDao.findAll();

        for (Funcionario aux : funcionarios) {
            Pessoa pessoa = pessoaDao.findById(aux.getIdPessoa());

            if (pessoa != null) {
                aux.setIdPessoa(pessoa.getIdPessoa());
                aux.setNome(pessoa.getNome());
                aux.setNascimento(pessoa.getNascimento());
                aux.setTelefone(pessoa.getTelefone());
                aux.setCpf(pessoa.getCpf());
                aux.setIdade(pessoa.getIdade());
                aux.setSexo(pessoa.getSexo());
            }
        }

        return funcionarios;
    }

    @Transactional
    public void insert(Funcionario funcionario) throws Exception {
        // Salva a parte de Pessoa
        Pessoa pessoaSalva = pessoaDao.insert(funcionario);

        // Salva os dados específicos de FUNCIONARIO (implementação separada)
        funcionario.setIdPessoa(pessoaSalva.getIdPessoa());
        funcionario.setEmailEncrypted(funcionario.getEmail());
        funcionario.setHashedSenha(funcionario.getSenha());

        funcionarioDao.insert(funcionario);
    }

    public void update(Funcionario funcionario) throws Exception {
        // atualiza os dados da pessoa
        pessoaDao.update(funcionario);

        // atualiza os dados do funcionario
        funcionario.setEmailEncrypted(funcionario.getEmail());
        funcionario.setHashedSenha(funcionario.getSenha());
        funcionarioDao.update(funcionario);
    }

    public void delete(int id) {
        funcionarioDao.delete(id);
        pessoaDao.delete(id);
    }
}
