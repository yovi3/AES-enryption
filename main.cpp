#include <iostream>
#include "GenerowanieKluczaGlownego.h"
#include "OczytIPodzialNaBajty.h"
#include <fstream>

using namespace std;

int main()
{
    ofstream MyFile("kluczGlowny.txt"); //utworznie pliku
    int rozmiarKlucza = 16;
    string KluczSzesnastkowo = KluczGlownyGenerator(rozmiarKlucza);
    cout << "Wygenerowany klucz w formacie szesnastkowym: " << KluczSzesnastkowo << endl;
    
    MyFile << KluczSzesnastkowo; // zapisanie wygenerowanego klucza do pliku (ndapisuje co jest w pliku)

    vector<char> macierzBajtow = odczytajPlik("krokiotwarciaplikow.txt");
    
    return 0;
}
