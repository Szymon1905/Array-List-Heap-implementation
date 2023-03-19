#include <iostream>
#include "Lista.h"
#include <cmath>
using namespace std;

Lista::Lista() {
    Lista::pierwszyElement = NULL;
    Lista::aktualnyElement = NULL;
    Lista::ostatniElement = NULL;
    Lista::rozmiar = 0;
}
// TODO refactor listy i komentarzy
Lista::~Lista() {
    for (int i = 0; i < Lista::rozmiar; i++) {

        //Przypisz kolejny inne_elementy jako aktualny
        aktualnyElement = pierwszyElement->nastepny;
        //Usuń pierwszy inne_elementy
        delete pierwszyElement;

        pierwszyElement = aktualnyElement;
    }
}

void Lista::dodaj_na_poczatek(int wartosc) {

    //Sprawdź, czy istnieje inne_elementy początkowy
    if (pierwszyElement == NULL) {
        //Utwórz nowy inne_elementy i ustaw go jako inne_elementy początkowy i końcowy
        pierwszyElement = new inne_elementy(wartosc, NULL, NULL);
        ostatniElement = pierwszyElement;

    } else {
        //Ustaw inne_elementy ktory był pierwszym jako aktualny
        aktualnyElement = pierwszyElement;
        //Zastąp pierwszy inne_elementy nowym
        //Ustaw jego wartość oraz inne_elementy kolejny na inne_elementy aktualny (były pierwszy)
        pierwszyElement = new inne_elementy(wartosc, aktualnyElement, NULL);
        aktualnyElement->poprzedni = pierwszyElement;

    }

    //Zwiększ rozmiar listy
    rozmiar = rozmiar + 1;

}

void Lista::dodaj_na_koniec(int wartosc) {
    //Sprawdź, czy istnieje inne_elementy początkowy
    if (pierwszyElement == NULL) {
        //Utwórz nowy inne_elementy i ustaw go jako inne_elementy początkowy i końcowy
        ostatniElement = new inne_elementy(wartosc, NULL, NULL);
        pierwszyElement = ostatniElement;

    } else {
        //Ustaw inne_elementy który był ostatnim jako aktualny
        aktualnyElement = ostatniElement;
        //Zastąp ostatni inne_elementy nowym
        //Ustaw jego wartość oraz inne_elementy poprzedni na inne_elementy aktualny (były ostatni)
        ostatniElement = new inne_elementy(wartosc, NULL, aktualnyElement);
        aktualnyElement->nastepny = ostatniElement;
    }
    //Zwiększ rozmiar listy o 1
    rozmiar++;
}

void Lista::dodaj_na_pozycje(int wartosc, int pozycja) {

    //Sprawdź czy wybrana pozycja jest pierwszą
    if (pozycja == 0) {
        Lista::dodaj_na_poczatek(wartosc);
        return;
    }

    //Sprawdź czy w liście istnieje pozycja podana przez użytkownika
    if (pozycja < 0 || pozycja >= rozmiar) {
        cout << "W liście nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }

    //Sprawdź czy wybrana pozycja jest ostatnią
    if (pozycja == rozmiar - 1) {
        dodaj_na_koniec(wartosc);
        return;
    }

    //Sprawdź w której połowie listy znajduje się wybrany inne_elementy
    if (pozycja < rozmiar / 2) { //liczone od indeksu zerowego

        //Przypisz za aktualny inne_elementy pierwszy
        aktualnyElement = pierwszyElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->nastepny;
        }

    } else {

        //Przypisz za aktualny inne_elementy ostatni
        aktualnyElement = ostatniElement;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->poprzedni;
        }

    }

    //Stwórz nowy inne_elementy listy z podanymi parametrami
    inne_elementy *nowyElementListy = new inne_elementy(wartosc, aktualnyElement,
                                                        aktualnyElement->nastepny);

    //przypisz nowy inne_elementy w odpowiednim miejscu tablicy
    aktualnyElement->nastepny->poprzedni = nowyElementListy;
    aktualnyElement->nastepny = nowyElementListy;

    //Zwiększ rozmiar listy
    rozmiar = rozmiar + 1;
}

void Lista::usun_pierwszy() {

    //przypisz drugi inne_elementy jako aktualny
    aktualnyElement = pierwszyElement->nastepny;

    //Usuń pierwszy inne_elementy
    delete pierwszyElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny inne_elementy jako pierwszy
    //Jeżeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualnyElement->poprzedni = NULL;
        pierwszyElement = aktualnyElement;
    } else {
        aktualnyElement = NULL;
        pierwszyElement = NULL;
        ostatniElement = NULL;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;
}

void Lista::usun_ostatni() {

    //Przypisz przedostani inne_elementy jako aktualny
    aktualnyElement = ostatniElement->poprzedni;
    //Usuń ostatni inne_elementy
    delete ostatniElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny inne_elementy jako ostatni
    //Jeżeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualnyElement->nastepny = NULL;
        ostatniElement = aktualnyElement;
    } else {
        aktualnyElement = NULL;
        pierwszyElement = NULL;
        ostatniElement = NULL;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;

}

// TODO usunąć starą metode
void Lista::usun_na_pozycji(int pozycja) {
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

    //Sprawdź w której połowie listy znajduje się wybrany inne_elementy
    if (pozycja < ceil(rozmiar / 2)) {
        //Przypisz za aktualny inne_elementy pierwszy
        aktualnyElement = pierwszyElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->nastepny;
        }
    } else {
        //Przypisz za aktualny inne_elementy ostatni
        aktualnyElement = ostatniElement;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->poprzedni;
        }
    }
    //Stwórz nowy inne_elementy listy z podanymi parametrami
    inne_elementy *nowyElementListy = aktualnyElement->nastepny;

    //przypisz nowy inne_elementy w odpowiednim miejscu tablicy
    aktualnyElement->nastepny = nowyElementListy->nastepny;
    aktualnyElement->nastepny->poprzedni = nowyElementListy;

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
    inne_elementy *poprzedniElement = nullptr;
    aktualnyElement = pierwszyElement;
    for (int i = 1; i < pozycja; i++) { // przesuwamy sie do elementu na pozycji do usuniecia
        poprzedniElement = aktualnyElement;
        aktualnyElement = aktualnyElement->nastepny;
    }
    poprzedniElement->nastepny = aktualnyElement->nastepny; // usuwamy inne_elementy ze srodkowej czesci listy
    aktualnyElement->nastepny->poprzedni = poprzedniElement;
    delete aktualnyElement;
    rozmiar--;
}

void Lista::usun_na_pozycji_test2(int pozycja) {
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
    inne_elementy *poprzedniElement = nullptr;
    aktualnyElement = pierwszyElement;

    while (i < pozycja) {
        poprzedniElement = aktualnyElement;
        aktualnyElement = aktualnyElement->nastepny;
        i++;
    }

    poprzedniElement->nastepny = aktualnyElement->nastepny;
    delete aktualnyElement;
    aktualnyElement = nullptr;
    rozmiar--;
}

bool Lista::znajdz_element(int wartosc) {

    //Jeżeli lista jest pusta, zwróć false z automatu
    if (rozmiar == 0) {
        return false;
    }

    //Przypisa pierwszy inne_elementy jako aktualny
    aktualnyElement = pierwszyElement;

    //Przeszukaj listę pod kątem wartości
    for (int i = 0; i < rozmiar; i++) {
        if (aktualnyElement->wartosc == wartosc) {
            cout << "Szukana wartość zajmuje w liście pozycję [" << i << "]" << endl;
            return true;
        }

        aktualnyElement = aktualnyElement->nastepny;
    }

    //Jeżeli wartość nie wystąpiła w żadnej iteracji listy zwróć false
    cout << "Szukana wartość nie występuje w liście" << endl;
    return false;
}

void Lista::wypisz_liste() {
    if(rozmiar == 0){
        cout << "Lista jest pusta" << endl;
        return;
    }

    //Ustaw jako akutualny inne_elementy pierwszy inne_elementy listy
    aktualnyElement = pierwszyElement;

    for (int i = 0; i < rozmiar; i++) {

        cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

        //Przypisz kolejny inne_elementy listy jako aktualny
        aktualnyElement = aktualnyElement->nastepny;

    }
}

// TODO co z tym
inne_elementy::inne_elementy(int wartosc, inne_elementy *nastepny, inne_elementy *poprzedni) {

    inne_elementy::wartosc = wartosc;
    inne_elementy::nastepny = nastepny;
    inne_elementy::poprzedni = poprzedni;

}