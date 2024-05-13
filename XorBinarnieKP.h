#pragma once
#include <vector>
#include <string>

using namespace std;

class XorBinarnieKP {
public:
    XorBinarnieKP(const vector<string>& hexadecymalne, const string& KluczSzesnastkowo);
    void XorKluczaIPliku();
    string hex_xor(const string& hex1, const string& hex2);
    vector<string> getWynikXOR() const { return wynikXOR; } // getter do odczytu wyników XOR
private:
    vector<string> hexadecymalne;
    string KluczSzesnastkowo;
    vector<string> wynikXOR; // wektor do przechowywania wyników XOR
};
