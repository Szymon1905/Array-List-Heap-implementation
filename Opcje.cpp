#include <iostream>
#include "Opcje.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"

//#include "Drzewo.h"

using namespace std;


void Opcje::opcja_tablica() {
    Czas czas;
    Tablica tablica;
    int wybor = NULL;
    int wartosc;
    int pozycja;

    while (true) {
        cout << "Opcje tablicy:" << endl;
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
                czas.Start();
                tablica.dodaj_na_poczatek(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                tablica.dodaj_na_koniec(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.Start();
                tablica.dodaj_na_pozycje(wartosc, pozycja);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 4:
                czas.Start();
                tablica.usun_pierwszy();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 5:
                czas.Start();
                tablica.usun_ostatni();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.Start();
                tablica.usun_na_pozycji(pozycja);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                tablica.znajdz_element(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 8:
                czas.Start();
                tablica.wypisz_tablice();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 9:
                return;

            default:
                cout << "Błędna opcja" << endl;
                break;
        }
    }
}

void Opcje::opcje_listy() {
    Czas czas;
    Lista lista;
    int wybor;
    int wartosc;
    int pozycja;

    while (true) {
        cout << "Opcje listy:" << endl;
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

            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                lista.dodaj_na_poczatek(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                lista.dodaj_na_koniec(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.Start();
                lista.dodaj_na_pozycje(wartosc, pozycja);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 4:
                czas.Start();
                lista.usun_pierwszy();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 5:
                czas.Start();
                lista.usun_ostatni();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.Start();
                lista.usun_na_pozycji(pozycja);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                lista.znajdz_element(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 8:
                czas.Start();
                lista.wypisz_liste();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 9:
                return;

            default:
                cout << "Błędna opcja" << endl;
                break;
        }
    }
}

void Opcje::opcje_kopca() {
    Czas czas;
    Kopiec kopiec;
    int wybor;
    int wartosc;
    while (true) {
        cout << "Opcje Kopca:" << endl;
        cout << "1 - Dodaj" << endl;
        cout << "2 - Usuń" << endl;
        cout << "3 - Wyszukaj" << endl;
        cout << "4 - Wypisz kopiec" << endl;
        cout << "5 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                kopiec.dodaj(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                kopiec.usun(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.Start();
                kopiec.sprawdzCzyIstnieje(wartosc);
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 4:
                czas.Start();
                kopiec.wydrukujKopiec();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

            case 5:
                return;

            default:
                cout << "Błędna opcja" << endl;
                break;
        }
    }
}





