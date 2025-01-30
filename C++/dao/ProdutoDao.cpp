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

// Converter ENUMS para STRING
std::string ProdutoDao::sexoToString(const Sexo& sexo) {
    std::string sexoStr;

    switch (sexo) {
        case Sexo::MASCULINO: sexoStr = "MASCULINO"; break;
        case Sexo::FEMININO: sexoStr = "FEMININO"; break;
        case Sexo::UNISSEX: sexoStr = "UNISSEX"; break;
    }

    return sexoStr;
}

std::string ProdutoDao::faixaEtariaToString(const FaixaEtaria& faixaEtaria) {
    std::string faixaEtariaStr;

    switch (faixaEtaria) {
        case FaixaEtaria::ADULTO: faixaEtariaStr = "ADULTO"; break;
        case FaixaEtaria::INFANTIL: faixaEtariaStr = "INFANTIL"; break;
        case FaixaEtaria::JUVENIL: faixaEtariaStr = "JUVENIL"; break;
    }

    return faixaEtariaStr;
}

std::string ProdutoDao::marcaToString(Marca marca) {
    switch (marca) {
        case Marca::KVRA: return "KVRA";
        case Marca::VOUK: return "VOUK";
        case Marca::DUBAI: return "DUBAI";
        case Marca::SUERTE: return "SUERTE";
        default: return "Desconhecida";
    }
}

std::string ProdutoDao::modeloToString(Modelo modelo) {
    switch (modelo) {
        case Modelo::COMUM: return "COMUM";
        case Modelo::REFORÇADO: return "REFORÇADO";
        default: return "Desconhecido";
    }
}

std::string ProdutoDao::tamanhoToString(Tamanho tamanho) {
    switch (tamanho) {
        case Tamanho::P: return "P";
        case Tamanho::M: return "M";
        case Tamanho::G: return "G";
        case Tamanho::GG: return "GG";
        case Tamanho::XGG: return "XGG";
        default: return "Desconhecido";
    }
}

std::string ProdutoDao::corToString(Cor cor) {
    switch (cor) {
        case Cor::PRETO: return "PRETO";
        case Cor::BRANCO: return "BRANCO";
        case Cor::AZUL: return "AZUL";
        case Cor::ROSA: return "ROSA";
        case Cor::CINZA: return "CINZA";
        case Cor::VERDE: return "VERDE";
        default: return "Desconhecida";
    }
}


// Converter STRINGS para ENUMS
Sexo ProdutoDao::stringToSexo(const std::string& sexoStr) {
    if (sexoStr == "MASCULINO") return Sexo::MASCULINO;
    if (sexoStr == "FEMININO") return Sexo::FEMININO;
    if (sexoStr == "UNISSEX") return Sexo::UNISSEX;
    throw std::invalid_argument("Sexo inválido: " + sexoStr);
}

FaixaEtaria ProdutoDao::stringToFaixaEtaria(const std::string& faixaEtariaStr) {
    if (faixaEtariaStr == "ADULTO") return FaixaEtaria::ADULTO;
    if (faixaEtariaStr == "INFANTIL") return FaixaEtaria::INFANTIL;
    if (faixaEtariaStr == "JUVENIL") return FaixaEtaria::JUVENIL;
    throw std::invalid_argument("Faixa etária inválida: " + faixaEtariaStr);
}

Marca ProdutoDao::stringToMarca(const std::string& marcaStr) {
    if (marcaStr == "KVRA") return Marca::KVRA;
    if (marcaStr == "VOUK") return Marca::VOUK;
    if (marcaStr == "DUBAI") return Marca::DUBAI;
    if (marcaStr == "SUERTE") return Marca::SUERTE;
    throw std::invalid_argument("Marca desconhecida");
}

Modelo ProdutoDao::stringToModelo(const std::string& modeloStr) {
    if (modeloStr == "COMUM") return Modelo::COMUM;
    if (modeloStr == "REFORÇADO") return Modelo::REFORÇADO;
    throw std::invalid_argument("Modelo desconhecido");
}

Tamanho ProdutoDao::stringToTamanho(const std::string& tamanhoStr) {
    if (tamanhoStr == "P") return Tamanho::P;
    if (tamanhoStr == "M") return Tamanho::M;
    if (tamanhoStr == "G") return Tamanho::G;
    if (tamanhoStr == "GG") return Tamanho::GG;
    if (tamanhoStr == "XGG") return Tamanho::XGG;
    throw std::invalid_argument("Tamanho desconhecido");
}

Cor ProdutoDao::stringToCor(const std::string& corStr) {
    if (corStr == "PRETO") return Cor::PRETO;
    if (corStr == "BRANCO") return Cor::BRANCO;
    if (corStr == "AZUL") return Cor::AZUL;
    if (corStr == "ROSA") return Cor::ROSA;
    if (corStr == "CINZA") return Cor::CINZA;
    if (corStr == "VERDE") return Cor::VERDE;
    throw std::invalid_argument("Cor desconhecida");
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

        // Preencher o produto
        produto.setIdProduto(sqlite3_column_int(stmt, 0)); // idProduto

        // Converter marca para o enum Marca
        std::string marcaStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        produto.setMarca(stringToMarca(marcaStr)); // marca
        
        // Converter modelo para o enum Modelo
        std::string modeloStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        produto.setModelo(stringToModelo(modeloStr)); // modelo

        

        produto.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))); // SKU
        std::cout << produto.getSKU() << "----------------------------------------------\n";    


        // Converter faixaEtaria para o enum FaixaEtaria
        std::string faixaEtariaStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        produto.setFaixaEtaria(stringToFaixaEtaria(faixaEtariaStr)); // faixaEtaria
        
        // Converter tamanho para o enum Tamanho
        std::string tamanhoStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        produto.setTamanho(stringToTamanho(tamanhoStr)); // tamanho
        
        // Converter sexo para o enum Sexo
        std::string sexoStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        produto.setSexo(stringToSexo(sexoStr)); // sexo
        
        // Converter cor para o enum Cor
        std::string corStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)));
        produto.setCor(stringToCor(corStr)); // cor
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
        Marca marca = stringToMarca(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        Modelo modelo = stringToModelo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        std::string SKU = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        FaixaEtaria faixaEtaria = stringToFaixaEtaria(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        Tamanho tamanho = stringToTamanho(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        Sexo sexo = stringToSexo(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        Cor cor = stringToCor(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)));

        // Criar o Produto
        Produto produto(idProduto, marca, modelo, SKU,
                        faixaEtaria, tamanho, sexo, cor
                       );

        produtos.push_back(produto);
    }

    sqlite3_finalize(stmt);
    return produtos;
}


// Inserir uma novo produto
Produto ProdutoDao::insert(Produto& produto) {
    std::string sql = "INSERT INTO Produto (marca, modelo, SKU, faixaEtaria, tamanho, sexo, cor) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    // Conversões de tipos
    std::string sexoStr = sexoToString(produto.getSexo()); // Converte Sexo pra String
    std::string faixaEtariaStr = faixaEtariaToString(produto.getFaixaEtaria()); // Converte FaixaEtaria pra String
    std::string marcaStr = marcaToString(produto.getMarca());
    std::string modeloStr = modeloToString(produto.getModelo());
    std::string tamanhoStr = tamanhoToString(produto.getTamanho()); // Converte Tamanho
    std::string corStr = corToString(produto.getCor()); // Converte Cor

    // Inserindo dados no banco
    sqlite3_bind_text(stmt, 1, marcaStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, modeloStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, produto.getSKU().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, faixaEtariaStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, tamanhoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, sexoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, corStr.c_str(), -1, SQLITE_STATIC);

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
    std::string sql = "UPDATE Produto SET marca = ?, modelo = ?, SKU = ?, faixaEtaria = ?, tamanho = ?, sexo = ?, cor = ? WHERE idProduto = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta: " + std::string(sqlite3_errmsg(db)));
    }

    // Conversões de tipos
    std::string sexoStr = sexoToString(produto.getSexo()); // Converte Sexo pra String
    std::string faixaEtariaStr = faixaEtariaToString(produto.getFaixaEtaria()); // Converte FaixaEtaria pra String
    std::string marcaStr = marcaToString(produto.getMarca());
    std::string modeloStr = modeloToString(produto.getModelo());
    std::string tamanhoStr = tamanhoToString(produto.getTamanho()); // Converte Tamanho
    std::string corStr = corToString(produto.getCor()); // Converte Cor


    // Inserindo dados no banco
    sqlite3_bind_text(stmt, 1, marcaStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, modeloStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, produto.getSKU().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, faixaEtariaStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, tamanhoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, sexoStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, corStr.c_str(), -1, SQLITE_STATIC);

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

        // Preencher o produto
        produto.setIdProduto(sqlite3_column_int(stmt, 0)); // idProduto

        // Converter marca para o enum Marca
        std::string marcaStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        produto.setMarca(stringToMarca(marcaStr)); // marca
        
        // Converter modelo para o enum Modelo
        std::string modeloStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        produto.setModelo(stringToModelo(modeloStr)); // modelo
        
        produto.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3))); // SKU
        
        // Converter faixaEtaria para o enum FaixaEtaria
        std::string faixaEtariaStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        produto.setFaixaEtaria(stringToFaixaEtaria(faixaEtariaStr)); // faixaEtaria
        
        // Converter tamanho para o enum Tamanho
        std::string tamanhoStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        produto.setTamanho(stringToTamanho(tamanhoStr)); // tamanho
        
        // Converter sexo para o enum Sexo
        std::string sexoStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        produto.setSexo(stringToSexo(sexoStr)); // sexo
        
        // Converter cor para o enum Cor
        std::string corStr(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)));
        produto.setCor(stringToCor(corStr)); // cor
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