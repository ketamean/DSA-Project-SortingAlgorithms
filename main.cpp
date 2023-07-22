#include "sorting_implementation.cpp"
#include "cmd.cpp"
void (*sorting_counter[11])(int*, int, unsigned long long&, double&) = 
    {
        selectionSort_counting,
        insertion_sort_counting,
        bubbleSort_counting,
        heapSort_counting,
        mergeSort_counting,
        quickSort_counting,
        radixSort_counting,
        shakerSort_counting,
        shellSort_counting,
        countingSort_counting,
        flashSort_counting
    };

int main (int argc, const char* argv[]) {
    vector<string> str_argv;
    for(int i = 0; i < argc; i++)
       str_argv.push_back(string(argv[i]));
    getTASK(argc,str_argv);
    return 0;
}