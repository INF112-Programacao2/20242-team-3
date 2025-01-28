#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/base64.h>
#include <openssl/rand.h>

class EncryptionUtil {
private:
    static const std::string SECRET_KEY; // Chave de 16 bytes para AES-128

public:
    // Criptografar
    static std::string encrypt(const std::string& data) {
        AES_KEY aesKey;
        unsigned char encryptedData[data.size() + AES_BLOCK_SIZE];
        unsigned char iv[AES_BLOCK_SIZE] = {0};

        // Gerar a chave AES de 128 bits
        AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(SECRET_KEY.c_str()), 128, &aesKey);

        // Criptografar
        int dataLength = data.size();
        int encryptedDataLength = (dataLength / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
        AES_cbc_encrypt(reinterpret_cast<const unsigned char*>(data.c_str()), encryptedData, dataLength, &aesKey, iv, AES_ENCRYPT);

        // Codificar os dados criptografados em Base64
        std::string encodedData = base64_encode(encryptedData, encryptedDataLength);
        return encodedData;
    }

    // Descriptografar
    static std::string decrypt(const std::string& encryptedData) {
        AES_KEY aesKey;
        unsigned char decryptedData[encryptedData.size() + AES_BLOCK_SIZE];
        unsigned char iv[AES_BLOCK_SIZE] = {0};

        // Decodificar os dados criptografados em Base64
        unsigned char* decodedData = base64_decode(encryptedData);

        // Gerar a chave AES de 128 bits
        AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(SECRET_KEY.c_str()), 128, &aesKey);

        // Descriptografar
        int decryptedDataLength = encryptedData.size();
        AES_cbc_encrypt(decodedData, decryptedData, decryptedDataLength, &aesKey, iv, AES_DECRYPT);

        return std::string(reinterpret_cast<char*>(decryptedData), decryptedDataLength);
    }

private:
    // Funções auxiliares de codificação e decodificação em Base64
    static std::string base64_encode(const unsigned char* data, size_t length) {
        char* encodedData = (char*)malloc(Base64encode_len(length));
        Base64encode(encodedData, (const char*)data, length);
        std::string result(encodedData);
        free(encodedData);
        return result;
    }

    static unsigned char* base64_decode(const std::string& data) {
        size_t decodedLength = Base64decode_len(data.c_str());
        unsigned char* decodedData = (unsigned char*)malloc(decodedLength);
        Base64decode((char*)decodedData, data.c_str());
        return decodedData;
    }
};

// Definir a chave secreta
const std::string EncryptionUtil::SECRET_KEY = "ARMOR00ASXCC#Key";
