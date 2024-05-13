#include "OczytIPodzialNaBajty.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;


vector<string> hexadecymalne;  // Globalny wektor do przechowywania wartoœci heksadecymalnych

vector<char> odczytajPlik(const string& nazwa_pliku) {
    // Otwórz plik w formacie binarnym
    ifstream plik(nazwa_pliku, ios::binary);

    // Wczytaj zawartoœæ pliku
    vector<char> bufor(istreambuf_iterator<char>(plik), {});
    vector<char> bufor_binarny = bufor;  // Kopiuj oryginalny bufor

    // Podziel na bloki po 16 bajtów
    while (bufor.size() % 16 != 0) {
        bufor.push_back(0);
    }


    for (size_t i = 0; i < bufor.size(); ++i) {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (0xff & static_cast<unsigned char>(bufor[i]));
        string hexadecymalny = ss.str();
        hexadecymalne.push_back(hexadecymalny);  // Zapisz wartoœæ heksadecymaln¹
    }
    return bufor_binarny;
}
