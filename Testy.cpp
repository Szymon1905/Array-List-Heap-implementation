#include <iostream>
#include <fstream>
#include <cstdlib> // for the system function
#include <direct.h> // for mkdir and chdir on Windows
#include <unistd.h> // for getcwd
#include "Czas.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Testy.h"

using namespace std;

// Każdy test dla 100 losowych wartości w przedziale 1-100

void Testy::testTablicy() {
    srand(time(NULL));
    Czas czas;
    Tablica tablica;
    int wartosc;
    string daneWyjsciowe = "wyjscie_Tablica.txt";
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);


    const char *folder = "Wyniki_tablicy";
    _mkdir(folder);
    _chdir(folder);

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    } else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWyjsciowy.open(daneWyjsciowe, fstream::out);

    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    if (plikWyjsciowy.is_open()) {
        cout << "Otwarto plik " << daneWyjsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wyjściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test tablicy " << endl;

    plikWyjsciowy = (basic_ofstream<char>) "dodaj_na_poczotek.txt";
    while (plikWejsciowy.good()) {
        //Wczytaj wartość z pliku
        plikWejsciowy >> wartosc;
        //Wykonaj funkcję z pomiarem
        czas.Start();
        tablica.dodaj_na_poczatek(wartosc);
        czas.Stop();
        //Zapisz do pliku wynik pomiaru
        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "dodaj_na_koniec.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.dodaj_na_koniec(wartosc);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "dodaj_na_pozycje.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.dodaj_na_pozycje(wartosc, rand() % tablica.rozmiarTablicy);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "usun_pierwszy.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    while (plikWejsciowy.good()) {
        //Wypełnia tablicę wartościami


        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_pierwszy();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "usun_ostatni.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_ostatni();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "usun_na_pozycji.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_na_pozycji(rand() % tablica.rozmiarTablicy);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }


    plikWejsciowy.close();
    plikWyjsciowy.close();
}
void Testy::testListy(){
    srand(time(NULL));
    Czas czas;
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe = "wyjscie_Tablica.txt";
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);


    const char *folder = "Wyniki_listy";
    _mkdir(folder);
    _chdir(folder);

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    } else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWyjsciowy.open(daneWyjsciowe, fstream::out);

    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    if (plikWyjsciowy.is_open()) {
        cout << "Otwarto plik " << daneWyjsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wyjściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test Listy " << endl;

    plikWyjsciowy = (basic_ofstream<char>) "dodaj_na_poczotek.txt";
    while (plikWejsciowy.good()) {
        //Wczytaj wartość z pliku
        plikWejsciowy >> wartosc;
        //Wykonaj funkcję z pomiarem
        czas.Start();
        tablica.dodaj_na_poczatek(wartosc);
        czas.Stop();
        //Zapisz do pliku wynik pomiaru
        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "dodaj_na_koniec.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.dodaj_na_koniec(wartosc);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "dodaj_na_pozycje.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.dodaj_na_pozycje(wartosc, rand() % tablica.rozmiarTablicy);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "usun_pierwszy.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    while (plikWejsciowy.good()) {
        //Wypełnia tablicę wartościami


        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_pierwszy();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "usun_ostatni.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_ostatni();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }

    plikWyjsciowy = (basic_ofstream<char>) "usun_na_pozycji.txt";
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_na_pozycji(rand() % tablica.rozmiarTablicy);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }


    plikWejsciowy.close();
    plikWyjsciowy.close();

}

void Testy::testKopca(){
    cout << "Uruchomiono Test Kopca " << endl;

}

/*
switch (wybor) {


                //Zamknij oba pliki

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


void Testy::testListy() {
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

void Testy::testKopca() {
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
*/
// Szymon Borzdyński 19.03.2023