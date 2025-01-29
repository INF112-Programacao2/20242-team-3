#ifndef BERMUDADAO_H
#define BERMUDADAO_H

#include <sqlite3.h>
#include <vector>
#include "../model/Bermuda.h"

class BermudaDao {
private:
    sqlite3* db;

public:
    BermudaDao(const std::string& db);
    ~BermudaDao();

    // Converter ENUMS para STRING
    std::string ajusteToString(Ajuste ajuste);
    std::string comprimentoToString(Comprimento comprimento);

    // Converter STRING para ENUMS
    Ajuste stringToAjuste(const std::string& ajusteStr);
    Comprimento stringToComprimento(const std::string& comprimentoStr);

    Bermuda findById(int idBermuda);
    std::vector<Bermuda> findAll();
    void insert(Bermuda& bermuda);
    void update(Bermuda& bermuda);
    void deleteById(int idBermuda);
};

#endif // KIMONODAO_H