#ifndef KEYGENERATOR_H
#define KEYGENERATOR_H

#include <vector>

class KeyGenerator {
public:
    static std::vector<unsigned char> generateKey(size_t length);
    static void printKey(const std::vector<unsigned char>& key);
};

#endif // KEYGENERATOR_H
