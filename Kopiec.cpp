#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Kopiec.h"

using namespace std;


// Poprawia struktrurę aby był zachowany warunek kopca
void Kopiec_binarny::popraw(int indeks) {
    int lewy = indeks * 2 + 1; // Oblicz indeks lewego dziecka
    int prawy = indeks * 2 + 2; // Oblicz indeks prawego dziecka
    int najwiekszy = indeks; // najwiekszy element jest rodzicem

    // Jeśli lewe dziekco istnieje i jest większe niż rodzic to zaktualizuj najwiekszy najwiekszky element
    if (lewy < kopiec.size() && kopiec[lewy] > kopiec[najwiekszy]) {
        najwiekszy = lewy;
    }

    // Jak wyżej ale dla prawego
    if (prawy < kopiec.size() && kopiec[prawy] > kopiec[najwiekszy]) {
        najwiekszy = prawy;
    }

    // jeśli największy element nie jest rodzicem, zamień rodzica z polem z największym elementem i uruchom rekurencje
    if (najwiekszy != indeks) {
        swap(kopiec[indeks], kopiec[najwiekszy]);
        popraw(najwiekszy);
    }
}



void Kopiec_binarny::dodaj(int value) {
    kopiec.push_back(value); // Dodać nowy element na końcu wektora

    int pozycja = kopiec.size() - 1; // pozycja nowego elementu
    int rodzic = (pozycja - 1) / 2; //  pozycja rodzica

    //Jeśli nowy element nie jest na szczycie i wartość jest większa niż rodzic to zamieniam miejscami
    while (pozycja > 0 && kopiec[rodzic] < kopiec[pozycja]) {
        swap(kopiec[rodzic], kopiec[pozycja]);
        pozycja = rodzic;
        rodzic = (pozycja - 1) / 2;
    }
    rozmiar_kopca++; // zwiększam kopiec
}

int Kopiec_binarny::usun_ze_szczytu() {
    if (kopiec.empty()) {
        cerr << "Kopiec jest pusty" << endl;
        return -1;
    }

    int szczyt = kopiec[0]; // wartość kopca
    kopiec[0] = kopiec.back(); // Zamieniam szcyt z ostatnim elementem kopca
    kopiec.pop_back(); // usuwam ostatni element kopca
    popraw(0); // poprawiam kopiec aby jego warunek był zachowany

    rozmiar_kopca--; // zmniejszam kopiec kopiec
    return szczyt; // zwracam rozmiar kopca
}

// stara metoda wypisania kopca
void Kopiec_binarny::wypisz_kopiec() {
    for (int i : kopiec) {
        cout << i << " ";
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


void Kopiec_binarny::kopiec_w_ASCII_do_prawej() {
    cout<<endl;
    int height = floor(log2(kopiec.size())) + 1; // Obliczam wysokość drzewa
    int szerokosc = pow(2, height) * 4; // Obliczam max szerokość wiersza

    int index = 0; // Indeks  węzła
    int current_level = 1; //poziom drzewa
    int current_node_count = 1; // Liczba węzłów na bieżącym poziomie
    while (index < kopiec.size()) { // obliczam ilość spacji
        for (int i = 0; i < current_node_count; i++) {
            if (i == current_node_count - 1) {
                cout << setw(szerokosc / current_node_count) << kopiec[index] << endl;
            } else {
                cout << setw(szerokosc / current_node_count) << kopiec[index];
            }
            index++;

            if (index >= kopiec.size()) { // wyjście z pętli
                break;
            }
        }
        current_level++;  // Przejście do kolejnego poziomu kopca
        current_node_count *= 2; // Liczba węzłów zwiększa się dwukrotnie z kazdym poziomem
    }
}

void Kopiec_binarny::kopiec_w_ASCII2_do_srodka() {
    cout<<endl;
    // obliczam głębokość kopca
    int depth = 0;
    int num_nodes = 1;
    while (num_nodes <= kopiec.size()) {
        depth++;
        num_nodes *= 2;
    }

    // Obliczam szerokość kopca
    int width = pow(2, depth - 1);

    // pętla po każdym poziomie kopca
    for (int level = 0; level < depth; level++) {
        // obliczam liczbę pól
        int pola = pow(2, level);
        // obliczam liczbę spacji polami
        int spacje_pola = width / pola;
        // obliczam liczbę spacji miedy poziomami
        int spacje_poziom = spacje_pola * 2;

        // Wypisuje pola na poziomie
        for (int i = 0; i < pola; i++) {
            int index = pow(2, level) - 1 + i;
            if (index >= kopiec.size()) {
                break;
            }

            //Wypisuje spacje
            cout << string(spacje_pola, ' ') << kopiec[index] << string(spacje_pola, ' ') << string(spacje_poziom, ' ');
        }
        cout << endl;
    }
}




