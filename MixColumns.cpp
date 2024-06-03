#include "MixColumns.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <array>
#include <vector>

const std::array<std::array<uint8_t, 4>, 4> MixColumns::mixMatrix = { {
    {0x02, 0x03, 0x01, 0x01},
    {0x01, 0x02, 0x03, 0x01},
    {0x01, 0x01, 0x02, 0x03},
    {0x03, 0x01, 0x01, 0x02}
} };

uint8_t MixColumns::galoisMultiplication(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; ++i) {
        if (b & 1) {
            p ^= a;
        }
        bool hi_bit_set = a & 0x80;
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1b; // Rijndael's finite field
        }
        b >>= 1;
    }
    return p;
}

void MixColumns::apply(std::vector<uint8_t>& state) {
    if (state.size() != 16) {
        throw std::invalid_argument("State must be 16 bytes");
    }

    for (int c = 0; c < 4; ++c) {
        std::array<uint8_t, 4> a;
        std::array<uint8_t, 4> b;
        for (int i = 0; i < 4; ++i) {
            a[i] = state[i * 4 + c];
        }
        for (int j = 0; j < 4; ++j) {
            b[j] = galoisMultiplication(a[0], mixMatrix[j][0]) ^
                galoisMultiplication(a[1], mixMatrix[j][1]) ^
                galoisMultiplication(a[2], mixMatrix[j][2]) ^
                galoisMultiplication(a[3], mixMatrix[j][3]);
        }
        for (int j = 0; j < 4; ++j) {
            state[j * 4 + c] = b[j];
        }
    }
}
