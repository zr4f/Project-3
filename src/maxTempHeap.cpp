#include "maxTempHeap.h"
#include <iostream>


maxTempHeap::maxTempHeap() {}

void maxTempHeap::heapifyUp(int index) {
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

void maxTempHeap::heapifyDown(int index) {
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

bool maxTempHeap::insert(const string& _date, const string& _time, const double& _temp, const double& _precipitation) {
    Node* newNode = new Node(_date, _time, _temp, _precipitation);
    heap.push_back(newNode);
    heapifyUp(heap.size() - 1);
    return true;
}

maxTempHeap::Node* maxTempHeap::extractMax() {
    Node* maxNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        heapifyDown(0);
    }
    return maxNode;
}

vector<string> maxTempHeap::getMax(){
    vector<string> result;
    result.push_back(heap[0]->date);
    result.push_back(heap[0]->time);
    result.push_back(to_string(heap[0]->temp));
    result.push_back(to_string(heap[0]->precipitation));
    return result;
}