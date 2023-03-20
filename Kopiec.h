#include <vector>
#include <iostream>

class Kopiec_binarny {
    std::vector<int> kopiec;

public:
    Kopiec_binarny() {}

    void popraw(int);

    int usun_ze_szczytu();

    void wypisz_kopiec();

    void dodaj(int value);

    void czy_istnieje(int wartosc);

};
