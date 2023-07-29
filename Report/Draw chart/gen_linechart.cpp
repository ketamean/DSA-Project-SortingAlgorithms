#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define folder "rand"
#define field "time"
using namespace std;

int main () {
    string algorithms[] = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort",
                    "heap-sort", "merge-sort", "quick-sort", "radix-sort",
                    "shell-sort", "counting-sort", "flash-sort"
                };

    string names[] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort",
                    "Heap Sort", "Merge Sort", "Quick Sort", "Radix Sort", 
                    "Shell Sort", "Counting Sort", "Flash Sort"
                };
                
    ofstream out("source.py");
    string time, comp, n;
    for (int i = 0; i < 11; i++) {
        string filename = string(folder) + "/" + algorithms[i] + ".txt";
        ifstream ifs(filename);
        getline(ifs, time); // skip 1st line
        out << "\t'" << names[i] << "': [";
        for (int i = 0; i < 6; i++) {
            getline(ifs, n, ','); // skip n
            getline(ifs, comp, ',');
            getline(ifs, time);
            out << "(" << n << ", ";
            if (string(field) == "comp") {
                out << comp;
            } else {
                out << time;
            }
            out << "), ";
        }
        out << "], " << endl;
        ifs.close();
    }

    sort()
    out.close();
}