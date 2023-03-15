#include "Czas.h"
#include <chrono>


using namespace std;
using namespace std::chrono;

void Czas::czasStart() {
    start = high_resolution_clock::now();
}

void Czas::czasStop() {
    stop = high_resolution_clock::now();
}

void Czas::czasWykonania() {
    long zmierzony_czas = duration_cast<nanoseconds>(Czas::stop - Czas::start).count();
    cout << "Czas wykonania: " << zmierzony_czas << "ms" << endl;
}


