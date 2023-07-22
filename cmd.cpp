#include "Library.h"
#include "sorting_implementation.cpp"
using namespace std;

#define DEBUG 0

enum ALGORITHM
{
    Selection,
    Insertion,
    Bubble,
    Shaker,
    Shell,
    Heap,
    Merge,
    Quick,
    Counting,
    Radix,
    Flash,
    Wrong_CMD_ALGO
};
enum Parameter
{
    Comp,
    Time,
    Both,
    Wrong_CMD_Param
};

bool isNumber(string n)
{
    for(int i = 0; n[i] != '\0'; i++)
        if(n[i] < '0' || n[i] >'9')
            return false;
    return true;    
}

ALGORITHM getALGORITHM(string algo)
{
    if(algo == "selection-sort") return Selection;
    if(algo == "insertion-sort") return Insertion;
    if(algo == "bubble-sort") return Bubble;
    if(algo == "shaker-sort") return Shaker;
    if(algo == "shell-sort") return Shell;
    if(algo == "heap-sort") return Heap;
    if(algo == "merge-sort") return Merge;
    if(algo == "quick-sort") return Quick;
    if(algo == "couting-sort") return Counting;
    if(algo == "radix-sort") return Radix;
    if(algo == "flash-sort") return Flash;
    return Wrong_CMD_ALGO;
}

Parameter getParameter(string par)
{
    if(par == "-comp")  return Comp;
    if(par == "-time")  return Time;
    if(par == "-both")  return Both;
    return Wrong_CMD_Param;
}

int getORDER(string order, string& nameOrder)
{
    if(order == "-rand")
    {
        nameOrder = "Randomize";
        return 0;
    } 
    if(order == "-nsorted")
    {
        nameOrder =  "Nearly Sorted";
        return 3;
    } 
    if(order == "-sorted") 
    {
        nameOrder = "Sorted";
        return 1;
    }
    if(order == "-rev")
    {
        nameOrder = "Reversed";
        return 2;
    }
    nameOrder = "Wrong_CMD";
    return 4;
}

void Sort(int *&arr, int n, unsigned long long &comparisonss, double &duration, ALGORITHM Algo)
{
    switch (Algo)
    {
    case Selection:
        //Call Selection sort:
        break;
    case Insertion:
        //Call Insertion sort:
        break;
    case Bubble:
        //Call Bubble sort:
        break;
    case Shaker:
        //Call Shaker sort:
        break;
    case Shell:
        //Call Shell sort:
        break;
    case Heap:
        heapSort_counting(arr, n, comparisonss, duration);
        //Call Heap sort:
        break;
    case Merge:
        //Call Merge sort:
        break;
    case Quick:
        quickSort_counting(arr, n, comparisonss, duration);
        //Call Quick sort:
        break;
    case Counting:
        //Call Counting sort:
        break;
    case Radix:
        //Call Radix sort:
        break;
    case Flash:
        //Call Flash sort:
        flashSort_counting(arr, n, comparisonss, duration);
        break;
    default:
        break;
    }
}

bool readfile(string filename, int* &arr, int &n)
{
    ifstream in;
    in.open(filename);
    if(!in.is_open())
    {
        cout << "Can't open file";
        return false;
    }
    string field;
    getline(in, field);
    if(!isNumber(field))
    {
        cout << "1st line in file is not a number";
        return false;
    }
    n = stoi(field);

    arr = new int[n];
    int i = 0;
    while(!in.eof() && i < n)
    {
        in >> arr[i++];
    }
    return true;
}

void printResultAlgoMode(string Order, Parameter param, double duration, unsigned long long comparasons)
{
    cout << "Input order: " << Order << endl
        << "--------------------------------------\n";
    if(param == Time)
        cout << "Runing time: " << duration << endl;
    else if(param == Comp)
        cout << "Comparisons: " << comparasons << endl;
    else if(param == Both)
    {
        cout << "Runing time: " << duration << endl;
        cout << "Comparisons: " << comparasons << endl;
    }
    cout << endl;
}

bool  Command1(vector<string> str_argv)
{

}

bool Command2(vector<string> str_argv)
{

}

bool Command3(vector<string> str_argv)
{

}

bool Command4(vector<string> str_argv)
{

}

bool Command5(vector<string> str_argv)
{

}

void getTASK(int argc,vector<string> str_argv)
{
#if DEBUG
        cout << "argc = " << argc << endl;
        cout << "argv: ";
        for (int i = 0; i < argc; i++)
        {
            cout << str_argv[i] << ", ";
        }
        cout << endl;
#endif
    // vector<string> str_argv;

    // for(int i = 0; i < argc; i++)
    //    str_argv.push_back( string(argv[i]) );

    int n; //n is number of element
    int *arr;

    if(argc == 5)
    {
        if(str_argv[1] == "-a")
        {
            if(isNumber(str_argv[3]) == false)
            {
                //Command 1: on the given input data
                //file.exe -a Algorithm file_input -both 
                bool check = Command1(str_argv); 
                if(check == false)
                    cout << "\nerror 1!";
            } else
            {
                //Command 3: on ALL data arrangements of a specified size.
                //file.exe -a algorithm size -comp
                bool check = Command3(str_argv); 
                if(check == false)
                    cout << "\nerror 3!";
            }
        } else if(str_argv[1] == "-c")
        {
            //Command 4: Run two sorting algorithms on the given input
            //file.exe -c algorithm_1 algorithm_2 file_input
            bool check = Command4(str_argv); 
            if( check == false)
                cout << "\nerror 4!";
        }
    } else if (argc == 6)
    {
        if(str_argv[1] == "-a")
        {
            //Comman 2: on the data generated automatically with specified size and order.
            //file.exe -a algorithm_1 size order -both
            bool check = Command2(str_argv); 
            if(check == false)
                cout << "\nerror 2!";
        } else if (str_argv[1] == "-c")
        {
            //Command 5: Two sorting algorithms on the data generated automatically.
            //file.exe -c algorithm_1 algorithm_2 size order
            bool check = Command5(str_argv); 
            if( check == false)
                cout << "\nerror 5!";
        }
    }
}