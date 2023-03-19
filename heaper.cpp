#include <vector>
#include <iostream>
#include "heaper.h"

using namespace std;

void BinaryHeap:: add(int value) {
    heap.push_back(value);

    int index = heap.size() - 1;

    // Percolate up the newly added element to its correct position in the heap
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Remove the specified element from the heap and return its value
int BinaryHeap::remove(int value) {
    int index = -1;

    // Find the index of the element to remove
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cerr << "Element not found in heap" << std::endl;
        return -1;
    }

    int root = heap[index];
    heap[index] = heap.back();
    heap.pop_back();

    // Percolate the element up or down to its correct position in the heap
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }

    while (index * 2 + 1 < heap.size()) {
        int child1 = index * 2 + 1;
        int child2 = index * 2 + 2;
        int minChild = child1;

        if (child2 < heap.size() && heap[child2] < heap[child1]) {
            minChild = child2;
        }

        if (heap[minChild] < heap[index]) {
            std::swap(heap[index], heap[minChild]);
            index = minChild;
        } else {
            break;
        }
    }

    return root;
}

// Print the current state of the heap
void BinaryHeap::print_heap() {
    for (int i = 0; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

// Check if an element exists in the heap
void BinaryHeap::check_if_exists(int value) {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i] == value) {
            cout<<"element istnieje na polu: "<<i<<endl;
        }
    }
    cout<<"element nie istnieje w kopcu"<<endl;
}
