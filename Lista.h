
#include <iostream>



using namespace std;

class ElementListy{

public:
    ElementListy *nastepny;
    ElementListy *poprzedni;
    int wartosc;

    ElementListy(int, ElementListy *, ElementListy *);
};

class Lista {

public:

    int rozmiar;

    Lista();

    ~Lista();

    ElementListy *pierwszyElement;
    ElementListy *ostatniElement;
    ElementListy *aktualnyElement;

    void dodaj_na_poczatek(int wartosc);

    void dodaj_na_pozycje(int wartosc, int pozycja);

    void dodaj_na_koniec(int wartosc);

    void wypisz_liste();

    void usun_pierwszy();

    void usun_ostatni();

    void usun_na_pozycji(int);

    bool znajdz_element(int wartosc);
};

