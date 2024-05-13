#include <iostream>
#include "GenerowanieKluczaGlownego.h"
#include "OczytIPodzialNaBajty.h"
#include <fstream>
#include "XorBinarnieKP.h"
#include "SubBytes.h"

using namespace std;

extern vector<string> hexadecymalne;

int main()
{
    ofstream MyFile("kluczGlowny.txt"); //utworznie pliku

    int rozmiarKlucza = 16;

    string KluczSzesnastkowo = KluczGlownyGenerator(rozmiarKlucza);

    cout << "Wygenerowany klucz w formacie szesnastkowym: " << KluczSzesnastkowo << endl;

    MyFile << KluczSzesnastkowo; // zapisanie wygenerowanego klucza do pliku (ndapisuje co jest w pliku)

    vector<char> macierzBajtow = odczytajPlik("krokiotwarciaplikow.txt");

    XorBinarnieKP xorBinarnieKP(hexadecymalne, KluczSzesnastkowo);
    xorBinarnieKP.XorKluczaIPliku();

    // Wyświetl wyniki XOR
    const vector<string>& wynikXOR = xorBinarnieKP.getWynikXOR();
    for (const auto& wynik : wynikXOR) {
        cout << wynik << " ";
    }
    cout << endl;

    return 0;
}
