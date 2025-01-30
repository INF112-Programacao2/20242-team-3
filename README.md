# 20242-team-3

Thulio Marco de Oliveira Fernandes  116223 
Gabriel Valério Silva Barros 116232
Leonardo Peçanha Scala 116217

# Tema do projeto

Sistema de gerenciamento de estoque para empresas fornecedoras de roupas esportivas.


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