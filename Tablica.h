#ifndef PROJEKT_SDIZO_NR_1_SZYMON_BORZDYNSKI_TABLICA_H
#define PROJEKT_SDIZO_NR_1_SZYMON_BORZDYNSKI_TABLICA_H
class Tablica {


public:
//Zmienne
    int *wskaznikNaHead;

    int rozmiarTablicy;

//Metody
    Tablica();

    ~Tablica();

    void dodaj_na_poczatek(int);

    void dodaj_na_koniec(int wartosc);

    void dodaj_na_pozycje(int wartosc, int pozycja);

    void usun_ostatni();

    void usun_pierwszy();

    void usun_na_pozycji(int pozycja);

    void wypisz_tablice();

    bool znajdz_element(int wartosc);
};
#endif //PROJEKT_SDIZO_NR_1_SZYMON_BORZDYNSKI_TABLICA_H
