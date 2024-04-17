#include "OczytIPodzialNaBajty.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

vector<char> odczytajPlik(const string& nazwa_pliku) {
    // Otw�rz plik w formacie binarnym
    ifstream plik(nazwa_pliku, ios::binary);

    // Wczytaj zawarto�� pliku
    vector<char> bufor(istreambuf_iterator<char>(plik), {});

    // Podziel na bloki po 16 bajt�w
    while (bufor.size() % 16 != 0) {
        bufor.push_back(0);
    }

    // Wydrukuj zawarto�� bufora
    for (size_t i = 0; i < bufor.size(); ++i) {
        cout << hex << setw(2) << setfill('0') << (0xff & static_cast<unsigned char>(bufor[i])) << " ";
        if ((i + 1) % 16 == 0)
            cout << endl;
    }

    return bufor;
}
