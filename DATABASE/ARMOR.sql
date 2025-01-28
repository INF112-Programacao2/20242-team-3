DROP SCHEMA IF EXISTS ARMOR;
CREATE SCHEMA IF NOT EXISTS ARMOR DEFAULT CHARACTER SET utf8 ;
USE ARMOR; 

CREATE TABLE Pessoa (
	idPessoa INT(11) NOT NULL AUTO_INCREMENT,
	nome VARCHAR(200) NOT NULL,
	nascimento DATE NOT NULL,
    telefone VARCHAR(15) NOT NULL, 
	cpf VARCHAR(11) NOT NULL,
	idade TINYINT UNSIGNED NOT NULL,
	sexo ENUM('MASCULINO', 'FEMININO') NOT NULL,
	PRIMARY KEY (idPessoa),
    UNIQUE INDEX cpf_UNIQUE (cpf ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE Cliente (
    idCliente INT(11) NOT NULL,
    envergadura DECIMAL(5, 2) NOT NULL,
    peso DECIMAL(5, 2) NOT NULL,
    altura DECIMAL(5, 2) NOT NULL,
    torax DECIMAL(5, 2) NOT NULL,
    cintura DECIMAL(5, 2) NOT NULL,
    PRIMARY KEY (idCliente),
    FOREIGN KEY (idCliente) REFERENCES Pessoa(idPessoa))
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

CREATE TABLE Funcionario (
    idFuncionario INT(11) NOT NULL,
	email VARCHAR(200) NOT NULL,
	senha VARCHAR(255) NOT NULL,
	UNIQUE INDEX email_UNIQUE (email ASC),
    PRIMARY KEY (idFuncionario),
    FOREIGN KEY (idFuncionario) REFERENCES Pessoa(idPessoa))
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

CREATE TABLE Marca (
  idMarca INT(11) NOT NULL AUTO_INCREMENT,
  nome VARCHAR(250) NOT NULL,
  PRIMARY KEY (idMarca))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE Modelo (
  idModelo INT(11) NOT NULL AUTO_INCREMENT,
  idMarca INT(11) NOT NULL,
  nome VARCHAR(250) NOT NULL,
  PRIMARY KEY (idModelo),
  FOREIGN KEY (idMarca) REFERENCES Marca(idMarca))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE Tamanho (
  idTamanho INT(11) NOT NULL AUTO_INCREMENT,
  tipoProduto ENUM('BERMUDA', 'FAIXA', 'KIMONO', 'RASH_GUARD') NOT NULL,
  nome VARCHAR(250) NOT NULL,
  PRIMARY KEY (idTamanho))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE Cor (
  idCor INT(11) NOT NULL AUTO_INCREMENT,
  nome VARCHAR(250) NOT NULL,
  PRIMARY KEY (idCor))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE Produto (
    idProduto INT(11) NOT NULL AUTO_INCREMENT,
    idMarca INT(11) NOT NULL,
    idModelo INT(11) NOT NULL,
    SKU VARCHAR(30) NOT NULL,
    faixaEtaria ENUM('ADULTO', 'INFANTIL', 'JUVENIL') NOT NULL,
    idTamanho INT(11) NOT NULL,
    sexo ENUM('MASCULINO', 'FEMININO', 'UNISSEX') NOT NULL,
    idCor INT(11) NOT NULL,
    PRIMARY KEY (idProduto),
    UNIQUE INDEX SKU_UNIQUE (SKU)) 
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

ALTER TABLE Produto ADD CONSTRAINT fk_produto_marca FOREIGN KEY (idMarca) REFERENCES Marca(idMarca) ON DELETE RESTRICT;
ALTER TABLE Produto ADD CONSTRAINT fk_produto_modelo FOREIGN KEY (idModelo) REFERENCES Modelo(idModelo) ON DELETE RESTRICT;
ALTER TABLE Produto ADD CONSTRAINT fk_produto_tamanho FOREIGN KEY (idTamanho) REFERENCES Tamanho(idTamanho) ON DELETE RESTRICT;
ALTER TABLE Produto ADD CONSTRAINT fk_produto_cor FOREIGN KEY (idCor) REFERENCES Cor(idCor) ON DELETE RESTRICT;

CREATE TABLE Kimono (
    idKimono INT(11) NOT NULL,
	gramaturaTecido DECIMAL(5, 2) NOT NULL,
    encolhimento INT(11) NOT NULL,
    forma ENUM('TRADICIONAL', 'SLIM', 'ULTRASLIM') NOT NULL,
    PRIMARY KEY (idKimono),
    FOREIGN KEY (idKimono) REFERENCES Produto(idProduto))
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

CREATE TABLE Faixa (
    idFaixa INT(11) NOT NULL,
	espessura ENUM('CLASSICA', 'ROBUSTA') NOT NULL,
    PRIMARY KEY (idFaixa),
    FOREIGN KEY (idFaixa) REFERENCES Produto(idProduto))
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

CREATE TABLE Bermuda (
    idBermuda INT(11) NOT NULL,
    ajuste ENUM('ELASTICO', 'BOTAO', 'AMARRACAO') NOT NULL,
	comprimento ENUM('CURTO', 'MEDIO', 'LONGO') NOT NULL,
    PRIMARY KEY (idBermuda),
    FOREIGN KEY (idBermuda) REFERENCES Produto(idProduto))
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

CREATE TABLE Rash_Guard (
    idRash_Guard INT(11) NOT NULL,
	fps INT(11) NOT NULL,
    PRIMARY KEY (idRash_Guard),
    FOREIGN KEY (idRash_Guard) REFERENCES Produto(idProduto))
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

CREATE TABLE Venda (
    idVenda INT(11) NOT NULL AUTO_INCREMENT,
    cpf VARCHAR(11) NOT NULL,
    SKU VARCHAR(30) NOT NULL,
    dataVenda DATE NOT NULL,
    satisfacao ENUM('MUITO_RUIM', 'RUIM', 'REGULAR', 'BOM', 'MUITO_BOM') NOT NULL,
    ajuste ENUM('JUSTO', 'LEVEMENTE_JUSTO', 'BOM', 'LEVEMENTE_FOLGADO', 'FOLGADO') NOT NULL,
    PRIMARY KEY (idVenda),
    FOREIGN KEY (cpf) REFERENCES Pessoa(cpf),
    FOREIGN KEY (SKU) REFERENCES Produto(SKU)
)
ENGINE = InnoDB
DEFAULT CHARSET = utf8;

ALTER TABLE Venda ADD CONSTRAINT fk_venda_pessoa FOREIGN KEY (cpf) REFERENCES Pessoa(cpf) ON DELETE RESTRICT;
ALTER TABLE Venda ADD CONSTRAINT fk_venda_produto FOREIGN KEY (SKU) REFERENCES Produto(SKU) ON DELETE RESTRICT;

INSERT INTO Cor (nome) VALUES ("Azul escuro");
INSERT INTO Cor (nome) VALUES ("Vermelho");
INSERT INTO Cor (nome) VALUES ("Preto");
INSERT INTO Cor (nome) VALUES ("Azul claro");

SELECT * FROM Tamanho;

INSERT INTO Tamanho (tipoProduto, nome) VALUES ("BERMUDA", 'P');
INSERT INTO Tamanho (tipoProduto, nome) VALUES ('BERMUDA', 'M');
INSERT INTO Tamanho (tipoProduto, nome) VALUES ('BERMUDA', 'G');
INSERT INTO Tamanho (tipoProduto, nome) VALUES ('BERMUDA', 'GG');

SELECT * FROM Tamanho WHERE tipoProduto = 'BERMUDA';

INSERT INTO Pessoa (nome, nascimento, telefone, cpf, idade, sexo) VALUES ("Thulio", '2004-07-15', "(31) 97112-0107", "17836460630", 20, 'MASCULINO');

select * from Funcionario where idFuncionario = 2;

INSERT INTO Funcionario (email, senha, idFuncionario) VALUES ("thuliomarco3@gmail.com", "@Thulio2025", 2);



SELECT 'Kimono' AS tipo
FROM Kimono
WHERE idKimono = 2
UNION ALL
SELECT 'Faixa' AS tipo
FROM Faixa
WHERE idFaixa = 2
UNION ALL
SELECT 'Bermuda' AS tipo
FROM Bermuda
WHERE idBermuda = 2
UNION ALL
SELECT 'Rash_Guard' AS tipo
FROM Rash_Guard
WHERE idRash_Guard = 2;

INSERT INTO Marca (nome) VALUES ("KVRA");
INSERT INTO Modelo (idMarca, nome) VALUES (1, "Reforçado");

-- Inserir na tabela Produto
INSERT INTO Produto (idMarca, idModelo, SKU, faixaEtaria, idTamanho, sexo, idCor)
VALUES (1, 1, 'SKU123456', 'ADULTO', 2, 'MASCULINO', 3);

-- Recuperar o último id gerado para Produto
SET @idProduto = LAST_INSERT_ID();

-- Inserir na tabela Kimono usando o idProduto como idKimono
INSERT INTO Kimono (idKimono, gramaturaTecido, encolhimento, forma)
VALUES (@idProduto, 450.5, 3, 'TRADICIONAL');

SELECT * FROM Kimono;
SELECT * FROM Produto;



