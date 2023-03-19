#include <iostream>
#include <Windows.h>
#include "Opcje.h"
#include "Testy.h"

using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8); // Konsola ustwiona na utf-8 aby były Polskie litery
    cout << "Autor: Szymon Borzdyński" << endl;

    //Inicjalizacja klasy testującej
    Testy testy;

    int opcja_poczatkowa;
    Opcje opcja;

    // Menu
    while (true) {
        cout << "Opcje:" << endl;
        cout << "1 - Tablica Dynamiczna" << endl;
        cout << "2 - Lista Dwukierunkowa" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Testy" << endl;
        cout << "5 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja_poczatkowa;
        system("CLS");


        //cout << "Automatyzować test? (t/n): ";
        //cin >> tn;

        switch (opcja_poczatkowa) {
            default:
                system("CLS");
                cout << "Błędna opcja 2" << endl<<endl;
                break;
            case 1:
                cout << "Tablica dynamiczna" << endl;
                opcja.opcja_tablica();
                break;

            case 2:
                cout <<"Lista dwukierunkowa" << endl;
                opcja.opcje_listy();
                break;

            case 3:
                cout << "Kopiec binarny" << endl;
                opcja.opcje_kopca();
                break;

            case 4:
                int opcja_testu;
                cout << "Testy do pliku" << endl;
                cout << "1 - Tablica Dynamiczna" << endl;
                cout << "2 - Lista Dwukierunkowa" << endl;
                cout << "3 - Kopiec Binarny" << endl;
                cin >> opcja_testu;
                switch (opcja_testu) {
                    case 1:
                        testy.testTablicy();
                        continue;
                    case 2:
                        testy.testListy();
                        continue;
                    case 3:
                        testy.testKopca();
                        continue;
                    default:
                        system("CLS");
                        cout << "Błędna opcja 1 " << endl<<endl;
                }

            case 5:
                return 0;
            case 6:
                testy.testListy();
        }
    }
}


