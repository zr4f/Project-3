#pragma once
#include <string>
#include <vector>
#include <utility>
using namespace std;

class maxHeap {
public:
    struct Node {
        string date;
        string time;
        double temp;
        double humidity;

        Node() : date(""), time(""), temp(0.0), humidity(0.0) {}
        Node(const string& _date, const string& _time, const double& _temp, const double& _humidity): date(_date), time(_time), temp(_temp), humidity(_humidity) {}
    };

private:
    vector<Node*> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    maxHeap();
    bool insert(const string& _date, const string& _time, const double& _temp, const double& _humidity);
    Node* extractMax();
};
