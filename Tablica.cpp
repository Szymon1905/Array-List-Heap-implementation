#include <iostream>
#include "Tablica.h"

using namespace std;
// TODO refactor tablicy
//Konstruktor inicjalizuje zmienne klasowe
Tablica::Tablica() {

    Tablica::wskaznikNaHead = NULL;
    Tablica::rozmiar = 0;

}

//Destruktor zwalnia pamięć tablicy, jeżeli istnieje
Tablica::~Tablica() {

    if (wskaznikNaHead != NULL) {
        delete[]wskaznikNaHead;
    }
}

void Tablica::dodaj_na_poczatek(int wartosc) {

    //Zaalokuj pamięć na tablicę większa o jeden inne_elementy niż poprzednio
    //Przypisz podaną wartość jako pierwszy inne_elementy tablicy
    int *nowyWskaznikNaHead = new int[rozmiar + 1];
    nowyWskaznikNaHead[0] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiar; i++) {
        nowyWskaznikNaHead[i + 1] = wskaznikNaHead[i];
    }

    //Zwolnij pamięć poprzedniej tablicy
    //Zastąp wskaźnik na głowę tablicy nowym
    delete wskaznikNaHead;
    wskaznikNaHead = nowyWskaznikNaHead;

    //Zwiększ rozmiar tablicy o 1
    rozmiar++;

}

void Tablica::dodaj_na_koniec(int wartosc) {

    //Zaalokuj pamięć na tablicę większa o jeden inne_elementy niż poprzednio
    //Przypisz podaną wartość jako ostatni inne_elementy tablicy
    int *nowyWskaznikNaHead = new int[rozmiar + 1];
    nowyWskaznikNaHead[rozmiar] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiar; i++) {
        nowyWskaznikNaHead[i] = wskaznikNaHead[i];
    }

    //Zwolnij pamięć poprzedniej tablicy
    //Zastąp wskaźnik na głowę tablicy nowym
    delete wskaznikNaHead;
    wskaznikNaHead = nowyWskaznikNaHead;

    //Zwiększ rozmiar tablicy o 1
    rozmiar++;

}

void Tablica::dodaj_na_pozycje(int wartosc, int pozycja) {
    //Sprawdź, czy wybrana pozycja znajduje się w tablicy
    //Jeżeli nie, anuluj dodawanie
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    } else {

        //Zaalokuj pamięć na tablicę większa o jeden inne_elementy niż poprzednio
        //Przypisz podaną wartość jako inne_elementy tablicy na wybranej pozycji
        int *nowyWskaznikNaHead = new int[rozmiar + 1];
        nowyWskaznikNaHead[pozycja] = wartosc;

        //Przepisz dane ze starej tablicy do nowej
        //Przerwij przed wybraną pozycją
        for (int i = 0; i < pozycja; i++) {
            nowyWskaznikNaHead[i] = wskaznikNaHead[i];
        }

        //Uzupełnij dane w tablicy po wybranej pozycji
        //Przepisz dane ze starej tablicy do nowej
        for (int i = pozycja; i < rozmiar; i++) {
            nowyWskaznikNaHead[i + 1] = wskaznikNaHead[i];
        }

        //Zwolnij pamięć poprzedniej tablicy
        //Zastąp wskaźnik na głowę tablicy nowym
        delete wskaznikNaHead;
        wskaznikNaHead = nowyWskaznikNaHead;

        //Zwiększ rozmiar tablicy o 1
        rozmiar++;

    }

}

void Tablica::usun_ostatni() {
    //Sprawdź, czy tablica nie jest pusta
    if (rozmiar > 0) {
        //Zaalokuj pamięć na tablicę mniejszą o jeden inne_elementy niż poprzednio
        int *nowyWskaznikNaHead = new int[rozmiar - 1];

        //Przepisz elementy starej tablicy poza ostatnim
        for (int i = 0; i < rozmiar - 1; i++) {
            nowyWskaznikNaHead[i] = wskaznikNaHead[i];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] wskaznikNaHead;
        wskaznikNaHead = nowyWskaznikNaHead;

        //Zmniejsz rozmiar tablicy o 1
        rozmiar--;
    } else {
        cout << "W tablicy nie ma żadnego elementu!" << endl;
    }

}

void Tablica::usun_pierwszy() {

    //Sprawdź, czy tablica nie jest pusta
    if (rozmiar > 0) {
        //Zaalokuj pamięć na tablicę mniejszą o jeden inne_elementy niż poprzednio
        int *nowyWskaznikNaHead = new int[rozmiar - 1];

        //Przepisz elementy starej tablicy poza pierwszym
        for (int i = 0; i < rozmiar - 1; i++) {
            nowyWskaznikNaHead[i] = wskaznikNaHead[i + 1];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] wskaznikNaHead;
        wskaznikNaHead = nowyWskaznikNaHead;

        //Zmniejsz rozmiar tablicy o 1
        rozmiar--;
    } else {
        cout << "W tablicy nie ma żadnego elementu!" << endl;
    }

}

void Tablica::usun_na_pozycji(int pozycja) {

    //Sprawdź, czy tablica nie jest pusta
    //Sprawdż czy pozycja nie wykracza poza tablicę
    if (rozmiar > 0 || pozycja > 0 || pozycja < rozmiar) {
        //Zaalokuj pamięć na tablicę mniejszą o jeden inne_elementy niż poprzednio
        int *nowyWskaznikNaHead = new int[rozmiar - 1];

        //Przepisz elementy do wybranej pozycji
        for (int i = 0; i < pozycja; i++) {
            nowyWskaznikNaHead[i] = wskaznikNaHead[i];
        }

        //Przepisz elementy po wybranej pozycji
        for (int i = pozycja; i < rozmiar - 1; i++) {
            nowyWskaznikNaHead[i] = wskaznikNaHead[i + 1];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] wskaznikNaHead;
        wskaznikNaHead = nowyWskaznikNaHead;

        //Zmniejsz rozmiar tablicy o 1
        rozmiar--;
    } else {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    }
}

bool Tablica::znajdz_element(int wartosc) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < rozmiar; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (wskaznikNaHead[i] == wartosc) {
            cout << "Szukana wartość zajmuje w tablicy pozycję [" << i << "]" << endl;
            return true;
        }
    }
    //Jeżeli wartość nie wystąpiła w żadnej iteracji tabeli zwróć false
    cout << "Szukana wartość nie występuje w tablicy" << endl;
    return false;
}

void Tablica::wypisz_tablice() {
    cout << "Aktualny stan tablicy:" << endl;
    //Jeżeli tablica nie ma elementów, wyświetl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    if (wskaznikNaHead != NULL) {
        for (int i = 0; i < rozmiar; i++) {
            cout << "    [" << i << "] " << wskaznikNaHead[i] << endl;
        }
    } else {
        cout << "    Tablica nie ma żadnych elementów" << endl;
    }
}

