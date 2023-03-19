#include <vector>
#include <iostream>

class Kopiec_binarny {
    std::vector<int> kopiec;

public:
    Kopiec_binarny() {}

    void heapify(int);

    int usun_ze_szczytu();

    void wypisz_kopiec();

    void dodaj(int value);

    bool czy_istnieje(int value);

};
