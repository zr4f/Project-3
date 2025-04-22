// Project 3 - Zarraf Rayan and Sydney Dodson
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <limits>
#include <iomanip>
#include "maxHeap.h"
#include "minHeap.h"
#include "maxPrecHeap.h"
#include "simpleHashMap.h"

using namespace std;

int main(){
    ifstream file("src/XMR.csv");
    if (!file.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return 1;
    }
    maxHeap max_heap;
    minHeap min_heap;
    maxPrecHeap max_prec_heap;
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
        string precip_str;
        double temp;
        double precip;
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
                precip_str = data;
                if(precip_str == "M" || precip_str == "T"){
                    skip = true;
                    continue;
                }
                precip = stod(precip_str);
                if(precip > 4.00) { //skipped due to equipment malfunction
                    skip = true;
                }
            }
            count++;
        }
        if(skip){
            continue;
        }
        pair<double, double> temp_humid = make_pair(temp, precip);
        hmap.insert(date, time, temp_humid);
        max_heap.insert(date, time, temp, precip);
        min_heap.insert(date, time, temp, precip);
        max_prec_heap.insert(date, time, temp, precip);
    }

    file.close();

    int option = 0;
    while(option != 7){
        cout << "\n----Weather Data Menu----" << endl;
        cout << "1. Find Maximum Temperature from Data" << endl;
        cout << "2. Find Minimum Temperature from Data" << endl;
        cout << "3. Find Maximum Precipitation from Data" << endl;
        cout << "4. Find Maximum Temperature from Date Range" << endl;
        cout << "5. Find Minimum Temperature from Date Range" << endl;
        cout << "6. Find Maximum Precipitation from Date Range" << endl;
        cout << "7. Quit" << endl;
        cout << "\nEnter Selection:" << endl;

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input is not a number." << std::endl;
        }
        if(option < 1 || option > 7){
            cout << "Input is not a number 1-7." << endl;
            continue;
        }
        //Max Heap
        if(option == 1){
            vector<string> output;
            output = max_heap.getMax();
            double temperature = stod(output[2]);
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Maximum Temperature: " << temperature << " F recorded at " << output[1] << " on " << output[0] << endl;
        }
        //Min Heap
        if(option == 2){
            vector<string> output;
            output = min_heap.getMin();
            double temperature = stod(output[2]);
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Minimum Temperature: " << temperature << " F recorded at " << output[1] << " on " << output[0] << endl;
        }
        if(option == 3){
            vector<string> output;
            output = max_prec_heap.getMax();
            double precipitation = stod(output[3]);
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Maximum Precipitation: " << precipitation << " (in) recorded at " << output[1] << " on " << output[0] << endl;
        }
        if(option == 4){
            string date1;
            string date2;
            cout << "Enter Date 1 in format YYYY-MM-DD:" << endl;
            cin >> date1;
            cout << "Enter Date 2 in format YYYY-MM-DD:" << endl;
            cin >> date2;
            vector<string> output = hmap.findMaxTempRange(date1, date2);
            double temperature = stod(output[2]);
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Maximum Temperature Between " << date1 << " and " << date2 << endl;
            cout << temperature << " F on " << output[0] << " at " << output[1] << endl;
        }
        if(option == 5){
            string date1;
            string date2;
            cout << "Enter Date 1 in format YYYY-MM-DD:" << endl;
            cin >> date1;
            cout << "Enter Date 2 in format YYYY-MM-DD:" << endl;
            cin >> date2;
            vector<string> output = hmap.findMinTempRange(date1, date2);
            double temperature = stod(output[2]);
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Minimum Temperature Between " << date1 << " and " << date2 << endl;
            cout << temperature << " F on " << output[0] << " at " << output[1] << endl;
        }
        if(option == 6) {
            string date1;
            string date2;
            cout << "Enter Date 1 in format YYYY-MM-DD:" << endl;
            cin >> date1;
            cout << "Enter Date 2 in format YYYY-MM-DD:" << endl;
            cin >> date2;
            vector<string> output = hmap.findMaxPrecRange(date1, date2);
            double precipitation = stod(output[2]);
            cout << fixed << showpoint;
            cout << setprecision(2);
            cout << "Maximum Precipitation Between " << date1 << " and " << date2 << endl;
            cout << precipitation << " (in) on " << output[0] << " at " << output[1] << endl;
        }
    }
    return 0;
}
