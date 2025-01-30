# 20242-team-3

Thulio Marco de Oliveira Fernandes  116223 
Gabriel Valério Silva Barros 116232
Leonardo Peçanha Scala 116217

# Tema do projeto

Sistema de gerenciamento de estoque para empresas fornecedoras de roupas esportivas.

# Sobre o sistema

Através dele, é possível gerenciar o estoque de tipos diferentes de Produtos, como Bermudas e Kimonos. Os comandos são inseridos pelo terminal, e as inserções e edições realizadas ficam salvas em um banco de dados criado em SQLite.

Devido à urgência do trabalho e o curto prazo para solucionar o problema, foi implementada uma solução mais simples se comparada aos planos iniciais, mas que contempla:
Hierarquia;
Polimorfismo;
Interfaces;
Além de conexão com o banco.

# Rodando o código

Para compilar o programa, **é necessário estar na pasta C++**:

Executar somente uma vez na máquina:

> sudo apt update

> sudo apt install libsqlite3-dev (instalar a biblioteca do sqlite)

> apt install sqlite (instalar o sqlite)

> gcc -c sqlite/sqlite3.c -o sqlite3.o (para compilar o código fonte do sqlite)

> g++ dao/criarDB.cpp sqlite3.o -o teste_sqlite (para criar o banco de dados)

> ./teste_sqlite (de fato cria o banco de dados)


Executar sempre que quiser rodar o programa:

> make