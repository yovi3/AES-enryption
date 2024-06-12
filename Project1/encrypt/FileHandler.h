#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

class FileHandler {
public:
    static std::vector<unsigned char> readFile(const std::string& filename);
    static void printHex(const std::vector<unsigned char>& data);
    static void saveToFile(const std::string& filename, const std::vector<unsigned char>& data);
    static void hexStringToBinaryFile(const std::string& hexString, const std::string& filename);
};

#endif // FILEHANDLER_H
