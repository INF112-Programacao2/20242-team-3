CC = g++
SRC = \
    model/Produto.cpp \
    model/Bermuda.cpp \
    model/Kimono.cpp \
    controller/BermudaController.cpp \
    controller/KimonoController.cpp \
    controller/MenuController.cpp \
    controller/LoginController.cpp \
    dao/ProdutoDao.cpp \
    dao/BermudaDao.cpp \
    dao/KimonoDao.cpp \
    main/main.cpp

TARGET = app
LIBS = -lsqlite3

all: build run

build:
	$(CC) $(SRC) -o $(TARGET) $(LIBS)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
