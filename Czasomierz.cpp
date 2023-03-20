#include "Czasomierz.h"
#include <chrono>

using namespace std::chrono;

void Czasomierz::Start() {
    start = high_resolution_clock::now();
}

void Czasomierz::Stop() {
    stop = high_resolution_clock::now();
}

// TODO poprawić metode

void Czasomierz::Zmierzony_czas() {
    long zmierzony_czas = duration_cast<nanoseconds>(Czasomierz::stop - Czasomierz::start).count();
    cout << "Czasomierz wykonania: " << zmierzony_czas << "ns" << endl;
}

long Czasomierz::czas_do_pliku() {
    long zmierzony_czas = duration_cast<nanoseconds>(Czasomierz::stop - Czasomierz::start).count();
    return zmierzony_czas;
}


