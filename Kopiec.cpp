#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Kopiec.h"

using namespace std;

//TODO refactor nazw

// Poprawia struktrurę aby był zachowany warunek kopca
void Kopiec_binarny::popraw(int indeks) {
    int lewy = indeks * 2 + 1;
    int prawy = indeks * 2 + 2;
    int najwiekszy = indeks;

    if (lewy < kopiec.size() && kopiec[lewy] > kopiec[najwiekszy]) {
        najwiekszy = lewy;
    }

    if (prawy < kopiec.size() && kopiec[prawy] > kopiec[najwiekszy]) {
        najwiekszy = prawy;
    }

    if (najwiekszy != indeks) {
        swap(kopiec[indeks], kopiec[najwiekszy]);
        popraw(najwiekszy);
    }
}



void Kopiec_binarny::dodaj(int value) {
    kopiec.push_back(value);

    int index = kopiec.size() - 1;
    int parent = (index - 1) / 2;

    while (index > 0 && kopiec[parent] < kopiec[index]) {
        swap(kopiec[parent], kopiec[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
    rozmiar_kopca++;
}

int Kopiec_binarny::usun_ze_szczytu() {
    if (kopiec.empty()) {
        cerr << "Heap is empty" << endl;
        return -1;
    }

    int szczyt = kopiec[0];
    kopiec[0] = kopiec.back();
    kopiec.pop_back();
    popraw(0);

    rozmiar_kopca--;
    return szczyt;
}

// TODO Buchalski kazał wypisac to jak w ASCII
void Kopiec_binarny::wypisz_kopiec() {
    for (int i = 0; i < kopiec.size(); ++i) {
        cout << kopiec[i] << " ";
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

void Kopiec_binarny::kopiec_w_ASCII() {
    cout<<endl;
    int height = floor(log2(kopiec.size())) + 1;
    int max_width = pow(2, height) * 4;

    int index = 0;
    int current_level = 1;
    int current_node_count = 1;
    while (index < kopiec.size()) {
        for (int i = 0; i < current_node_count; i++) {
            if (i == current_node_count - 1) {
                cout << setw(max_width / current_node_count) << kopiec[index] << endl;
            } else {
                cout << setw(max_width / current_node_count) << kopiec[index];
            }
            index++;

            if (index >= kopiec.size()) {
                break;
            }
        }
        current_level++;
        current_node_count *= 2;
    }
}

void Kopiec_binarny::kopiec_w_ASCII2() {
    // Calculate the depth of the heap
    int depth = 0;
    int num_nodes = 1;
    while (num_nodes <= kopiec.size()) {
        depth++;
        num_nodes *= 2;
    }

    // Calculate the width of each level
    int width = pow(2, depth - 1);

    // Loop through each level of the heap
    for (int level = 0; level < depth; level++) {
        // Calculate the number of nodes on this level
        int num_nodes = pow(2, level);
        // Calculate the spacing between nodes
        int spacing = width / num_nodes;
        // Calculate the spacing between levels
        int level_spacing = spacing * 2;

        // Print the nodes on this level
        for (int i = 0; i < num_nodes; i++) {
            // Calculate the index of this node
            int index = pow(2, level) - 1 + i;
            // If the index is beyond the end of the heap, break out of the loop
            if (index >= kopiec.size()) {
                break;
            }

            // Print the node with spacing
            std::cout << std::string(spacing, ' ') << kopiec[index] << std::string(spacing, ' ') << std::string(level_spacing, ' ');
        }

        // Print a newline character to move to the next level
        std::cout << std::endl;
    }
}




