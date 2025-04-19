#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std; 

class simpleHashMap {
    private:
        unordered_map<string, vector<pair<string, pair<double, double>>>> map;
        string incrementDate(const string& date);

    public:
        simpleHashMap();
        void insert(const string& date, const string& time, const pair<double, double>& measurements);
        vector<string> findMinRange(const string& date1, const string& date2);
        vector<string> findMaxRange(const string& date1, const string& date2);
};

