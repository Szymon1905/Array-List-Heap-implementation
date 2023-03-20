#include <iostream>
#include "Tablica.h"

using namespace std;
// TODO refactor tablicy

//Konstruktor
Tablica::Tablica() {

    Tablica::wskaznik = NULL;
    Tablica::rozmiar = 0;

}

//Destruktor
Tablica::~Tablica() {

    if (wskaznik != NULL) {
        delete[]wskaznik;
    }
}

void Tablica::dodaj_na_poczatek(int wartosc) {

    //Alokuje pamięć na tablicę o jeden większą
    int *nowy_wskaznik = new int[rozmiar + 1];

    //Przypisuje nowy pierwszy element
    nowy_wskaznik[0] = wartosc;

    //Przepisuje dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiar; i++) {
        nowy_wskaznik[i + 1] = wskaznik[i];
    }

    //Zwalniam pamięć po starej tablicy
    delete wskaznik;

    //Daje wskaźnik na nowy
    wskaznik = nowy_wskaznik;

    //Zwiększam rozmiar tablicy
    rozmiar++;

}

void Tablica::dodaj_na_koniec(int wartosc) {

    //Alokuje pamięć na tablicę o jeden większą
    int *nowy_wskaznik = new int[rozmiar + 1];

    //Przypisuje nowy ostatni element
    nowy_wskaznik[rozmiar] = wartosc;

    //Przepisuje dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiar; i++) {
        nowy_wskaznik[i] = wskaznik[i];
    }

    //Zwalniam pamięć po starej tablicy
    delete wskaznik;

    //Daje wskaźnik na nowy
    wskaznik = nowy_wskaznik;

    //Zwiększam rozmiar tablicy
    rozmiar++;

}

void Tablica::dodaj_na_pozycje(int wartosc, int pozycja) {
    //Sprawdam czy taka pozycja jest w tablicy
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    } else {

        //Alokuje pamięć na tablicę o jeden większą
        int *nowy_wskaznik = new int[rozmiar + 1];

        //Przypisuje wartość jako inne_elementy tablicy na wybranej pozycji
        nowy_wskaznik[pozycja] = wartosc;

        //Przepisuje dane przed pozycją ze starej do nowej tablicy
        for (int i = 0; i < pozycja; i++) {
            nowy_wskaznik[i] = wskaznik[i];
        }

        //Przepisuje dane po pozycji ze starej do nowej tablicy
        for (int i = pozycja; i < rozmiar; i++) {
            nowy_wskaznik[i + 1] = wskaznik[i];
        }

        //Zwalniam pamięć po starej tablicy
        delete wskaznik;

        //Daje wskaźnik na nowy
        wskaznik = nowy_wskaznik;

        //Zwiększam rozmiar tablicy
        rozmiar++;

    }

}

void Tablica::usun_ostatni() {
    //Sprawdzam, czy tablica nie jest pusta
    if (rozmiar > 0) {
        //Alokuje pamięć na tablicę o jeden mniejszą
        int *nowy_wskaznik = new int[rozmiar - 1];

        //Przepisuje elementy starej tablicy bez ostatniego
        for (int i = 0; i < rozmiar - 1; i++) {
            nowy_wskaznik[i] = wskaznik[i];
        }

        //Zwalniam pamięć po starej tablicy
        delete[] wskaznik;

        //Daje wskaźnik na nowy
        wskaznik = nowy_wskaznik;

        //Zmniejszam rozmiar tablicy
        rozmiar--;
    } else {
        cout << "tablica jest pusta" << endl;
    }

}

void Tablica::usun_pierwszy() {

    //Sprawdam, czy tablica nie jest pusta
    if (rozmiar > 0) {
        //Alokuje pamięć na tablicę o jeden mniejszą
        int *nowy_wskaznik = new int[rozmiar - 1];

        //Przepisuje elementy starej tablicy bez pierwszego
        for (int i = 0; i < rozmiar - 1; i++) {
            nowy_wskaznik[i] = wskaznik[i + 1];
        }

        //Zwalniam pamięć po starej tablicy
        delete[] wskaznik;

        //Daje wskaźnik na nowy
        wskaznik = nowy_wskaznik;

        //Zmniejszam rozmiar tablicy
        rozmiar--;
    } else {
        cout << "W tablicy nie ma żadnego elementu!" << endl;
    }

}

void Tablica::usun_na_pozycji(int pozycja) {

    //Sprawdzam, czy tablica nie jest pusta i czy pozycja jest prawidłowa
    if (rozmiar > 0 || pozycja > 0 || pozycja < rozmiar) {
        //Alokuje pamięć na tablicę o jeden mniejszą
        int *nowy_wskaznik = new int[rozmiar - 1];

        //Przepisuje dane do pozycji ze starej do nowej tablicy
        for (int i = 0; i < pozycja; i++) {
            nowy_wskaznik[i] = wskaznik[i];
        }

        //Przepisuje dane po pozycji ze starej do nowej tablicy
        for (int i = pozycja; i < rozmiar - 1; i++) {
            nowy_wskaznik[i] = wskaznik[i + 1];
        }

        //Zwalniam pamięć po starej tablicy
        delete[] wskaznik;

        //Daje wskaźnik na nowy
        wskaznik = nowy_wskaznik;

        //Zmniejszam rozmiar tablicy
        rozmiar--;
    } else {
        cout << "Nie ma takiej pozycji" << endl;
    }
}

bool Tablica::znajdz_element(int wartosc) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < rozmiar; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (wskaznik[i] == wartosc) {
            cout << "wartość jest na pozcyji: "<< i << endl;
            return true;
        }
    }

    cout << "Nie ma takiej wartości w tablicy" << endl;
    return false;
}

void Tablica::wypisz_tablice() {
    cout << "Tablica:" << endl;

    //Sprawdzam czy wskaznik nie jest null i wypisuje tablice
    if (wskaznik != NULL) {
        for (int i = 0; i < rozmiar; i++) {
            cout << "    [" << i << "] " << wskaznik[i] << endl;
        }
    } else {
        cout << "    Tablica nie ma żadnych elementów" << endl;
    }
}

