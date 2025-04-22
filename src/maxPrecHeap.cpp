#include "maxPrecHeap.h"
#include <iostream>


maxPrecHeap::maxPrecHeap() {}

void maxPrecHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->precipitation > heap[parent]->precipitation) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void maxPrecHeap::heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left]->precipitation > heap[largest]->precipitation) { 
            largest = left;
        }
        if (right < size && heap[right]->precipitation > heap[largest]->precipitation){ 
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

bool maxPrecHeap::insert(const string& _date, const string& _time, const double& _temp, const double& _precipitation) {
    Node* newNode = new Node(_date, _time, _temp, _precipitation);
    heap.push_back(newNode);
    heapifyUp(heap.size() - 1);
    return true;
}

maxPrecHeap::Node* maxPrecHeap::extractMax() {
    Node* maxNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        heapifyDown(0);
    }
    return maxNode;
}

vector<string> maxPrecHeap::getMax(){
    vector<string> result;
    result.push_back(heap[0]->date);
    result.push_back(heap[0]->time);
    result.push_back(to_string(heap[0]->temp));
    result.push_back(to_string(heap[0]->precipitation));
    return result;
}

