#include <iostream>
#include "GenerowanieKluczaGlownego.h"

using namespace std;

int main()
{
    int rozmiarKlucza = 16;
    string KluczSzesnastkowo = KluczGlownyGenerator(rozmiarKlucza);
    cout << "Wygenerowany klucz w formacie szesnastkowym: " << KluczSzesnastkowo << endl;
    return 0;
}
