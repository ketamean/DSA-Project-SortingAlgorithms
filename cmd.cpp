#include "Library.h"
#include "sorting_implementation.cpp"
using namespace std;

#define DEBUG 0

void (*sort[11])(int*, int, unsigned long long&, double&) = 
    {
        selectionSort_counting,
        insertionSort_counting,
        bubbleSort_counting,
        shakerSort_counting,
        shellSort_counting,
        heapSort_counting,
        mergeSort_counting,
        quickSort_counting,
        countingSort_counting,
        radixSort_counting,
        flashSort_counting
    };

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

ALGORITHM getALGORITHM(string algo, string &name_of_algorithm)
{
    if(algo == "selection-sort") {
        name_of_algorithm = "Selection Sort";
        return Selection;
    }
    if(algo == "insertion-sort") {
        name_of_algorithm = "Insertion Sort";
        return Insertion;
    }
    if(algo == "bubble-sort") {
        name_of_algorithm = "Bubble Sort";
        return Bubble;
    }
    if(algo == "shaker-sort") {
        name_of_algorithm = "Shaker Sort";
        return Shaker;
    }
    if(algo == "shell-sort") {
        name_of_algorithm = "Shell Sort";
        return Shell;
    }
    if(algo == "heap-sort") {
        name_of_algorithm = "Heap Sort";
        return Heap;
    }
    if(algo == "merge-sort") {
        name_of_algorithm = "Merge Sort";
        return Merge;
    }
    if(algo == "quick-sort") {
        name_of_algorithm = "Quick Sort";
        return Quick;
    }
    if(algo == "counting-sort") {
        name_of_algorithm = "Counting Sort";
        return Counting;
    }
    if(algo == "radix-sort") {
        name_of_algorithm = "Radix Sort";
        return Radix;
    }
    if(algo == "flash-sort") {
        name_of_algorithm = "Flash Sort";
        return Flash;
    }
    name_of_algorithm = "";
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
        nameOrder = "Randomized";
        return 0;
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
    if(order == "-nsorted")
    {
        nameOrder =  "Nearly Sorted";
        return 3;
    } 
    nameOrder = "Wrong_CMD";
    return 4;
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
    string name_algo = "";
    ALGORITHM ALGO = getALGORITHM(str_argv[2], name_algo);
    int n; //n is number of element
    int *arr;
    
    unsigned long long comparisons;
    double duration;
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
            << "Algorithm:: " << name_algo   << endl
            << "Input file: " << str_argv[3] << endl
            << "Input size: " << n << endl;
    sort[ALGO](arr, n, comparisons, duration);
    ofstream ofs("output.txt");
    ofs << n << endl;
    for(int i = 0; i < n; i++)
        ofs << arr[i] << " ";
    if(PARAM == Time)
        cout << "Runing time: " << duration << endl;
    else if(PARAM == Comp)
        cout << "Comparisons: " << comparisons << endl;
    else if(PARAM == Both)
    {
        cout << "Runing time: " << duration << endl;
        cout << "Comparisons: " << comparisons << endl;
    }
    delete []arr;
    return true;
}

bool Command2(vector<string> str_argv)
{
    string name_Algo, NameORDER;
    ALGORITHM ALGO = getALGORITHM(str_argv[2], name_Algo);
    int ORDER = getORDER(str_argv[4], NameORDER);
    Parameter PARAM = getParameter(str_argv[5]);
    if(ALGO == Wrong_CMD_ALGO || PARAM == Wrong_CMD_Param) 
    {
        cout << "algorithm or output parameter is not correct.";
        return 0;
    }
    if(ORDER == 4)
    {
        cout << "algorithm or output parameter is not correct.";
        return 0;
    }
    if(isNumber(str_argv[3]) == false)
    {
        cout << "size is not a number.";
        return 0;
    }

    unsigned long long comparisons;
    double duration;
    int n = stoi(str_argv[3]);
    int* arr = new int[n];

    cout << "ALGORITHM MODE\n"
            << "Algorithm: " << name_Algo << endl
            << "Input size: " << n << endl;

    GenerateData(arr,n, ORDER);
    sort[ALGO](arr, n, comparisons, duration);
    ofstream ofs("output.txt");
    ofs << n << endl;
    for(int i = 0; i < n; i++)
        ofs << arr[i] << " ";
    printResultAlgoMode(NameORDER, PARAM, duration, comparisons);
    delete []arr;
    return true;
}

bool Command3(vector<string> str_argv)
{
    //get the algorithm name and input size
    string algorithmName;
    ALGORITHM algorithm = getALGORITHM(str_argv[2], algorithmName);
    int inputSize = stoi(str_argv[3]);

    //prep input for sorting func
    int *arr = new int[inputSize];
    unsigned long long comparisions;
    double duration;

    //display header for the algorithm mode
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithmName << endl;
    cout << "Input size: " << inputSize << endl << endl;

    vector<string> orderInput = {"-rand", "-sorted", "-rev", "-nsorted"};
    //run the algorithm on generated data
    for (int order = 0; order < 4; order++) {
        //generate data with the specified order
        string orderName; //get the orderName ()
        GenerateData(arr, inputSize, order);
        getORDER(orderInput[order], orderName);
        //run the sorting algorithm
        sort[algorithm](arr, inputSize, comparisions, duration);
        ofstream ofs("output.txt");
        ofs << inputSize << endl;
        for(int i = 0; i < inputSize; i++)
            ofs << arr[i] << " ";
        Parameter parameter = getParameter(str_argv[4]);

        //display the result
        cout << "Input order: " << orderName << endl << "-------------------------" << endl;
        if (parameter == Comp) {
            cout << "Comparisons: " << comparisions << endl;
        } else if (parameter == Time) {
            cout << "Running time: " << duration << endl;
        } else {
            cout << "Running time: " << duration << endl << "Comparisons: " << comparisions << endl;
        }
        cout << "-------------------------" << endl << endl;
    }

    //clean up memory
    delete[] arr;
    return 1;
}

bool Command4(vector<string> str_argv)
{
    // Initialize input for sorting functions
    int n = stoi(str_argv[4]);
    int* arr = new int[n];

    string name_algo_1, name_algo_2;
    unsigned long long comparisons_algo_1, comparisons_algo_2;
    double duration_algo_1, duration_algo_2;

    ALGORITHM Algo_1 = getALGORITHM(str_argv[2], name_algo_1),
              Algo_2 = getALGORITHM(str_argv[3], name_algo_2);

    // get data order
    string str_data_order;
    int int_data_order = getORDER(str_argv[5], str_data_order);

    if(readfile(str_argv[4], arr, n) == false)
    {
        cout << "The file is not in the correct format!";
        return 0;
    }

    // count the 1st algorithm
    GenerateData(arr, n, int_data_order);
    sort[Algo_1](arr, n, comparisons_algo_1, duration_algo_1);

    // count the 2nd algorithm
    GenerateData(arr, n, int_data_order);
    sort[Algo_2](arr, n, comparisons_algo_2, duration_algo_2);
    delete []arr;

    cout << "COMPARE MODE\n"
         << "Algorithm:: " << str_argv[2] << " | " << str_argv[3] << endl
         << "Input file: " << str_argv[4] << endl
         << "Input size: " << n << endl 
         << "File input order: " << str_data_order << endl
         << "--------------------------------------------\n"
         << "Running time: " << duration_algo_1 << " | " << duration_algo_1 << endl
         << "Comparisons:  " << comparisons_algo_2 << " | " << comparisons_algo_2 << endl;
    
    delete[] arr;
    return 1;
}

bool Command5(vector<string> str_argv)
{   
    // 2 strings which contains the display styles of 2 sorting algorithms
    string name_algo_1, name_algo_2;
    // get 2 algorithms user wants to compare
    ALGORITHM algorithm_1 = getALGORITHM(str_argv[2], name_algo_1);
    ALGORITHM algorithm_2 = getALGORITHM(str_argv[3], name_algo_2);

    if (algorithm_1 == Wrong_CMD_ALGO || algorithm_2 == Wrong_CMD_ALGO) return false;

    // get data order
    string str_data_order;
    int int_data_order = getORDER(str_argv[5], str_data_order);

    if (int_data_order > 3) return false;

    // prepare input for sorting functions
    int n = stoi(str_argv[4]);
    int* data = new int[n];
    GenerateData(data, n, int_data_order);

    // output data to file
    ofstream ofs;
    ofs.open("input.txt");
    ofs << n << "\n";
    for (int i = 0; i < n; i++) ofs << data[i] << ' ';
    ofs.close();

    unsigned long long comparisons_algorithm_1, comparisons_algorithm_2;
    double duration_algorithm_1, duration_algorithm_2;

    int* arr = new int[n];

    // copy data to arr then arr will be sorted
    for (int i = 0; i < n; i++) arr[i] = data[i];
    // count the 1st algorithm
    sort[algorithm_1](arr, n, comparisons_algorithm_1, duration_algorithm_1);


    // copy data to arr then arr will be sorted
    for (int i = 0; i < n; i++) arr[i] = data[i];
    // count the 2nd algorithm
    sort[algorithm_2](arr, n, comparisons_algorithm_2, duration_algorithm_2);

    // display result
    cout << "COMPARE MODE\n"
         << "Algorithm: " << name_algo_1 << " | " << name_algo_2 << endl
         << "Input size: " << n << endl
         << "Input order: " << str_data_order << endl
         << "-------------------------" << endl
         << "Running time: " << duration_algorithm_1 << " | " << duration_algorithm_2 << endl
         << "Comparisons: " << comparisons_algorithm_1 << " | " << comparisons_algorithm_2 << endl;

    delete[] arr;
    delete[] data;
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