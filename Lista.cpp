#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() {
    Lista::pierwszy_element = nullptr;
    Lista::aktualny_element = nullptr;
    Lista::ostatni_element = nullptr;
    Lista::rozmiar = 0;
}

Lista::~Lista() {
    for (int i = 0; i < Lista::rozmiar; i++) {

        //Przepisuje kolejne elementy listy jako aktualne
        aktualny_element = pierwszy_element->nastepny;

        //Usuwam pierwszy elementy_listy
        delete pierwszy_element;

        pierwszy_element = aktualny_element;
    }
}

void Lista::dodaj_na_poczatek(int wartosc) {

    //Sprawdzam, czy pierwszy element istnieje
    if (pierwszy_element == nullptr) {
        //Tworzę nowy element i ustawiam go jako początkowy i końcowy
        pierwszy_element = new elementy_listy(wartosc, nullptr, nullptr);
        ostatni_element = pierwszy_element;

    } else {
        //Ustawiam element ktory był pierwszy na aktualny
        aktualny_element = pierwszy_element;
        pierwszy_element = new elementy_listy(wartosc, aktualny_element, nullptr);
        aktualny_element->poprzedni = pierwszy_element;

    }

    //Zwiększam rozmiar listy
    rozmiar = rozmiar + 1;

}

void Lista::dodaj_na_koniec(int wartosc) {
    //Sprawdzam, czy istnieje element początkowy
    if (pierwszy_element == nullptr) {
        //Tworzę nowy element i ustawiam go jako element początkowy i końcowy
        ostatni_element = new elementy_listy(wartosc, nullptr, nullptr);
        pierwszy_element = ostatni_element;

    } else {
        //Ustawiam ostatni element jako aktualny
        aktualny_element = ostatni_element;
        ostatni_element = new elementy_listy(wartosc, nullptr, aktualny_element);
        aktualny_element->nastepny = ostatni_element;
    }
    //Zwiększam rozmiar listy
    rozmiar++;
}

void Lista::dodaj_na_pozycje(int wartosc, int pozycja) {

    //Sprawdzam czy pozycja jest w liście
    if (pozycja < 0 || pozycja >= rozmiar) {
        cout << "W liście nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }

    //Sprawdzam  pozycja jest pierwsza
    if (pozycja == 0) {
        Lista::dodaj_na_poczatek(wartosc);
        return;
    }

    //Sprawdzam czy pozycja jest ostatnia
    if (pozycja == rozmiar - 1) {
        dodaj_na_koniec(wartosc);
        return;
    }

    //Sprawdzam w której połowie listy znajduje się wybrany elementy_listy
    if (pozycja < rozmiar / 2) { //liczone od indeksu zerowego

        //Przypisuje za aktualny pierwszy element listy za aktualny
        aktualny_element = pierwszy_element;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualny_element = aktualny_element->nastepny;
        }

    } else {

        //Przypisuje aktualny jako ostatni
        aktualny_element = ostatni_element;

        //Przesuwam wszystkie elementy o jedną pozycję do tyłu
        for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
            aktualny_element = aktualny_element->poprzedni;
        }

    }

    //Tworzę nowy element listy z podanymi parametrami
    elementy_listy *nowy_element = new elementy_listy(wartosc, aktualny_element,
                                                      aktualny_element->nastepny);

    //przypisuje nowy element w odpowiednim miejscu w tablicy
    aktualny_element->nastepny->poprzedni = nowy_element;
    aktualny_element->nastepny = nowy_element;

    //Zwiększam rozmiar listy
    rozmiar = rozmiar + 1;
}

void Lista::usun_pierwszy() {

    //przypisuje drugi elementy_listy jako aktualny
    aktualny_element = pierwszy_element->nastepny;

    //Usuwam pierwszy elementy_listy
    delete pierwszy_element;

    if (rozmiar > 1) {
        aktualny_element->poprzedni = nullptr;
        pierwszy_element = aktualny_element;
    } else {
        aktualny_element = nullptr;
        pierwszy_element = nullptr;
        ostatni_element = nullptr;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;
}

void Lista::usun_ostatni() {

    //Przypisuje przedostani element jako aktualny
    aktualny_element = ostatni_element->poprzedni;

    //Usuwam ostatni element listy
    delete ostatni_element;

    //Sprawdzam czy lista nie jest pusta
    if (rozmiar > 1) {
        aktualny_element->nastepny = nullptr;
        ostatni_element = aktualny_element;
    } else {
        aktualny_element = nullptr;
        pierwszy_element = nullptr;
        ostatni_element = nullptr;
    }

    //Zmniejszam rozmiar listy
    rozmiar--;

}


void Lista::usun_na_pozycji(int pozycja) {
    if (pozycja < 0 || pozycja >= rozmiar) {
        cout << "Niepoprawna pozycja" << endl;
        return;
    }

    if (pozycja == 0) {
        usun_pierwszy();
        return;
    }

    if (pozycja == rozmiar - 1) {
        usun_ostatni();
        return;
    }

    int i = 0;
    elementy_listy *poprzedniElement = nullptr;
    aktualny_element = pierwszy_element;

    while (i < pozycja) {
        poprzedniElement = aktualny_element;
        aktualny_element = aktualny_element->nastepny;
        i++;
    }

    poprzedniElement->nastepny = aktualny_element->nastepny;
    delete aktualny_element;
    aktualny_element = nullptr;
    rozmiar--;
}

void Lista::znajdz_element(int wartosc) {

    //sprawdzam czy lista jest pusta
    if (rozmiar == 0) {
        return;
    }

    //Przypisuje pierwszy jako aktualny element
    aktualny_element = pierwszy_element;

    //szukam wartosci w liście
    for (int i = 0; i < rozmiar; i++) {
        if (aktualny_element->wartosc == wartosc) {
            cout << "wartość jest na pozycji: "<< i << endl;
            return;
        }

        aktualny_element = aktualny_element->nastepny;
    }
    cout << "Nie ma takiej wartości w tablicy" << endl;
}

void Lista::wypisz_liste() {
    if(rozmiar == 0){
        cout << "Lista jest pusta" << endl;
        return;
    }

    //Przypisuje pierwszy jako aktualny element
    aktualny_element = pierwszy_element;

    for (int i = 0; i < rozmiar; i++) {

        cout << "[" << i << "] " << aktualny_element->wartosc << endl;

        //Przypisuje kolejne elementy jako aktualne
        aktualny_element = aktualny_element->nastepny;

    }
}

elementy_listy::elementy_listy(int wartosc, elementy_listy *nastepny, elementy_listy *poprzedni) {

    elementy_listy::wartosc = wartosc;
    elementy_listy::nastepny = nastepny;
    elementy_listy::poprzedni = poprzedni;

}