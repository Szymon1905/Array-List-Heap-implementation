#include <vector>
#include <iostream>
#include "Kopiec.h"

using namespace std;

//TODO refactor nazw

void Kopiec_binarny::heapify(int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;

    if (left < kopiec.size() && kopiec[left] > kopiec[largest]) {
        largest = left;
    }

    if (right < kopiec.size() && kopiec[right] > kopiec[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(kopiec[index], kopiec[largest]);
        heapify(largest);
    }
}



void Kopiec_binarny::dodaj(int value) {
    kopiec.push_back(value);

    int index = kopiec.size() - 1;
    int parent = (index - 1) / 2;

    while (index > 0 && kopiec[parent] < kopiec[index]) {
        std::swap(kopiec[parent], kopiec[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

int Kopiec_binarny::usun_ze_szczytu() {
    if (kopiec.empty()) {
        std::cerr << "Heap is empty" << std::endl;
        return -1;
    }

    int root = kopiec[0];
    kopiec[0] = kopiec.back();
    kopiec.pop_back();
    heapify(0);

    return root;
}

void Kopiec_binarny::wypisz_kopiec() {
    for (int i = 0; i < kopiec.size(); ++i) {
        std::cout << kopiec[i] << " ";
    }
    std::cout << std::endl;
}

bool Kopiec_binarny::czy_istnieje(int value) {
    for (int i = 0; i < kopiec.size(); ++i) {
        if (kopiec[i] == value) {
            return true;
        }
    }
    return false;
}



