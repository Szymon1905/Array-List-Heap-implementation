#include <iostream>
#include <chrono>



using namespace std;
using namespace std::chrono;

class Czasomierz {
public:
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;

    void Start();

    void Stop();

    void Zmierzony_czas();

    long czas_do_pliku();
};



