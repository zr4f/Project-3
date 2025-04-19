// Project 3 - Zarraf Rayan and Sydney Dodson
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <limits>
#include "simpleHashMap.h"

using namespace std;

int main(){
    ifstream file("XMR.csv");
    if (!file.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return 1;
    }

    simpleHashMap hmap;
    string line;
    while(getline(file, line)){
        vector<string> row;
        stringstream ss(line);
        string data;
        string date; 
        string time;
        string temp_str;
        string humid_str;
        double temp;
        double humid;
        int count = 0;
        while(getline(ss, data, ',')){
            if(count == 0){
                continue;
            }
            if(count == 1){
                date = data;
            }
            if(count == 2){
                time = data;
            }
            if(count == 3){
                temp_str = data;
                temp = stod(temp_str);
            }
            if(count == 4){
                humid_str = data;
                humid = stod(humid_str);
            }
        }
        pair<double, double> temp_humid = make_pair(temp, humid);
        hmap.insert(date, time, temp_humid);
    }

    file.close();

    
    int option = 0;
    while(option != 5){
        cout << "Weather Data Menu" << endl;
        cout << "1. Find Maximum Temperature from Data" << endl;
        cout << "2. Find Minimum Temperature from Data" << endl;
        cout << "3. Find Maximum Temperature from Date Range" << endl;
        cout << "4. Find Minimum Temperature from Date Range" << endl;
        cout << "5. Quit" << endl;
        cout << "\nEnter Selection:" << endl;

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input is not a number." << std::endl;
        }
        if(option < 1 || option > 5){
            cout << "Input is not a number 1-5." << endl;
            continue;
        }
        
    }
    return 0;
}
