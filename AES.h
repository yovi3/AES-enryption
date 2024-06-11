#ifndef AES_H
#define AES_H

#include <vector>
#include <string>

class AES {
public:
    static std::vector<unsigned char> xorData(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key);
    static void subBytes(std::vector<unsigned char>& data);
    static void shiftRows(std::vector<unsigned char>& data);
    static void mixColumns(std::vector<unsigned char>& data);
    static void printState(const std::vector<unsigned char>& state, const std::string& label);
    static void addRoundKey(std::vector<unsigned char>& data, const std::vector<unsigned char>& roundKey);
    static std::vector<std::vector<unsigned char>> keyExpansion(const std::vector<unsigned char>& key);
    static std::vector<unsigned char> applyAES(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key);
    static const unsigned char sBox[256];
private:
    static uint8_t galois_multiplication(uint8_t a, uint8_t b);
};

#endif // AES_H
