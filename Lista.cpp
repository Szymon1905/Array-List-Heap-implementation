#include <iostream>
#include "Lista.h"
#include <cmath>
using namespace std;

Lista::Lista() {
    Lista::pierwszy_element = NULL;
    Lista::aktualny_element = NULL;
    Lista::ostatni_element = NULL;
    Lista::rozmiar = 0;
}
// TODO refactor listy i komentarzy
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
    if (pierwszy_element == NULL) {
        //Tworzę nowy element i ustawiam go jako początkowy i końcowy
        pierwszy_element = new elementy_listy(wartosc, NULL, NULL);
        ostatni_element = pierwszy_element;

    } else {
        //Ustawiam element ktory był pierwszy na aktualny
        aktualny_element = pierwszy_element;

        // TODO URGENT FIX TUTAJ
        //Ustaw jego wartość oraz elementy_listy kolejny na elementy_listy aktualny (były pierwszy)
        //Zastępuje pierwszy element nowym
        pierwszy_element = new elementy_listy(wartosc, aktualny_element, NULL);
        aktualny_element->poprzedni = pierwszy_element;

    }

    //Zwiększam rozmiar listy
    rozmiar = rozmiar + 1;

}

void Lista::dodaj_na_koniec(int wartosc) {
    //Sprawdzam, czy istnieje element początkowy
    if (pierwszy_element == NULL) {
        //Tworzę nowy element i ustawiam go jako element początkowy i końcowy
        ostatni_element = new elementy_listy(wartosc, NULL, NULL);
        pierwszy_element = ostatni_element;

    } else {
        //Ustawiam ostatni element jako aktualny
        aktualny_element = ostatni_element;

        // TODO URGENT FIX TUTAJ 2
        //Zastąp ostatni elementy_listy nowym
        //Ustaw jego wartość oraz elementy_listy poprzedni na elementy_listy aktualny (były ostatni)
        ostatni_element = new elementy_listy(wartosc, NULL, aktualny_element);
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

        //Przypisz za aktualny elementy_listy pierwszy
        aktualny_element = pierwszy_element;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualny_element = aktualny_element->nastepny;
        }

    } else {

        //Przypisuje za ostatni jako aktualny
        aktualny_element = ostatni_element;

        //Przesuwam wszystkie elementy o jedną pozycję do tyłu
        for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
            aktualny_element = aktualny_element->poprzedni;
        }

    }

    //Stwórz nowy elementy_listy listy z podanymi parametrami
    elementy_listy *nowy_element = new elementy_listy(wartosc, aktualny_element,
                                                      aktualny_element->nastepny);

    //przypisz nowy elementy_listy w odpowiednim miejscu tablicy
    aktualny_element->nastepny->poprzedni = nowy_element;
    aktualny_element->nastepny = nowy_element;

    //Zwiększ rozmiar listy
    rozmiar = rozmiar + 1;
}

void Lista::usun_pierwszy() {

    //przypisz drugi elementy_listy jako aktualny
    aktualny_element = pierwszy_element->nastepny;

    //Usuń pierwszy elementy_listy
    delete pierwszy_element;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny elementy_listy jako pierwszy
    //Jeżeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualny_element->poprzedni = NULL;
        pierwszy_element = aktualny_element;
    } else {
        aktualny_element = NULL;
        pierwszy_element = NULL;
        ostatni_element = NULL;
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
        aktualny_element->nastepny = NULL;
        ostatni_element = aktualny_element;
    } else {
        aktualny_element = NULL;
        pierwszy_element = NULL;
        ostatni_element = NULL;
    }

    //Zmniejszam rozmiar listy
    rozmiar--;

}

// TODO usunąć starą metode
void Lista::usun_na_pozycji_stare(int pozycja) {
//Sprawdź czy w liście istnieje pozycja podana przez użytkownika
    if (pozycja < 0 || pozycja >= rozmiar) {
        cout << "W liście nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawdź czy wybrana pozycja jest pierwszą
    if (pozycja == 0) {
        usun_pierwszy();
        return;
    }

    //Sprawdź czy wybrana pozycja jest ostatnią
    if (pozycja == rozmiar - 1) {
        usun_ostatni();
        return;
    }

    //Sprawdź w której połowie listy znajduje się wybrany elementy_listy
    if (pozycja < ceil(rozmiar / 2)) {
        //Przypisz za aktualny elementy_listy pierwszy
        aktualny_element = pierwszy_element;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualny_element = aktualny_element->nastepny;
        }
    } else {
        //Przypisz za aktualny elementy_listy ostatni
        aktualny_element = ostatni_element;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
            aktualny_element = aktualny_element->poprzedni;
        }
    }
    //Stwórz nowy elementy_listy listy z podanymi parametrami
    elementy_listy *nowyElementListy = aktualny_element->nastepny;

    //przypisz nowy elementy_listy w odpowiednim miejscu tablicy
    aktualny_element->nastepny = nowyElementListy->nastepny;
    aktualny_element->nastepny->poprzedni = nowyElementListy;

    delete[]nowyElementListy;

    //Zmniejsz rozmiar listy
    rozmiar--;

}

void Lista::usun_na_pozycji_test(int pozycja) {
    if (pozycja < 1 || pozycja > rozmiar) { // sprawdzenie czy pozycja jest w zakresie listy
        std::cout << "Nieprawidlowa pozycja!" << std::endl;
        return;
    }
    if (pozycja == 1) { // usuwanie pierwszego elementu
        usun_pierwszy();
        return;
    }
    if (pozycja == rozmiar) { // usuwanie ostatniego elementu
        usun_ostatni();
        return;
    }
    elementy_listy *poprzedniElement = nullptr;
    aktualny_element = pierwszy_element;
    for (int i = 1; i < pozycja; i++) { // przesuwamy sie do elementu na pozycji do usuniecia
        poprzedniElement = aktualny_element;
        aktualny_element = aktualny_element->nastepny;
    }
    poprzedniElement->nastepny = aktualny_element->nastepny; // usuwam elementy_listy ze srodkowej czesci listy
    aktualny_element->nastepny->poprzedni = poprzedniElement;
    delete aktualny_element;
    rozmiar--;
}

// TODO sprawdzic dla 3 elementow 32,86,53
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

    //Przeszukuje liste
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

// TODO co z tym
elementy_listy::elementy_listy(int wartosc, elementy_listy *nastepny, elementy_listy *poprzedni) {

    elementy_listy::wartosc = wartosc;
    elementy_listy::nastepny = nastepny;
    elementy_listy::poprzedni = poprzedni;

}