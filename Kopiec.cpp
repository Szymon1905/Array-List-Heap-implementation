#include <vector>
#include <iostream>
#include "Kopiec.h"

using namespace std;

//TODO refactor nazw

// Poprawia struktrurę aby był zachowany warunek kopca
void Kopiec_binarny::popraw(int indeks) {
    int lewy = indeks * 2 + 1;
    int prawy = indeks * 2 + 2;
    int najwiekszy = indeks;

    if (lewy < kopiec.size() && kopiec[lewy] > kopiec[najwiekszy]) {
        najwiekszy = lewy;
    }

    if (prawy < kopiec.size() && kopiec[prawy] > kopiec[najwiekszy]) {
        najwiekszy = prawy;
    }

    if (najwiekszy != indeks) {
        swap(kopiec[indeks], kopiec[najwiekszy]);
        popraw(najwiekszy);
    }
}



void Kopiec_binarny::dodaj(int value) {
    kopiec.push_back(value);

    int index = kopiec.size() - 1;
    int parent = (index - 1) / 2;

    while (index > 0 && kopiec[parent] < kopiec[index]) {
        swap(kopiec[parent], kopiec[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

int Kopiec_binarny::usun_ze_szczytu() {
    if (kopiec.empty()) {
        cerr << "Heap is empty" << endl;
        return -1;
    }

    int szczyt = kopiec[0];
    kopiec[0] = kopiec.back();
    kopiec.pop_back();
    popraw(0);

    return szczyt;
}

// TODO Buchalski kazał wypisac to jak w ASCII
void Kopiec_binarny::wypisz_kopiec() {
    for (int i = 0; i < kopiec.size(); ++i) {
        cout << kopiec[i] << " ";
    }
    cout << endl;
}

void Kopiec_binarny::czy_istnieje(int wartosc) {
    for (int i = 0; i < kopiec.size(); ++i) {
        if (kopiec[i] == wartosc) {
            cout << "wartość jest na pozycji: "<< i << endl;
        }
    }
    cout << "Nie ma takiej wartości w kopcu" << endl;
}



