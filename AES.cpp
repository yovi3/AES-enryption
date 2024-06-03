#include "AES.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "MixColumns.h"

const unsigned char AES::sBox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

const unsigned char Rcon[11] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36, 0x6C };

void printState(const std::vector<unsigned char>& state, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& byte : state) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;
}

uint8_t galoisMultiplication(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    uint8_t hi_bit_set;
    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            p ^= a;
        }
        hi_bit_set = a & 0x80;
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1b;
        }
        b >>= 1;
    }
    return p;
}

std::vector<unsigned char> AES::xorData(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key) {
    std::vector<unsigned char> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key[i % key.size()];
    }
    return result;
}

void AES::subBytes(std::vector<unsigned char>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] = sBox[data[i]];
    }
    printState(data, "After SubBytes");
}

void AES::shiftRows(std::vector<unsigned char>& data) {
    std::vector<unsigned char> temp(16);

    temp[0] = data[0];
    temp[1] = data[1];
    temp[2] = data[2];
    temp[3] = data[3];

    temp[4] = data[5];
    temp[5] = data[6];
    temp[6] = data[7];
    temp[7] = data[4];

    temp[8] = data[10];
    temp[9] = data[11];
    temp[10] = data[8];
    temp[11] = data[9];

    temp[12] = data[15];
    temp[13] = data[12];
    temp[14] = data[13];
    temp[15] = data[14];

    data = temp;
    printState(data, "After ShiftRows");
}

void AES::mixColumns(std::vector<unsigned char>& data) {
    std::vector<uint8_t> state(data.begin(), data.end());
    MixColumns::apply(state);
    std::copy(state.begin(), state.end(), data.begin());
    printState(data, "After MixColumns");
}

void AES::addRoundKey(std::vector<unsigned char>& data, const std::vector<unsigned char>& roundKey) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= roundKey[i];
    }
    printState(data, "After AddRoundKey");
}

std::vector<unsigned char> rotWord(const std::vector<unsigned char>& word) {
    return { word[1], word[2], word[3], word[0] };
}

std::vector<unsigned char> subWord(const std::vector<unsigned char>& word) {
    std::vector<unsigned char> result(4);
    for (int i = 0; i < 4; ++i) {
        result[i] = AES::sBox[word[i]];
    }
    return result;
}

std::vector<std::vector<unsigned char>> AES::keyExpansion(const std::vector<unsigned char>& key) {
    std::vector<std::vector<unsigned char>> expandedKeys(11, std::vector<unsigned char>(16));
    for (int i = 0; i < 16; ++i) {
        expandedKeys[0][i] = key[i];
    }
    for (int i = 1; i < 11; ++i) {
        std::vector<unsigned char> temp(4);
        for (int j = 0; j < 4; ++j) {
            temp[j] = expandedKeys[i - 1][12 + j];
        }
        temp = rotWord(temp);
        temp = subWord(temp);
        temp[0] ^= Rcon[i - 1];
        for (int j = 0; j < 4; ++j) {
            expandedKeys[i][j] = expandedKeys[i - 1][j] ^ temp[j];
        }
        for (int j = 4; j < 16; ++j) {
            expandedKeys[i][j] = expandedKeys[i - 1][j] ^ expandedKeys[i][j - 4];
        }
    }
    return expandedKeys;
}

std::vector<unsigned char> AES::applyAES(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key) {
    if (key.size() != 16) {
        throw std::invalid_argument("Key must be 16 bytes");
    }

    std::vector<unsigned char> encryptedData;
    auto expandedKeys = keyExpansion(key);
    for (size_t i = 0; i < data.size(); i += 16) {
        std::vector<unsigned char> block(data.begin() + i, data.begin() + std::min(data.size(), i + 16));

        if (block.size() < 16) {
            block.resize(16, 0);
        }

        addRoundKey(block, expandedKeys[0]);

        for (int round = 1; round < 10; ++round) {
            subBytes(block);
            shiftRows(block);
            mixColumns(block);
            addRoundKey(block, expandedKeys[round]);
        }

        subBytes(block);
        shiftRows(block);
        addRoundKey(block, expandedKeys[10]);

        encryptedData.insert(encryptedData.end(), block.begin(), block.end());
    }

    return encryptedData;
}

std::vector<unsigned char> AES::pkcs5Padding(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> paddedData = data;
    size_t paddingSize = 16 - (data.size() % 16);
    paddedData.insert(paddedData.end(), paddingSize, static_cast<unsigned char>(paddingSize));
    return paddedData;
}

std::vector<unsigned char> AES::applyAESCBC(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key, const std::vector<unsigned char>& iv) {
    if (key.size() != 16 || iv.size() != 16) {
        throw std::invalid_argument("Key and IV must be 16 bytes");
    }

    std::vector<unsigned char> encryptedData;
    auto expandedKeys = keyExpansion(key);
    std::vector<unsigned char> previousBlock = iv;

    std::vector<unsigned char> paddedData = pkcs5Padding(data);

    for (size_t i = 0; i < paddedData.size(); i += 16) {
        std::vector<unsigned char> block(paddedData.begin() + i, paddedData.begin() + i + 16);

        block = xorData(block, previousBlock);

        addRoundKey(block, expandedKeys[0]);

        for (int round = 1; round < 10; ++round) {
            subBytes(block);
            shiftRows(block);
            mixColumns(block);
            addRoundKey(block, expandedKeys[round]);
        }

        subBytes(block);
        shiftRows(block);
        addRoundKey(block, expandedKeys[10]);

        encryptedData.insert(encryptedData.end(), block.begin(), block.end());
        previousBlock = block;
    }

    return encryptedData;
}

std::vector<unsigned char> AES::applyAESECB(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key) {
    if (key.size() != 16) {
        throw std::invalid_argument("Key must be 16 bytes");
    }

    std::vector<unsigned char> encryptedData;
    auto expandedKeys = keyExpansion(key);
    std::vector<unsigned char> paddedData = pkcs5Padding(data);

    for (size_t i = 0; i < paddedData.size(); i += 16) {
        std::vector<unsigned char> block(paddedData.begin() + i, paddedData.begin() + i + 16);

        addRoundKey(block, expandedKeys[0]);

        for (int round = 1; round < 10; ++round) {
            subBytes(block);
            shiftRows(block);
            mixColumns(block);
            addRoundKey(block, expandedKeys[round]);
        }

        subBytes(block);
        shiftRows(block);
        addRoundKey(block, expandedKeys[10]);

        encryptedData.insert(encryptedData.end(), block.begin(), block.end());
    }

    return encryptedData;
}
