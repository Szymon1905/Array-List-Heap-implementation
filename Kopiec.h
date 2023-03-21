#include <vector>
#include <iostream>

class Kopiec_binarny {
    std::vector<int> kopiec;
    int rozmiar_kopca=0;

public:
    Kopiec_binarny() {}

    void popraw(int);

    int usun_ze_szczytu();

    void wypisz_kopiec();

    void dodaj(int value);

    void czy_istnieje(int wartosc);

    void kopiec_w_ASCII_do_prawej();

    void kopiec_w_ASCII2_do_srodka();
};
