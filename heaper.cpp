#include <vector>
#include <iostream>
#include "heaper.h"

using namespace std;

int BinaryHeap::parent(int i) {
    return (i - 1) / 2;
}

int BinaryHeap::left_child(int i) {
    return 2 * i + 1;
}

int BinaryHeap::right_child(int i) {
    return 2 * i + 2;
}

void BinaryHeap::heapify_down(int i) {
    int min_index = i;

    int left = left_child(i);
    if (left < heap.size() && heap[left] < heap[min_index]) {
        min_index = left;
    }

    int right = right_child(i);
    if (right < heap.size() && heap[right] < heap[min_index]) {
        min_index = right;
    }

    if (min_index != i) {
        std::swap(heap[i], heap[min_index]);
        heapify_down(min_index);
    }
}



void BinaryHeap::add(int value) {
    heap.push_back(value);

    int index = heap.size() - 1;

    // Percolate up the newly added element to its correct position in the heap
    while (index > 0 && heap[index] < heap[parent(index)]) {
        std::swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}
    // Add a new element to the heap


int BinaryHeap::remove_top() {
    if (heap.empty()) {
        std::cerr << "Heap is empty" << std::endl;
        return -1;
    }

    int top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    heapify_down(0);

    return top;
}

void BinaryHeap::print_heap() {
    for (int i = 0; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}



