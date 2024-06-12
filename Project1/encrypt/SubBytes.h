#ifndef SUBBYTES_H
#define SUBBYTES_H

#include <vector>

class SubBytes {
public:
    static void apply(std::vector<unsigned char>& data);

private:
    static const unsigned char sBox[256];
};

#endif // SUBBYTES_H
