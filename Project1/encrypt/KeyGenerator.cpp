// KeyGenerator.cpp
#include "KeyGenerator.h"
#include <iostream>
#include <iomanip>
#include <random>

std::vector<unsigned char> KeyGenerator::generateKey(size_t length) {
    std::vector<unsigned char> key(length);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (size_t i = 0; i < length; ++i) {
        key[i] = static_cast<unsigned char>(dis(gen));
    }
    return key;
}

void KeyGenerator::printKey(const std::vector<unsigned char>& key) {
    for (const auto& byte : key) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << std::endl;
}
