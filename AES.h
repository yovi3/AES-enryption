#ifndef AES_H
#define AES_H

#include <vector>

class AES {
public:
    static std::vector<unsigned char> xorData(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key);
    static void subBytes(std::vector<unsigned char>& data);
    static void shiftRows(std::vector<unsigned char>& data);
    static void mixColumns(std::vector<unsigned char>& data);
    static void addRoundKey(std::vector<unsigned char>& data, const std::vector<unsigned char>& roundKey);
    static std::vector<std::vector<unsigned char>> keyExpansion(const std::vector<unsigned char>& key);
    static std::vector<unsigned char> applyAES(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key);
    static std::vector<unsigned char> applyAESCBC(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key, const std::vector<unsigned char>& iv);
    static std::vector<unsigned char> applyAESECB(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key); // Nowa funkcja
    static std::vector<unsigned char> pkcs5Padding(const std::vector<unsigned char>& data);
    static const unsigned char sBox[256];
};

#endif // AES_H
