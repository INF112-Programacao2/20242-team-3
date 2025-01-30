#include <iostream>
#include <string>
#include <bcrypt.h>  

class PasswordUtil {
public:
    // Gerar hash da senha
    static std::string hashPassword(const std::string& password) {
        char hash[BCRYPT_HASHSIZE];
        if (bcrypt_gensalt(12, hash) != 0) {
            throw std::runtime_error("Erro ao gerar o salt");
        }
        char hashedPassword[BCRYPT_HASHSIZE];
        if (bcrypt_hashpw(password.c_str(), hash, hashedPassword) != 0) {
            throw std::runtime_error("Erro ao gerar o hash");
        }
        return std::string(hashedPassword);
    }

    // Verificar se a senha corresponde ao hash
    static bool checkPassword(const std::string& rawPassword, const std::string& hashedPassword) {
        return bcrypt_checkpw(rawPassword.c_str(), hashedPassword.c_str()) == 0;
    }
};
