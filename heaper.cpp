#include <vector>
#include <iostream>
#include "heaper.h"

using namespace std;

void BinaryHeap::heapify(int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapify(largest);
    }
}



void BinaryHeap::add(int value) {
    heap.push_back(value);

    int index = heap.size() - 1;
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] < heap[index]) {
        std::swap(heap[parent], heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

int BinaryHeap::remove() {
    if (heap.empty()) {
        std::cerr << "Heap is empty" << std::endl;
        return -1;
    }

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);

    return root;
}

void BinaryHeap::print_heap() {
    for (int i = 0; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

bool BinaryHeap::check_if_exists(int value) {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i] == value) {
            return true;
        }
    }
    return false;
}



