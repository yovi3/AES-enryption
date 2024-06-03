#include "FileHandler.h"
#include "KeyGenerator.h"
#include "AES.h"
#include <iostream>

int main() {
    try {
        // Wczytaj plik
        std::vector<unsigned char> fileData = FileHandler::readFile("example.txt");
        std::cout << "File Data (Hex): ";
        FileHandler::printHex(fileData);

        // Wygeneruj klucz
        std::vector<unsigned char> key = KeyGenerator::generateKey(16);
        std::cout << "Generated Key (Hex): ";
        KeyGenerator::printKey(key);

        // Przetwórz dane przy użyciu AES
        std::vector<unsigned char> encryptedData = AES::applyAES(fileData, key);
        std::cout << "Encrypted Data (Hex): ";
        FileHandler::printHex(encryptedData);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
