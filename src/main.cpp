// Project 3 - Zarraf Rayan and Sydney Dodson
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    ifstream file("XMR.csv");
    if (!file.is_open()) {
        cerr << "Error: cannot open file" << endl;
        return 1;
    }

    //initialize data structures here
    vector<vector<string>> test;
    string line;
    //while(getline(file, line)){
    for(int i = 0; i < 10; i++){
        vector<string> row;
        stringstream ss(line);
        string data;
        while(getline(ss, data, ',')){
            row.push_back(data);
        }
    }

    file.close();

    for (auto row : test) {
        for (auto data : row) {
            cout << data << " ";
        }
        cout << endl;
    }

}
