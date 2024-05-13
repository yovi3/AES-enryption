#include "GenerowanieKluczaGlownego.h" //do³¹czenie pliku nag³ówkowego z deklaracj¹ funckji
#include <random> //generowanie liczb losowych
#include <sstream> // Biblioteka do obs³ugi strumieni danych.
#include <iomanip>// zmienia system liczb na szesnastkowy

using namespace std;

string KluczGlownyGenerator(int rozmiarKlucza) //generowanie g³ównego klucza w formacie szesnastkowym 16 losowych bajtów 
{
    random_device rd; // tworzy obiekt które generuje liczby losowe
    mt19937 gen(rd()); // tworzy generator liczb losowych o nazwie gen, który jest zainicjowany wartoœci¹ z rd
    uniform_int_distribution<> dis(0, 255);//definiuje rozk³ad równomierny dla liczb ca³kowitych od 0 do 255, które bêd¹ generowane przez generator dis to nazwa obiektu
    
    stringstream klucz; // który bêdzie u¿ywany do konstrukcji klucza.

    for (int i = 0; i < rozmiarKlucza; ++i) {
        
        int randomByte = dis(gen); // generuje losowy bajt przy u¿yciu zdefiniowanego wczeœniej rozk³adu.
        klucz << hex << setw(2) << setfill('0') << randomByte; // konwertuje wygenerowany bajt na wartoœæ szesnastkow¹ i dodaje do obiektu key. U¿ywane s¹ manipulatory strumienia hex (zmiana na szesnastkowy), setw (ustawia szerokoœæ na 2) i setfill (wype³nia zerami).
    }

    return klucz.str();
}
