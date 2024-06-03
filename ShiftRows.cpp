#include "ShiftRows.h"
#include <iostream>

void ShiftRows::apply(std::vector<unsigned char>& state) {
    if (state.size() != 16) {
        throw std::invalid_argument("State must be 16 bytes");
    }

    std::vector<unsigned char> temp(16);

    // Przesuniêcie wierszy (indeksy stanów reprezentuj¹ 4x4 macierz)
    // Wiersz 0: bez zmian
    temp[0] = state[0];
    temp[1] = state[1];
    temp[2] = state[2];
    temp[3] = state[3];

    // Wiersz 1: przesuniêcie o 1 w lewo
    temp[4] = state[5];
    temp[5] = state[6];
    temp[6] = state[7];
    temp[7] = state[4];

    // Wiersz 2: przesuniêcie o 2 w lewo
    temp[8] = state[10];
    temp[9] = state[11];
    temp[10] = state[8];
    temp[11] = state[9];

    // Wiersz 3: przesuniêcie o 3 w lewo
    temp[12] = state[15];
    temp[13] = state[12];
    temp[14] = state[13];
    temp[15] = state[14];

    state = temp;
}
