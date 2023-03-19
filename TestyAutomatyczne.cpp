#include <iostream>
#include <fstream>
#include "TestyAutomatyczne.h"
#include "Czas.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"

using namespace std;

void TestyAutomatyczne::testTablicy() {
    srand(time(NULL));
    Czas czas;
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcję tablicy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/Tablica/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                return;

            case 1:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.dodaj_na_poczatek(wartosc);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.dodaj_na_koniec(wartosc);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.dodaj_na_pozycje(wartosc, rand() % tablica.rozmiarTablicy);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                cout << "Rozpoczynam test automatyczny...";

                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodaj_na_poczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.usun_pierwszy();
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 5:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodaj_na_poczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.usun_ostatni();
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 6:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodaj_na_poczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.usun_na_pozycji(rand() % tablica.rozmiarTablicy);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 7:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    tablica.dodaj_na_poczatek(wartosc);
                }

                for (int i = 0; i < tablica.rozmiarTablicy; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    tablica.znajdz_element(rand() % 2000000 - 1000000);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 8:
                czas.Start();
                tablica.wypisz_tablice();
                czas.Stop();
                cout << "Czas wykonania: " << czas.czas_do_pliku() << "ms" << endl;
                break;
        }

    }
}

void TestyAutomatyczne::testListy() {
    srand(time(NULL));
    Czas czas;
    Lista lista;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;


    while (wybor != 0) {
        cout << "Wybierz funkcję listy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/Lista/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    lista.dodaj_na_poczatek(wartosc);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    lista.dodaj_na_koniec(wartosc);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    // TODO zmienić sposób zapisu
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;

                    if (lista.rozmiar == 0) {
                        czas.Start();
                        lista.dodaj_na_pozycje(wartosc, 0);
                        czas.Stop();
                    } else {
                        czas.Start();
                        lista.dodaj_na_pozycje(wartosc, 1);
                        czas.Stop();
                    }
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodaj_na_poczatek(wartosc);
                }
                while (lista.rozmiar != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    lista.usun_pierwszy();
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 5:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodaj_na_poczatek(wartosc);
                }
                while (lista.rozmiar != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    lista.usun_ostatni();
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 6:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodaj_na_poczatek(wartosc);
                }
                while (lista.rozmiar != 0) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    lista.usun_na_pozycji(rand() % lista.rozmiar);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 7:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    lista.dodaj_na_poczatek(wartosc);
                }

                for (int i = 0; i < lista.rozmiar; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    lista.znajdz_element(rand() % 2000000 - 1000000);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 8:
                czas.Start();
                lista.wypisz_liste();
                czas.Stop();
                czas.Zmierzony_czas();
                break;

        }

    }
}

void TestyAutomatyczne::testKopca() {
    srand(time(NULL));
    Czas czas;
    Kopiec kopiec;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/Kopiec/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    kopiec.dodaj(wartosc);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:


                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    kopiec.usun(wartosc);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                //Wypełnij tablicę wartościami
                while (plikWejsciowy.good()) {
                    plikWejsciowy >> wartosc;
                    kopiec.dodaj(wartosc);
                }

                for (int i = 0; i < kopiec.rozmiar; i++) {
                    //Wykonaj funkcję z pomiarem
                    czas.Start();
                    kopiec.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.Stop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czas_do_pliku() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                czas.Start();
                kopiec.wydrukujKopiec();
                czas.Stop();
                czas.Zmierzony_czas();
                break;
        }

    }
}