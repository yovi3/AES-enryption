#ifndef MIXCOLUMNS_H
#define MIXCOLUMNS_H

#include <array>
#include <vector>
#include <cstdint>

class MixColumns {
public:
    static void apply(std::vector<uint8_t>& state);

private:
    static const std::array<std::array<uint8_t, 4>, 4> mixMatrix;
    static uint8_t galoisMultiplication(uint8_t a, uint8_t b);
};

#endif // MIXCOLUMNS_H
