#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

std::vector<unsigned char> FileHandler::readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    std::vector<unsigned char> data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return data;
}

void FileHandler::printHex(const std::vector<unsigned char>& data) {
    for (const auto& byte : data) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";
    }
    std::cout << std::dec << std::endl;
}

void FileHandler::saveToFile(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}

void FileHandler::hexStringToBinaryFile(const std::string& hexString, const std::string& filename) {
    std::vector<unsigned char> binaryData;
    binaryData.reserve(hexString.size() / 2);

    for (std::size_t i = 0; i < hexString.size(); i += 2) {
        unsigned char byte = std::stoi(hexString.substr(i, 2), nullptr, 16);
        binaryData.push_back(byte);
    }

    saveToFile(filename, binaryData);
}
