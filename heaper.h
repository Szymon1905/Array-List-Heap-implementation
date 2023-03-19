#include <vector>
#include <iostream>

class BinaryHeap {
    std::vector<int> heap;

public:

    int parent(int i);

    int left_child(int i);

    int right_child(int i);

    void heapify_down(int i);

    int remove_top();

    void print_heap();

    void add(int value);

    BinaryHeap() {}
};
