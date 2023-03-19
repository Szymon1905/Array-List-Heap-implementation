
#include <iostream>



using namespace std;

class element{

public:
    element *nastepny;
    element *poprzedni;
    int wartosc;

    element(int, element *, element *);
};



class Lista {

public:

    int rozmiar;

    Lista();

    ~Lista();

    element *pierwszyElement;
    element *ostatniElement;
    element *aktualnyElement;

    void dodaj_na_poczatek(int wartosc);

    void dodaj_na_koniec(int wartosc);

    void dodaj_na_pozycje(int wartosc, int pozycja);

    void wypisz_liste();

    void usun_pierwszy();

    void usun_ostatni();

    void usun_na_pozycji(int);

    void usun_na_pozycji_test(int);

    void usun_na_pozycji_test2(int);

    bool znajdz_element(int wartosc);
};

