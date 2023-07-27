#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    ifstream ifs("output.txt");
    string buffer;
    getline(ifs, buffer);
    unsigned int n = stoi(buffer);
    int val = -1;
    for (int i = 0; i < n; i++) {
        ifs >> buffer;
        if (stoi(buffer) > val) val = stoi(buffer);
        else {
            cout << "WRONG";
            return 0;
        } 
    }
    ifs.close();
    cout << "CORRECT";
    return 0;
}