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
        bool findDate(const string& date);
        simpleHashMap();
        void insert(const string& date, const string& time, const pair<double, double>& measurements);
        vector<string> findMinTempRange(const string& date1, const string& date2);
        vector<string> findMaxTempRange(const string& date1, const string& date2);
        vector<string> findMinPrecRange(const string& date1, const string& date2);
        vector<string> findMaxPrecRange(const string& date1, const string& date2);
};

