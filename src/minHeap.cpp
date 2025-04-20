#include "minHeap.h"
#include <iostream>

minHeap::minHeap() {}

void minHeap::heapifyUp(int index) {
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

void minHeap::heapifyDown(int index) {
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

bool minHeap::insert(const string& _date, const string& _time, const double& _temp, const double& _humidity) {
    Node* newNode = new Node(_date, _time, _temp, _humidity);
    heap.push_back(newNode);
    heapifyUp(heap.size() - 1);
    return true;
}

minHeap::Node* minHeap::extractMin() {
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

vector<string> minHeap::getMin(){
    vector<string> result;
    result.push_back(heap[0]->date);
    result.push_back(heap[0]->time);
    result.push_back(to_string(heap[0]->temp));
    result.push_back(to_string(heap[0]->humidity));
    return result;
}
