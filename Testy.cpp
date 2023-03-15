#include <iostream>
#include "Testy.h"
#include "Tablica.h"
#include "Lista.h"


//#include "Kopiec.h"
//#include "Drzewo.h"

using namespace std;


void Testy::testTablicy() {
    Czas czas;
    Tablica tablica;
    int wybor = NULL;
    int wartosc;
    int pozycja;

    while (true) {
        cout << "Opcje:" << endl;
        cout << "1 - Dodaj element na początek" << endl;
        cout << "2 - Dodaj element na koniec" << endl;
        cout << "3 - Dodaj element na wybraną pozycję" << endl;
        cout << "4 - Usuń element na początku" << endl;
        cout << "5 - Usuń element na końcu" << endl;
        cout << "6 - Usuń element na wybranym miejscu" << endl;
        cout << "7 - Wyszukaj element" << endl;
        cout << "8 - Wypisz tablicę" << endl;
        cout << "9 - Wyjście" << endl;

        cout << endl;
        cout << "Wybór: ";
        cin >> wybor;
        system("CLS");
        cout<<"Wybrano"<<wybor<<endl;
        switch (wybor) {
            case 1:

                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                tablica.dodaj_na_poczatek(wartosc);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                tablica.dodaj_na_koniec(wartosc);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                tablica.dodaj_na_pozycje(wartosc, pozycja);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 4:
                czas.czasStart();
                tablica.usun_pierwszy();
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 5:
                czas.czasStart();
                tablica.usun_ostatni();
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                tablica.usun_na_pozycji(pozycja);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                tablica.znajdz_element(wartosc);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 8:
                czas.czasStart();
                tablica.wypisz_tablice();
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 9:
                return;

            default:
                cout << "Błędna opcja" << endl;
                break;
        }
    }
}

void Testy::testListy() {
    Czas czas;
    Lista lista;
    int wybor;
    int wartosc;
    int pozycja;

    while (true) {
        cout << "Wybierz funkcję listy:" << endl;
        cout << "1 - Dodaj na początek" << endl;
        cout << "2 - Dodaj na koniec" << endl;
        cout << "3 - Dodaj na na wybraną pozycję" << endl;
        cout << "4 - Usuń pierwszy" << endl;
        cout << "5 - Usuń ostatni" << endl;
        cout << "6 - Usuń którykolwiek" << endl;
        cout << "7 - Wyszukaj element" << endl;
        cout << "8 - Wydrukuj listę" << endl;
        cout << "9 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;
        system("CLS");

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                lista.dodaj_na_poczatek(wartosc);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                lista.dodaj_na_koniec(wartosc);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                lista.dodaj_na_pozycje(wartosc, pozycja);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 4:
                czas.czasStart();
                lista.usun_pierwszy();
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 5:
                czas.czasStart();
                lista.usun_ostatni();
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                lista.usun_na_pozycji(pozycja);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                lista.znajdz_element(wartosc);
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 8:
                czas.czasStart();
                lista.wypisz_liste();
                czas.czasStop();
                czas.czasWykonania();
                break;

            case 9:
                return;
        }
    }
}





