#ifndef KIMONODAO_H
#define KIMONODAO_H

#include <sqlite3.h>
#include <vector>
#include "../model/Kimono.h"

class KimonoDao {
private:
    sqlite3* db;

public:
    KimonoDao(const std::string& db);
    ~KimonoDao();

    std::string formaToString(Forma forma);
    Forma stringToForma(const std::string& formaStr);

    Kimono findById(int idKimono);
    std::vector<Kimono> findAll();
    void insert(Kimono& kimono);
    void update(const Kimono& kimono);
    void deleteById(int idKimono);
};

#endif // KIMONODAO_H