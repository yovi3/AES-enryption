#include "KeyGenerator.h"
#include <random>
#include <iostream>
#include <iomanip>

std::vector<unsigned char> KeyGenerator::generateKey(size_t length) {
    std::vector<unsigned char> key(length);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (size_t i = 0; i < length; ++i) {
        key[i] = dis(gen);
    }

    return key;
}

void KeyGenerator::printKey(const std::vector<unsigned char>& key) {
    for (const auto& byte : key) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";
    }
    std::cout << std::dec << std::endl;
}
