#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

class FileHandler {
public:
    static std::vector<unsigned char> readFile(const std::string& filename);
    static void printHex(const std::vector<unsigned char>& data);
};

#endif // FILEHANDLER_H
