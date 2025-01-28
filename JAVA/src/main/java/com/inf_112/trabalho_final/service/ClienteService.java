package com.inf_112.trabalho_final.service;

import com.inf_112.trabalho_final.dao.ClienteDao;
import com.inf_112.trabalho_final.dao.PessoaDao;
import com.inf_112.trabalho_final.model.Cliente;
import com.inf_112.trabalho_final.model.Pessoa;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
public class ClienteService {

    private final ClienteDao clienteDao;
    private final PessoaDao pessoaDao;

    public ClienteService(ClienteDao clienteDao, PessoaDao pessoaDao) {
        this.clienteDao = clienteDao;
        this.pessoaDao = pessoaDao;
    }

    public Cliente getById(int id) {
        // Recupera a Pessoa associada ao ID
        Pessoa pessoa = pessoaDao.findById(id);

        if (pessoa == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        System.out.println(pessoa.toString());

        Cliente cliente = clienteDao.findById(id);

        if (cliente == null) {
            return null; // Ou lance uma exceção, se desejar
        }

        cliente.setIdPessoa(pessoa.getIdPessoa());
        cliente.setNome(pessoa.getNome());
        cliente.setNascimento(pessoa.getNascimento());
        cliente.setTelefone(pessoa.getTelefone());
        cliente.setCpf(pessoa.getCpf());
        cliente.setIdade(pessoa.getIdade());
        cliente.setSexo(pessoa.getSexo());
        System.out.println(cliente.toString());

        return cliente;
    }

    public List<Cliente> getAll() {
        List<Cliente> clientes = clienteDao.findAll();

        for (Cliente aux : clientes) {
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

        return clientes;
    }

    @Transactional
    public void insert(Cliente cliente) throws Exception {
        // Salva a parte de Pessoa

        Pessoa pessoaSalva = pessoaDao.insert(cliente);

        // Salva os dados específicos de Cliente (implementação separada)
        cliente.setIdPessoa(pessoaSalva.getIdPessoa());
        clienteDao.insert(cliente);
    }

    public void update(Cliente cliente) throws Exception {
        // atualiza os dados da pessoa
        pessoaDao.update(cliente);

        // atualiza os dados do Cliente
        clienteDao.update(cliente);
    }

    public void delete(int id) {
        clienteDao.delete(id);
        pessoaDao.delete(id);
    }
}
