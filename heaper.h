#include <vector>
#include <iostream>

class BinaryHeap {
    std::vector<int> heap;

public:
    BinaryHeap() {}

    void heapify(int);

    int remove();

    void print_heap();

    void add(int value);

    bool check_if_exists(int value);

};
