#include <iostream>
#include <Windows.h>
#include "Opcje.h"
using namespace std;


//#include "TestyAutomatyczne.h"



int main() {
    cout << "Autor: Szymon Borzdyński" << endl;
    //Inicjalizacja klasy testującej
    //TestyAutomatyczne testyAutomatyczne;

    SetConsoleOutputCP(CP_UTF8);

    int opcja_poczatkowa;
    Opcje opcja;

    // Menu
    while (true) {
        cout << "Opcje:" << endl;
        cout << "1 - Tablica Dynamiczna" << endl;
        cout << "2 - Lista dwukierunkowa" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Drzewo Czerowno-Czarne" << endl;
        cout << "5 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja_poczatkowa;
        system("CLS");


        //cout << "Automatyzować test? (t/n): ";
        //cin >> tn;

        switch (opcja_poczatkowa) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 1:
                cout << "Tablica dynamiczna" << endl;
                opcja.opcja_tablica();
                //testyAutomatyczne.opcja_tablica();
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
                cout << "Drzewo czerwono-czarne" << endl;
                //Opcje.testDrzewa();
                break;

            case 5:
                return 0;
        }
    }
}
