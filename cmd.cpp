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
    int n; //n is number of element
    int *arr;
    
    unsigned long long comparisons;
    double duration;
    ALGORITHM ALGO = getALGORITHM(str_argv[2]);
    Parameter PARAM = getParameter(str_argv[4]);
    if(ALGO == Wrong_CMD_ALGO || PARAM == Wrong_CMD_Param) 
    {
        cout << "name algorithm or output parameter is not correct.";
        return 0;
    }
    if(readfile(str_argv[3], arr, n) == false)
    {
        cout << "file is not in the correct form!";
        return 0;
    }
        
    cout << "ALGORITHM MODE" << endl
            << "Algorithm:: " << str_argv[2] << endl
            << "Input file: " << str_argv[3] << endl
            << "Input size: " << n << endl;
    Sort(arr, n, comparisons, duration, ALGO);
    if(PARAM == Time)
        cout << "Runing time: " << duration << endl;
    else if(PARAM == Comp)
        cout << "Comparisons: " << comparisons << endl;
    else if(PARAM == Both)
    {
        cout << "Runing time: " << duration << endl;
        cout << "Comparisons: " << comparisons << endl;
    }
    cout << endl;
    return true;
}

bool Command2(vector<string> str_argv)
{
    unsigned long long comparisons;
    double duration;
    //Comman 2: on the data generated automatically with specified size and order.
    //file.exe -a algorithm_1 size order -both
    ALGORITHM ALGO = getALGORITHM(str_argv[2]);
    string NameORDER;
    Parameter PARAM = getParameter(str_argv[5]);
    int ORDER = getORDER(str_argv[4], NameORDER);
    if(ALGO == Wrong_CMD_ALGO || PARAM == Wrong_CMD_Param) 
    {
        cout << "name algorithm or output parameter is not correct.";
        return 0;
    }
    if(ORDER == 4)
    {
        cout << "name algorithm or output parameter is not correct.";
        return 0;
    }
    if(isNumber(str_argv[3]) == false)
    {
        cout << "size isn't number.";
        return 0;
    }
    int n = stoull(str_argv[3]);
    int* arr = new int[n];
    cout << "ALGORITHM MODE\n"
            << "Algorithm:: " << str_argv[2] << endl
            << "Input size: " << n << endl;

    GenerateData(arr,n, ORDER);
    Sort(arr, n, comparisons, duration, ALGO);
    printResultAlgoMode(NameORDER, PARAM, duration, comparisons);
    delete []arr;
    return true;
}

bool Command3(vector<string> str_argv)
{
    int n; //n is number of element
    int *arr;
    unsigned long long comparisons;
    double duration;
    ALGORITHM ALGO = getALGORITHM(str_argv[2]);
    Parameter PARAM = getParameter(str_argv[4]);
    if(ALGO == Wrong_CMD_ALGO || PARAM == Wrong_CMD_Param) 
    {
        cout << "name algorithm or output parameter is not correct.";
        return false;
    }

    if(isNumber(str_argv[3]) == false)
    {
        cout << "size isn't number.";
        return false;
    }
    n = stoi(str_argv[3]);
    arr = new int[n];
    cout << "ALGORITHM MODE\n"
            << "Algorithm:: " << str_argv[2] << endl
            << "Input size: " << stoi(str_argv[3]) << endl << endl;

    GenerateRandomData(arr,n);
    Sort(arr, n, comparisons, duration, ALGO);
    printResultAlgoMode("Randomize", PARAM, duration, comparisons);

    GenerateNearlySortedData(arr,n);
    Sort(arr, n, comparisons, duration, ALGO);
    printResultAlgoMode("Nearly Sorted", PARAM, duration, comparisons);

    GenerateSortedData(arr,n);
    Sort(arr, n, comparisons, duration, ALGO);
    printResultAlgoMode("Sorted",PARAM, duration, comparisons);

    GenerateReverseData(arr,n);
    Sort(arr, n, comparisons, duration, ALGO);
    printResultAlgoMode("Reversed", PARAM, duration, comparisons);
    delete []arr;
    return true;
}

bool Command4(vector<string> str_argv)
{
    int* arr;
    int n;
    unsigned long long comparisons1, comparisons2;
    double duration1, duration2;
    ALGORITHM ALGO1 = getALGORITHM(str_argv[2]),
                ALGO2 = getALGORITHM(str_argv[3]);
    if(ALGO1 == Wrong_CMD_ALGO || ALGO2 == Wrong_CMD_ALGO)
    {
        cout << "name algorithm or output parameter is not correct.";
        return 0;
    }

    if(readfile(str_argv[4], arr, n) == false)
    {
        cout << "file is not in the correct form!";
        return 0;
    }
    Sort(arr, n, comparisons1, duration1, ALGO1);
    readfile(str_argv[4], arr, n);
    Sort(arr, n, comparisons2, duration2, ALGO2);
    delete []arr;

    cout << "COMPARE MODE\n"
         << "Algorithm:: " << str_argv[2] << " | " << str_argv[3] << endl
         << "Input file: " << str_argv[4] << endl
         << "Input size: " << n << endl 
         << "--------------------------------------------\n"
         << "Running time: " << duration1 << " | " << duration2 << endl
         << "Comparisons:  " << comparisons1 << " | " << comparisons2 << endl;
    return 1;
}

bool Command5(vector<string> str_argv)
{
    //Command 5: Two sorting algorithms on the data generated automatically.
    //file.exe -c algorithm_1 algorithm_2 size order
    unsigned long long comparisons1, comparisons2;
    double duration1, duration2;
    ALGORITHM ALGO1 = getALGORITHM(str_argv[2]),
                ALGO2 = getALGORITHM(str_argv[3]);
    string NameORDER;
    int ORDER = getORDER(str_argv[5], NameORDER);
    if(ALGO1 == Wrong_CMD_ALGO || ALGO2 == Wrong_CMD_ALGO)
    {
        cout << "name algorithm or output parameter is not correct.";
        return 0;
    }
    if(ORDER == 4)
    {
        cout << "output parameter is not correct.";
        return 0;
    }
    if(isNumber(str_argv[4]) == false)
    {
        cout << "size is not number";
        return 0;
    }
    int n = stoi(str_argv[4]);
    int* arr = new int[n];
    int* arr_copy = new int [n];
    GenerateData(arr, n, ORDER);
    for(int i = 0; i < n; i++)
        arr_copy[i] = arr[i];

    Sort(arr, n, comparisons1, duration1, ALGO1);
    Sort(arr_copy, n, comparisons2, duration2, ALGO2);
    cout << "sort xong";
    delete []arr;
    delete []arr_copy;
    
    cout << "COMPARE MODE\n"
            << "Algorithm:: " << str_argv[2] << " | " << str_argv[3] << endl
            << "Input size: " << n << endl 
            << "Input order: " << NameORDER << endl
            << "--------------------------------------------\n"
            << "Running time: " << duration1 << " | " << duration2 << endl
            << "Comparisons:  " << comparisons1 << " | " << comparisons2 << endl;
    return true;
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