
#include <iostream>



using namespace std;

class inne_elementy{

public:
    inne_elementy *nastepny;
    inne_elementy *poprzedni;
    int wartosc;

    inne_elementy(int, inne_elementy *, inne_elementy *);
};



class Lista {

public:

    int rozmiar;

    Lista();

    ~Lista();

    inne_elementy *pierwszyElement;
    inne_elementy *ostatniElement;
    inne_elementy *aktualnyElement;

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

