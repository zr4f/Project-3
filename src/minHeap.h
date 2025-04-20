#pragma once
#include <string>
#include <vector>
#include <utility>
using namespace std;

class minHeap{
    public:
        struct Node{
            string date;
            string time;
            double temp;
            double humidity;

            Node():date(""), time(""), temp(0.0), humidity(0.0){}
            Node(const string& _date, const string& _time, const double& _temp, const double& _humidity): date(_date), time(_time), temp(_temp), humidity(_humidity){}
        };

    private:
        vector<Node*> heap; 
        void heapifyDown(int index);
        void heapifyUp(int index);

    public:

        minHeap();
        bool insert(const string& _date, const string& _time, const double& _temp, const double& humidity);
        Node* extractMin();
        vector<string> getMin();
};


