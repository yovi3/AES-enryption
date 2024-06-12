#include "FileHandler.h"
#include "KeyGenerator.h"
#include "AES.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "encrypt.h"
#include <vector>
#include <string>


std::string vectorToHexString(const std::vector<unsigned char>& vec) {
    std::stringstream ss;
    for (auto byte : vec) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    return ss.str();
}

std::string encrypt(std::string filePath2) {
    try {
        // Wczytaj plik
        std::vector<unsigned char> fileData = FileHandler::readFile(filePath2);
        std::cout << "File Data (Hex): ";
        FileHandler::printHex(fileData);

        // Wygeneruj klucz
        std::vector<unsigned char> key = KeyGenerator::generateKey(16);
        //std::cout << "Generated Key (Hex): ";
        KeyGenerator::printKey(key);
        std::string keyString = vectorToHexString(key);
        // Przetwórz dane przy u¿yciu AES
        std::vector<unsigned char> encryptedData = AES::applyAES(fileData, key);
        //std::cout << "Encrypted Data (Hex): ";
        //FileHandler::printHex(encryptedData);

        // Konwersja zaszyfrowanych danych do formatu szesnastkowego
        std::ostringstream hexStream;
        for (const auto& byte : encryptedData) {
            hexStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        }
        std::string hexString = hexStream.str();

        // Zapisz dane szesnastkowe jako plik binarny
        FileHandler::hexStringToBinaryFile(hexString, "encrypted_hex.dat");

        std::cout << "Encrypted data in hex format saved to encrypted_hex.dat" << std::endl;


        return keyString;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}