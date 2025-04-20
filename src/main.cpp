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
    ifstream file("src/XMR.csv");
    if (!file.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return 1;
    }

    simpleHashMap hmap;
    string line;
    bool firstLine = true;
    while(getline(file, line)){
        if (firstLine == true) {
            firstLine = false;
            continue;
        }
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
        bool skip = false;
        while(getline(ss, data, ',')){
            if(count == 1){
                size_t space_pos = data.find(' ');
                date = data.substr(0, space_pos);
                time = data.substr(space_pos + 1);
            }
            if(count == 2){
                temp_str = data;
                if(temp_str != "M"){
                    temp = stod(temp_str);
                }
                else{
                    skip = true;
                }
            }
            if(count == 3) {
                humid_str = data;
                if(humid_str != "M"){
                    humid = stod(humid_str);
                }
                else{
                    skip = true;
                }
            }
            count++;
        }
        if(skip){
            continue;
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
        //Max Heap
        if(option == 1){
            //Max Heap
        }
        //Min Heap
        if(option == 2){
            //Min Heap
        }
        if(option == 3){
            string date1;
            string date2;
            cout << "Enter Date 1 in format YYYY-MM-DD:" << endl;
            cin >> date1;
            cout << "Enter Date 2 in format YYYY-MM-DD:" << endl;
            cin >> date2;
            vector<string> output = hmap.findMaxRange(date1, date2);
            cout << "Maximum Temperature Between " << date1 << " and " << date2 << endl;
            cout << output[2] << " F on " << output[0] << " at " << output[1] << endl;
        }
        if(option == 4){
            string date1;
            string date2;
            cout << "Enter Date 1 in format YYYY-MM-DD:" << endl;
            cin >> date1;
            cout << "Enter Date 2 in format YYYY-MM-DD:" << endl;
            cin >> date2;
            vector<string> output = hmap.findMinRange(date1, date2);
            cout << "Minimum Temperature Between " << date1 << " and " << date2 << endl;
            cout << output[2] << " °F on " << output[0] << " at " << output[1] << endl;
        }
    }
    return 0;
}
