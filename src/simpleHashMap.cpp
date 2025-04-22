#include "simpleHashMap.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <utility>


simpleHashMap::simpleHashMap(){}
void simpleHashMap::insert(const string& date, const string& time, const pair<double, double>& measurements) {
    map[date].push_back(make_pair(time, measurements));
}

// helper function to incriment the date so we  can go through the hashmap
string simpleHashMap::incrementDate(const string& date) {
    int year, month, day;
    char dash;
    stringstream ss(date);
    ss >> year >> dash >> month >> dash >> day;

    day++;


    if (day > 31) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    ostringstream oss;
    oss << setw(4) << setfill('0') << year << "-"
        << setw(2) << setfill('0') << month << "-"
        << setw(2) << setfill('0') << day;
    return oss.str();
}


// takes in a range of dates and returns the date of the lowest temp, time of the lowest temp, and the lowest temp as a vector
vector<string> simpleHashMap::findMinTempRange(const string& date1, const string& date2) {
    vector<string> result;
    if (!findDate(date1)) {
        result.push_back("N/A");
        result.push_back("N/A");
        result.push_back("N/A");
        cout << "Invalid date\n" <<endl;
        return result;
    }
    if (!findDate(date2)) {
        result.push_back("N/B");
        result.push_back("N/B");
        result.push_back("N/B");
        cout << "Invalid date\n" <<endl;
        return result;
    }
    string minDate = date1;
    string minTime = map.at(date1).front().first;
    double minTemp = map.at(date1).front().second.first;
    

    string current = date1;
  
    while (current <= date2) {
        if (map.find(current) != map.end()) {
            for (auto i : map[current]) {
                double temp = i.second.first;
                if (temp < minTemp) {
                    minTemp = temp;
                    minDate = current;
                    minTime = i.first;
                }
            }
        }
        current = incrementDate(current);
    }

    result.push_back(minDate);
    result.push_back(minTime);
    result.push_back(to_string(minTemp));
    return result;
}

// takes in a range of dates and returns the date of the highest temp, time of the highest temp, and the highest temp as a vector
vector<string> simpleHashMap::findMaxTempRange(const string& date1, const string& date2) {
    vector<string> result;
    if (map.find(date1) == map.end()) {
        result.push_back("N/A");
        result.push_back("N/A");
        result.push_back("N/A");
        cout << "Invalid date" <<endl;
        return result;
    }
    if (map.find(date2) == map.end()) {
        result.push_back("N/A");
        result.push_back("N/A");
        result.push_back("N/A");
        cout << "Invalid date" <<endl;
        return result;
    }
    string maxDate = date1;
    string maxTime = map.at(date1).front().first;
    double maxTemp = map.at(date1).front().second.first;

    string current = date1;
  
    while (current <= date2) {
        if (map.find(current) != map.end()) {
            for (auto i : map[current]) {
                double temp = i.second.first;
                if (temp > maxTemp) {
                    maxTemp = temp;
                    maxDate = current;
                    maxTime = i.first;
                }
            }
        }
        current = incrementDate(current);
    }

    result.push_back(maxDate);
    result.push_back(maxTime);
    result.push_back(to_string(maxTemp));
    return result;
}


vector<string> simpleHashMap::findMinPrecRange(const string& date1, const string& date2) {
    vector<string> result;
    if (!findDate(date1)) {
        result.push_back("N/A");
        result.push_back("N/A");
        result.push_back("N/A");
        cout << "Invalid date\n" <<endl;
        return result;
    }
    if (!findDate(date2)) {
        result.push_back("N/B");
        result.push_back("N/B");
        result.push_back("N/B");
        cout << "Invalid date\n" <<endl;
        return result;
    }
    string minDate = date1;
    string minTime = map.at(date1).front().first;
    double minPrec = map.at(date1).front().second.second;
    

    string current = date1;
  
    while (current <= date2) {
        if (map.find(current) != map.end()) {
            for (auto i : map[current]) {
                double temp = i.second.second;
                if (temp < minPrec) {
                    minPrec = temp;
                    minDate = current;
                    minTime = i.first;
                }
            }
        }
        current = incrementDate(current);
    }

    result.push_back(minDate);
    result.push_back(minTime);
    result.push_back(to_string(minPrec));
    return result;
}

// takes in a range of dates and returns the date of the highest temp, time of the highest temp, and the highest temp as a vector
vector<string> simpleHashMap::findMaxPrecRange(const string& date1, const string& date2) {
    vector<string> result;
    if (map.find(date1) == map.end()) {
        result.push_back("N/A");
        result.push_back("N/A");
        result.push_back("N/A");
        cout << "Invalid date" <<endl;
        return result;
    }
    if (map.find(date2) == map.end()) {
        result.push_back("N/A");
        result.push_back("N/A");
        result.push_back("N/A");
        cout << "Invalid date" <<endl;
        return result;
    }
    string maxDate = date1;
    string maxTime = map.at(date1).front().first;
    double maxPrec = map.at(date1).front().second.second;

    string current = date1;
  
    while (current <= date2) {
        if (map.find(current) != map.end()) {
            for (auto i : map[current]) {
                double temp = i.second.second;
                if (temp > maxPrec) {
                    maxPrec = temp;
                    maxDate = current;
                    maxTime = i.first;
                }
            }
        }
        current = incrementDate(current);
    }

    result.push_back(maxDate);
    result.push_back(maxTime);
    result.push_back(to_string(maxPrec));
    return result;
}

bool simpleHashMap::findDate(const string& date){
    if (map.find(date)!=map.end()) {
        return true;
    }
    return false;
}
