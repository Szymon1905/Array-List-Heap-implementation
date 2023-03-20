#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib> // for the system function
#include <direct.h> // for mkdir and chdir on Windows
#include <random>
#include "Czasomierz.h"
#include "Tablica.h"
#include "Lista.h"
#include "Stary_Kopiec.h"
#include "Testy.h"
#include "Kopiec.h"
using namespace std;

// Każdy test dla 100 losowych wartości w przedziale 1-100

int losuj(int rozmiar) {
    if (rozmiar == 0){
        return 0;
    }

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(0, rozmiar);
    int randomNum = dist(gen);

    return randomNum;
}

// TODO elimninacja plik

void Testy::testTablicy() {
    srand(time(NULL));
    Czasomierz czas;
    Tablica tablica;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;


    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test tablicy " << endl;

    const char *folder = "Wyniki_tablicy";
    _mkdir(folder);
    _chdir(folder);

    daneWyjsciowe = "dodaj_na_poczotek.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
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
    plikWyjsciowy.close();

    daneWyjsciowe = "dodaj_na_koniec.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.dodaj_na_koniec(wartosc);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "dodaj_na_pozycje.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.dodaj_na_pozycje(wartosc, rand() % tablica.rozmiar);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun_pierwszy.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        //Wypełnia tablicę wartościami


        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_pierwszy();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun_ostatni.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_ostatni();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun_na_pozycji.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        tablica.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        tablica.usun_na_pozycji(rand() % tablica.rozmiar);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    } else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
    chdir("..");
}

void Testy::testListy(){
    Czasomierz czas;
    Lista lista;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test listy " << endl;

    const char *folder = "Wyniki_listy";
    _mkdir(folder);
    _chdir(folder);

    daneWyjsciowe = "dodaj_na_poczatek.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    while (plikWejsciowy.good()) {
        //Wczytaj wartość z pliku
        plikWejsciowy >> wartosc;
        //Wykonaj funkcję z pomiarem
        czas.Start();
        lista.dodaj_na_poczatek(wartosc);
        czas.Stop();
        //Zapisz do pliku wynik pomiaru
        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "dodaj_na_koniec.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        lista.dodaj_na_koniec(wartosc);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "dodaj_na_pozycje.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);

    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        lista.dodaj_na_pozycje(wartosc,0);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun_pierwszy.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        lista.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        lista.usun_pierwszy();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun_ostatni.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        lista.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        lista.usun_ostatni();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun_na_pozycji.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        lista.dodaj_na_poczatek(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        lista.usun_na_pozycji_test2(losuj(lista.rozmiar));
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    } else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
    chdir("..");
}

// TODO fix funkcji losującej

void Testy::testKopca(){
    Czasomierz czas;
    Kopiec_binarny kopiec;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe = "wejscie_100.txt";
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    plikWejsciowy.open(daneWejsciowe);
    if (plikWejsciowy.is_open()) {
        cout << "Otwarto plik " << daneWejsciowe << endl;
    } else {
        cout << "Nie udało się otworzyć pliku wejściowego" << endl;
        return;
    }

    cout << "Uruchomiono Test Kopca " << endl;

    const char *folder = "Wyniki_kopiec";
    _mkdir(folder);
    _chdir(folder);

    daneWyjsciowe = "dodaj.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    while (plikWejsciowy.good()) {
        //Wczytaj wartość z pliku
        plikWejsciowy >> wartosc;
        //Wykonaj funkcję z pomiarem
        czas.Start();
        kopiec.dodaj(wartosc);
        czas.Stop();
        //Zapisz do pliku wynik pomiaru
        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    daneWyjsciowe = "usun.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        kopiec.dodaj(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        kopiec.usun_ze_szczytu();
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();


    daneWyjsciowe = "sprawdzCzyIstnieje.txt";
    plikWyjsciowy.open(daneWyjsciowe, fstream::out);
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;
        kopiec.dodaj(wartosc);
    }
    plikWejsciowy.seekg(0, std::ios::beg);
    while (plikWejsciowy.good()) {
        plikWejsciowy >> wartosc;

        czas.Start();
        kopiec.czy_istnieje(wartosc);
        czas.Stop();

        plikWyjsciowy << czas.czas_do_pliku() << " ns" << endl;
    }
    plikWyjsciowy.close();

    char sciezka_wyjscia[1024];
    if (getcwd(sciezka_wyjscia, sizeof(sciezka_wyjscia)) != nullptr) {
        cout << "Dane wyjściowe zapisano w: " << sciezka_wyjscia << '\n';
    } else {
        cerr << "Nie udało sie otworzyć ścieżki.\n";
        return;
    }

    plikWejsciowy.close();
}




//plikWejsciowy.close();
//chdir("..");
//return;
// TODO usun_ze_szczytu

// Szymon Borzdyński 19.03.2023