#include "ProdutoDao.h"

// Construtor para abrir o banco
ProdutoDao::ProdutoDao(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Não foi possível abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Destrutor para fechar o banco
ProdutoDao::~ProdutoDao() {
    sqlite3_close(db);
}

// Converter string para Sexo
Sexo ProdutoDao::stringToSexo(const std::string& sexoStr) {
    if (sexoStr == "MASCULINO") return Sexo::MASCULINO;
    if (sexoStr == "FEMININO") return Sexo::FEMININO;
    if (sexoStr == "UNISSEX") return Sexo::UNISSEX;
    throw std::invalid_argument("Sexo inválido: " + sexoStr);
}

// Converter Sexo para String
std::string ProdutoDao::sexoToString(const Sexo& sexo) {
    std::string sexoStr;

    switch (sexo) {
        case Sexo::MASCULINO: sexoStr = "MASCULINO"; break;
        case Sexo::FEMININO: sexoStr = "FEMININO"; break;
        case Sexo::UNISSEX: sexoStr = "UNISSEX"; break;
    }

    return sexoStr;
}

// Converter string para FaixaEtaria
FaixaEtaria ProdutoDao::stringToFaixaEtaria(const std::string& faixaEtariaStr) {
    if (faixaEtariaStr == "ADULTO") return FaixaEtaria::ADULTO;
    if (faixaEtariaStr == "INFANTIL") return FaixaEtaria::INFANTIL;
    if (faixaEtariaStr == "JUVENIL") return FaixaEtaria::JUVENIL;
    throw std::invalid_argument("Faixa etária inválida: " + faixaEtariaStr);
}

// Converter FaixaEtaria para String
std::string ProdutoDao::faixaEtariaToString(const FaixaEtaria& faixaEtaria) {
    std::string faixaEtariaStr;

    switch (faixaEtaria) {
        case FaixaEtaria::ADULTO: faixaEtariaStr = "ADULTO"; break;
        case FaixaEtaria::INFANTIL: faixaEtariaStr = "INFANTIL"; break;
        case FaixaEtaria::JUVENIL: faixaEtariaStr = "JUVENIL"; break;
    }

    return faixaEtariaStr;
}

// Buscar o produto pelo ID
Produto ProdutoDao::findById(int idProduto) {
    std::string sql = "SELECT * FROM Produto WHERE idProduto = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idProduto);

    Produto produto; // Objeto vazio para armazenar os dados
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        // Obter os dados do produto
        int idMarca = sqlite3_column_int(stmt, 1); // idMarca
        int idModelo = sqlite3_column_int(stmt, 2); // idModelo
        int idTamanho = sqlite3_column_int(stmt, 5); // idTamanho
        int idCor = sqlite3_column_int(stmt, 7); // idCor
        
        // Criar objetos auxiliares
        Marca* marca = new Marca(idMarca, ""); // Passe o nome correto se disponível
        Modelo* modelo = new Modelo(idModelo, idMarca, ""); // Passe o nome correto se disponível
        Tamanho* tamanho = new Tamanho(idTamanho, TipoProduto::FAIXA, ""); // Passe o tipo correto
        Cor* cor = new Cor(idCor, ""); // Passe o nome correto se disponível

        // Preencher o produto
        produto.setIdProduto(sqlite3_column_int(stmt, 0)); // idProduto
        produto.setIdMarca(idMarca); // idMarca
        produto.setMarca(marca); // Ponteiro para o objeto Marca
        produto.setIdModelo(idModelo); // idModelo
        produto.setModelo(modelo); // Ponteiro para o objeto Modelo
        produto.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))); // SKU
        
        // Converter faixaEtaria para o enum FaixaEtaria
        std::string faixaEtariaStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        produto.setFaixaEtaria(stringToFaixaEtaria(faixaEtariaStr)); // faixaEtaria
        
        produto.setIdTamanho(idTamanho); // idTamanho
        produto.setTamanho(tamanho); // Ponteiro para o objeto Tamanho
        
        // Converter sexo para o enum Sexo
        std::string sexoStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        produto.setSexo(stringToSexo(sexoStr)); // sexo
        
        produto.setIdCor(idCor); // idCor
        produto.setCor(cor); // Ponteiro para o objeto Cor
    } else {
        std::cerr << "Nenhum produto encontrado com o ID: " << idProduto << std::endl;
    }

    sqlite3_finalize(stmt);
    return produto;
}

// Buscar todos os produtos
std::vector<Produto> ProdutoDao::findAll() {
    std::string sql = "SELECT * FROM Produto";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    std::vector<Produto> produtos;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int idProduto = sqlite3_column_int(stmt, 0);
        int idMarca = sqlite3_column_int(stmt, 1);
        int idModelo = sqlite3_column_int(stmt, 2);
        std::string SKU = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        FaixaEtaria faixaEtaria = stringToFaixaEtaria(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        int idTamanho = sqlite3_column_int(stmt, 5);
        Sexo sexo = stringToSexo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        int idCor = sqlite3_column_int(stmt, 7);

        // Criar objetos auxiliares
        Marca* marca = new Marca(idMarca, ""); // Passe o nome correto se disponível
        Modelo* modelo = new Modelo(idModelo, idMarca, ""); // Passe o nome correto se disponível
        Tamanho* tamanho = new Tamanho(idTamanho, TipoProduto::FAIXA, ""); // Passe o tipo correto
        Cor* cor = new Cor(idCor, ""); // Passe o nome correto se disponível

        // Criar o Produto
        Produto produto(idProduto, idMarca, marca, idModelo, modelo, SKU,
                        faixaEtaria, idTamanho, tamanho, sexo, idCor, cor
                       );

        produtos.push_back(produto);
    }

    sqlite3_finalize(stmt);
    return produtos;
}


// Inserir uma novo produto
Produto ProdutoDao::insert(Produto& produto) {
    std::string sql = "INSERT INTO Produto (idMarca, idModelo, SKU, faixaEtaria, idTamanho, sexo, idCor) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    // Conversões de tipos
    std::string sexoStr = sexoToString(produto.getSexo()); // Converte Sexo pra String
    std::string faixaEtariaStr = faixaEtariaToString(produto.getFaixaEtaria()); // Converte FaixaEtaria pra String

    // Inserindo dados no banco
    sqlite3_bind_int(stmt, 1, produto.getIdMarca());
    sqlite3_bind_int(stmt, 2, produto.getIdModelo());
    sqlite3_bind_text(stmt, 3, produto.getSKU().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, faixaEtariaStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, produto.getIdTamanho());
    sqlite3_bind_text(stmt, 6, sexoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, produto.getIdCor());

    // Executar a consulta
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Erro ao executar consulta de inserção: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);

    // Recuperar o ID gerado automaticamente (LAST_INSERT_ROWID em SQLite)
    int idProduto = sqlite3_last_insert_rowid(db);
    produto.setIdProduto(idProduto);

    return produto;
}

// Atualizar um produto existente
Produto ProdutoDao::update(const Produto& produto) {
    std::string sql = "UPDATE Produto SET idMarca = ?, idModelo = ?, SKU = ?, faixaEtaria = ?, idTamanho = ?, sexo = ?, idCor = ? WHERE idProduto = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    // Conversões de tipos
    std::string sexoStr = sexoToString(produto.getSexo()); // Converte Sexo pra String
    std::string faixaEtariaStr = faixaEtariaToString(produto.getFaixaEtaria()); // Converte FaixaEtaria pra String

    // Inserindo dados no banco
    sqlite3_bind_int(stmt, 1, produto.getIdMarca());
    sqlite3_bind_int(stmt, 2, produto.getIdModelo());
    sqlite3_bind_text(stmt, 3, produto.getSKU().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, faixaEtariaStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, produto.getIdTamanho());
    sqlite3_bind_text(stmt, 6, sexoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, produto.getIdCor());
    sqlite3_bind_int(stmt, 8, produto.getIdProduto());

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Erro ao executar consulta de atualização: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);

    return produto;
}

// Deletar um produto pelo ID
void ProdutoDao::deleteById(int idProduto) {
    std::string sql = "DELETE FROM Produto WHERE idProduto = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idProduto);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Erro ao deletar o Produto: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
}

// Buscar todos os produtos, filtrando pelo SKU
Produto ProdutoDao::findBySKU(const std::string& SKU) {
    std::string sql = "SELECT * FROM Produto WHERE SKU = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    // Associar o valor do SKU ao parâmetro da consulta
    sqlite3_bind_text(stmt, 1, SKU.c_str(), -1, SQLITE_STATIC);

    Produto produto;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        // Mapear as colunas do resultado para os atributos do Produto
        produto.setIdProduto(sqlite3_column_int(stmt, 0)); // idProduto
        produto.setIdMarca(sqlite3_column_int(stmt, 1)); // idMarca
        produto.setIdModelo(sqlite3_column_int(stmt, 2)); // idModelo
        produto.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))); // SKU
        
        // Converter faixaEtaria para o enum FaixaEtaria
        std::string faixaEtariaStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        produto.setFaixaEtaria(stringToFaixaEtaria(faixaEtariaStr)); // faixaEtaria
        
        produto.setIdTamanho(sqlite3_column_int(stmt, 5)); // idTamanho
        
        // Converter sexo para o enum Sexo
        std::string sexoStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        produto.setSexo(stringToSexo(sexoStr)); // sexo
        
        produto.setIdCor(sqlite3_column_int(stmt, 7)); // idCor
    } else {
        std::cerr << "Nenhum produto encontrado com o SKU: " << SKU << std::endl;
    }

    // Finalizar o statement
    sqlite3_finalize(stmt);
    
    return produto;
}

// Pesquisar como Tipo de Produto
std::string ProdutoDao::searchTipoProduto(int idProduto) {
    std::string sql = R"(
        SELECT 'Kimono' AS tipo FROM Kimono WHERE idKimono = ? 
        UNION ALL SELECT 'Faixa' AS tipo FROM Faixa WHERE idFaixa = ? 
        UNION ALL SELECT 'Bermuda' AS tipo FROM Bermuda WHERE idBermuda = ?
        UNION ALL SELECT 'Rash_Guard' AS tipo FROM Rash_Guard WHERE idRash_Guard = ?
    )";

    sqlite3_stmt* stmt;

    // Preparar a consulta
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, idProduto);
    sqlite3_bind_int(stmt, 2, idProduto);
    sqlite3_bind_int(stmt, 3, idProduto);
    sqlite3_bind_int(stmt, 4, idProduto);

    // Executar a consulta e capturar o resultado
    std::string tipoProduto;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        // Obter o valor da coluna 'tipo' como string
        tipoProduto = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    } else {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Produto com ID " + std::to_string(idProduto) + " não encontrado.");
    }

    // Finalizar o statement
    sqlite3_finalize(stmt);

    return tipoProduto;
}