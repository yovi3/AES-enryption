#include "GenerowanieKluczaGlownego.h" //do��czenie pliku nag��wkowego z deklaracj� funckji
#include <random> //generowanie liczb losowych
#include <sstream> // Biblioteka do obs�ugi strumieni danych.
#include <iomanip>// zmienia system liczb na szesnastkowy

using namespace std;

string KluczGlownyGenerator(int rozmiarKlucza) //generowanie g��wnego klucza w formacie szesnastkowym 16 losowych bajt�w 
{
    random_device rd; // tworzy obiekt kt�re generuje liczby losowe
    mt19937 gen(rd()); // tworzy generator liczb losowych o nazwie gen, kt�ry jest zainicjowany warto�ci� z rd
    uniform_int_distribution<> dis(0, 255);//definiuje rozk�ad r�wnomierny dla liczb ca�kowitych od 0 do 255, kt�re b�d� generowane przez generator dis to nazwa obiektu
    
    stringstream klucz; // kt�ry b�dzie u�ywany do konstrukcji klucza.

    for (int i = 0; i < rozmiarKlucza; ++i) {
        
        int randomByte = dis(gen); // generuje losowy bajt przy u�yciu zdefiniowanego wcze�niej rozk�adu.
        klucz << hex << setw(2) << setfill('0') << randomByte; // konwertuje wygenerowany bajt na warto�� szesnastkow� i dodaje do obiektu key. U�ywane s� manipulatory strumienia hex (zmiana na szesnastkowy), setw (ustawia szeroko�� na 2) i setfill (wype�nia zerami).
    }

    return klucz.str();
}
