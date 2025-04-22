#include "minTempHeap.h"
#include <iostream>

minTempHeap::minTempHeap() {}

void minTempHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->temp < heap[parent]->temp) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void minTempHeap::heapifyDown(int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left]->temp < heap[smallest]->temp) {
            smallest = left;
        }
        if (right < size && heap[right]->temp < heap[smallest]->temp) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

bool minTempHeap::insert(const string& _date, const string& _time, const double& _temp, const double& _precipitation) {
    Node* newNode = new Node(_date, _time, _temp, _precipitation);
    heap.push_back(newNode);
    heapifyUp(heap.size() - 1);
    return true;
}

minTempHeap::Node* minTempHeap::extractMin() {
    if (heap.empty()) {
        throw runtime_error("Heap is empty");
    }

    Node* minNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        heapifyDown(0);
    }
    return minNode;
}

vector<string> minTempHeap::getMin(){
    vector<string> result;
    result.push_back(heap[0]->date);
    result.push_back(heap[0]->time);
    result.push_back(to_string(heap[0]->temp));
    result.push_back(to_string(heap[0]->precipitation));
    return result;
}
