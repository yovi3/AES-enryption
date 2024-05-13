#include "XorBinarnieKP.h"
#include <sstream>
#include <iostream>
#include <iomanip> 

using namespace std;

XorBinarnieKP::XorBinarnieKP(const vector<string>& hexadecymalne, const string& KluczSzesnastkowo)
    : hexadecymalne(hexadecymalne), KluczSzesnastkowo(KluczSzesnastkowo) {}

void XorBinarnieKP::XorKluczaIPliku() {
    for (int i = 0; i < hexadecymalne.size(); i += 16) {
        string wynikBloku;
        cout << "Blok przed XOR: ";
        for (int j = 0; j < 16; ++j) {
            cout << hexadecymalne[i + j] << " ";
            string wynik = hex_xor(hexadecymalne[i + j], KluczSzesnastkowo.substr(j * 2, 2));
            wynikBloku += wynik;
        }
        cout << endl;
        wynikXOR.push_back(wynikBloku); // zapisz wynik XOR dla ca³ego bloku do wektora
        cout << "Blok po XOR: " << wynikBloku << endl;
    }
}

string XorBinarnieKP::hex_xor(const string& hex1, const string& hex2) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << (stoi(hex1, nullptr, 16) ^ stoi(hex2, nullptr, 16));
    return ss.str();
}
