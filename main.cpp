#include "sorting_implementation.cpp"

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
    
    return 0;
}