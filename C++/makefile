# Variáveis
CXX = g++
CFLAGS = -c
LDFLAGS = -lsqlite3
SQLITE_SRC = sqlite/sqlite3.c
SQLITE_OBJ = sqlite3.o

# Arquivos principais
DB_NAME = BANCO.db
CPP_FILES = model/Produto.cpp model/Cor.cpp model/Marca.cpp model/Modelo.cpp model/Tamanho.cpp dao/ProdutoDao.cpp dao/testeDao.cpp
APP_NAME = app

# Regras principais
test: sqlite $(DB_NAME) $(APP_NAME) run

sqlite:
	@if [ ! -f $(SQLITE_OBJ) ]; then \
		gcc $(CFLAGS) $(SQLITE_SRC) -o $(SQLITE_OBJ); \
		echo "SQLite compilado com sucesso."; \
	else \
		echo "SQLite já compilado."; \
	fi

$(DB_NAME): dao/criarDB.cpp sqlite
	@if [ ! -f $(DB_NAME) ]; then \
		$(CXX) dao/criarDB.cpp $(SQLITE_OBJ) -o criarDB -lsqlite3; \
		./criarDB; \
		echo "Banco de dados criado com sucesso."; \
	else \
		echo "Banco de dados já existente."; \
	fi

$(APP_NAME): $(CPP_FILES) $(SQLITE_OBJ)
	@$(CXX) $(CPP_FILES) $(SQLITE_OBJ) -o $(APP_NAME) $(LDFLAGS)
	@echo "Aplicativo $(APP_NAME) compilado com sucesso."

run:
	@./$(APP_NAME)
	@echo "Teste executado com sucesso."

clean:
	@rm -f $(APP_NAME) $(SQLITE_OBJ) criarDB $(DB_NAME)
	@echo "Arquivos de compilação removidos."
