#include <iostream>

#include <Windows.h>
using namespace std;

#include "Testy.h"
//#include "TestyAutomatyczne.h"



int main() {
    cout << "Autor: Szymon Borzdyński" << endl;
    //Inicjalizacja klasy testującej
    //TestyAutomatyczne testyAutomatyczne;

    SetConsoleOutputCP(CP_UTF8);

    int opcja;
    Testy testy;

    // Menu
    while (true) {
        cout << "Opcje:" << endl;
        cout << "1 - Tablica Dynamiczna" << endl;
        cout << "2 - Lista dwukierunkowa" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Drzewo Czerowno-Czarne" << endl;
        cout << "5 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja;
        system("CLS");


        //cout << "Automatyzować test? (t/n): ";
        //cin >> tn;
        // TODO printf
        switch (opcja) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 1:
                cout << "Tablica dynamiczna" << endl;
                testy.testTablicy();
                //testyAutomatyczne.testTablicy();
                break;

            case 2:
                cout <<"Lista dwukierunkowa" << endl;
                testy.testListy();
                //else Testy.testListy();
                break;

            case 3:
                cout << "Kopiec binarny" << endl;
                testy.testKopca();
                break;

            case 4:
                cout << "Drzewo czerwono-czarne" << endl;
                //if (tn == "t") testyAutomatyczne.testDrzewa();
                //else Testy.testDrzewa();
                break;

            case 5:
                return 0;
        }
    }
}
