#pragma once
#include <string>
#include <vector>
#include <utility>
using namespace std;

class minTempHeap{
    public:
        struct Node{
            string date;
            string time;
            double temp;
            double precipitation;

            Node():date(""), time(""), temp(0.0), precipitation(0.0){}
            Node(const string& _date, const string& _time, const double& _temp, const double& _precipitation): date(_date), time(_time), temp(_temp), precipitation(_precipitation){}
        };

    private:
        vector<Node*> heap; 
        void heapifyDown(int index);
        void heapifyUp(int index);

    public:

        minTempHeap();
        bool insert(const string& _date, const string& _time, const double& _temp, const double& precipitation);
        Node* extractMin();
        vector<string> getMin();
};


