# 20242-team-3

Thulio Marco de Oliveira Fernandes  116223 
Gabriel Valério Silva Barros 116232
Leonardo Peçanha Scala 116217

# Tema do projeto

Sistema de gerenciamento de estoque para empesas fornecedoras de itens variados.


# Rodando o código

Para compilar o programa, é necessário estar na pasta raíz do projeto:

> cd "TRABALHO FINAL INF112/Trabalho Final INF112/C++"

Depois, basta rodar o comando a seguir para executar o código principal do projeto:

> make test

O código principal PARA TESTES irá, em ordem:
- Inserir um novo cadastro na tabela Produto
- Exibir o Produto cadastrado
- Atualizar o produto com novos dados
- Exibir o Produto com os dados atualizados
- Exibir todos os Produtos cadastrados
- Deletar o Produto que acabou de ser cadastrado
- Exibir todos os Produtos cadastrados novamente
- Exibir todos os Produtos com o SKU "Novo SKU3"

Executar estando na pasta C++:

>> Executar somente uma vez na máquina:

> sudo apt update

> sudo apt install libsqlite3-dev (instalar a biblioteca do sqlite)

> apt install sqlite

> gcc -c sqlite/sqlite3.c -o sqlite3.o (pra compilar o código fonte do sqlite, não é a gente que faz esse código, só compila ele pra usar)

> g++ dao/criarDB.cpp sqlite3.o -o teste_sqlite (pra criar o banco de dados. Só executar uma vez na máquina - no seu caso, não precisa executar de novo)

> ./teste_sqlite (de fato cria o banco de dados)

>> Executar sempre que quiser rodar o programa:

> g++ model/Produto.cpp model/Bermuda.cpp model/Kimono.cpp controller/BermudaController.cpp controller/KimonoController.cpp controller/MenuController.cpp dao/ProdutoDao.cpp dao/BermudaDao.cpp dao/KimonoDao.cpp -o app -lsqlite3 (compila os arquivos necessários)

> ./app (executa o teste)