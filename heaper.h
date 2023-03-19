#include <vector>
#include <iostream>

class BinaryHeap {
    std::vector<int> heap;;

public:

    void add(int);

    int remove();

    void print_heap();

    void check_if_exists(int);

    BinaryHeap() {}
};
