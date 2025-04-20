#include "maxHeap.h"
#include <iostream>


maxHeap::maxHeap() {}

void maxHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->temp > heap[parent]->temp) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void maxHeap::heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left]->temp > heap[largest]->temp) { 
            largest = left;
        }
        if (right < size && heap[right]->temp > heap[largest]->temp) { 
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

bool maxHeap::insert(const string& _date, const string& _time, const double& _temp, const double& _humidity) {
    Node* newNode = new Node(_date, _time, _temp, _humidity);
    heap.push_back(newNode);
    heapifyUp(heap.size() - 1);
    return true;
}

maxHeap::Node* maxHeap::extractMax() {
    Node* maxNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        heapifyDown(0);
    }
    return maxNode;
}
