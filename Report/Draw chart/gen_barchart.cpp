#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#define folder "rand"
#define field "comp"
using namespace std;

int main () {
    string algorithms[] = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "flash-sort", "heap-sort",
                    "merge-sort", "quick-sort", "radix-sort", "shell-sort", "counting-sort"};

    string names[] = {"Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Flash Sort",
                    "Heap Sort", "Merge Sort", "Quick Sort", "Radix Sort", "Shell Sort", "Counting Sort"};
    string size[] = {"'10000'", "'30000'", "'50000'", "'100000'", "'300000'", "'500000'"};
                
    ofstream out("source.py");
    string time, comp, n;
    string com[6][11];
    for (int j = 0; j < 11; j++) {
        string filename = string(folder) + "/" + algorithms[j] + ".txt";
        ifstream ifs(filename);
        getline(ifs, time); // skip 1st line
        for (int i = 0; i < 6; i++) {
            getline(ifs, n, ','); // skip n
            getline(ifs, comp, ',');
            com[i][j] = comp;
            getline(ifs, time);

        }
        ifs.close();
    }

    for(int i = 0; i < 6; i++)
    {
        out << size[i] << ": (";
        for(int j = 0; j < 10; j++)
        {
            out << com[i][j] <<",";
        }
        out << com[i][10] << "),\n";
    }

    out.close();
}