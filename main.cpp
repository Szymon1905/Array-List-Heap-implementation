#include <iostream>
#include <Windows.h>
#include "Opcje.h"
#include "Testy.h"
#include "Lista.h"
#include "Kopiec.h"

using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8); // Konsola ustwiona na utf-8 aby były Polskie litery
    cout << "Autor: Szymon Borzdyński" << endl;


    Testy testy;
    Opcje opcja;
    int opcja_poczatkowa;


    while (true) {
        cout << "Opcje:" << endl;
        cout << "1 - Tablica Dynamiczna" << endl;
        cout << "2 - Lista Dwukierunkowa" << endl;
        cout << "3 - Kopiec Binarny" << endl;
        cout << "4 - Testy" << endl;
        cout << "5 - Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> opcja_poczatkowa;
        //system("CLS");


        switch (opcja_poczatkowa) {
            default:
                //system("CLS");
                cout << "Błędna opcja 1" << endl<<endl;
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
                cout << "3 - Stary_Kopiec Binarny" << endl;
                cin >> opcja_testu;
                switch (opcja_testu) {
                    case 1:
                        testy.testTablicy();
                        continue;
                    case 2:
                        testy.testListy();
                        continue;
                    case 3:
                        // TODO sprawdzić czy to działa
                        // update: Nie
                        testy.testKopca();
                        continue;
                    default:
                        //system("CLS");
                        cout << "Błędna opcja 2 " << endl<<endl;
                }

            case 5:
                return 0;

                // TODO wywalić case 6
            case 6:
                // Testy kocpa
                Kopiec_binarny kopiecus;

                kopiecus.dodaj(10);
                kopiecus.dodaj(20);
                kopiecus.dodaj(15);
                kopiecus.dodaj(30);
                kopiecus.dodaj(25);
                kopiecus.dodaj(17);
                kopiecus.dodaj(18);
                kopiecus.dodaj(100);
                kopiecus.dodaj(10);
                kopiecus.dodaj(16);

                kopiecus.wypisz_kopiec();

                kopiecus.usun_ze_szczytu();

                kopiecus.wypisz_kopiec();

                kopiecus.usun_ze_szczytu();

                kopiecus.wypisz_kopiec();

                kopiecus.usun_ze_szczytu();

                kopiecus.wypisz_kopiec();

                kopiecus.usun_ze_szczytu();

                kopiecus.wypisz_kopiec();

                string czekaj;
                cin>>czekaj;
                return 0;
        }
    }
}
