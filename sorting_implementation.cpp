#include "DataGenerator.cpp"
///////////////////////////////////////
////////////////////////////////////////
// SELECTION SORT
void selectionSort_counting(int arr[], int n, int &comparisions, double &duration) {
    double start = clock(); //get current time
    
    for (int i = 0; i < n; i++) {
        int minIndex = i, minVal = arr[i];

        for (int j = i + 1; j < n; j++) {
            if (++comparisions && arr[j] < minVal) {
                minVal = arr[j];
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
    cout << "Operation took: " << duration << "secs." << endl;
}
// END SELECTION SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// INSERTION SORT

// END INSERTION SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// BUBBLE SORT
// src: https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    comparisions = 0;
    duration = 0;
    int i = 0;
    bool swapped;
    double start = clock(); // get starting time
    while (++comparisions && i < n - 1) {
        swapped = false;
        int j = 0;
        while (++comparisions && j < n - i - 1) {
            if (++comparisions && arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
            j++;
        }
        if (swapped == false) {
            break;
        }
        i++;
    }
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
}
// END BUBBLE SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// SHAKER SORT

// END SHAKER SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// SHELL SORT

// END SHELL SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// HEAP SORT
/// @param pos the position at which we start to build the heap
void heap_rebuild(int a[], int n, int pos, unsigned long long &comparisons) {
    bool is_heap = false;
    int k;
    while (is_heap == false && ++comparisons && 2*pos + 1 < n) {
        k = 2*pos + 1;
        if (++comparisons && k < n - 1 && ++comparisons && a[k] < a[k + 1]) k = k + 1;
        if (++comparisons && a[k] > a[pos]) {
            swap(a[k], a[pos]);
            k = pos;
        } else is_heap = true;
    }
}
void heap_construction(int a[], int n, unsigned long long &comparisons) {
    for (int i = n/2 - 1; ++comparisons && i >= 0; --i) {
        heap_rebuild(a, n, i, comparisons);
    }
}

void heapSort_counting(int a[], int n, unsigned long long &comparisons, double &duration) {
    comparisons = 0;
    duration = 0;
    double start = clock();
    heap_construction(a, n, comparisons);
    unsigned int sorted_part = n - 1;
    while (++comparisons && sorted_part > 0) {
        swap(a[0], a[sorted_part]);
        heap_rebuild(a, sorted_part, 0, comparisons);
        sorted_part--;
    }
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END HEAP SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// MERGE SORT

// END MERGE SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// QUICK SORT
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end, unsigned long long &comparisons)
{ 
    // base case
    if (++comparisons && start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1, comparisons);
 
    // Sorting the right part
    quickSort(arr, p + 1, end, comparisons);
}

void quickSort_counting(int arr[], int n, unsigned long long &comparisons, double &duration)
{
    double start = clock(); //get current time
    quickSort(arr, 0, n - 1, comparisons);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}

// END QUICK SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// COUNTING SORT

// END COUNTING SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// RADIX SORT

// END RADIX SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// FLASH SORT
void InsertionSort(int *arr, int n, int &comparisons)
{
    int value_i, pos;
    for(int i = 1;(++comparisons) && i < n ; i++)
    {
        value_i = arr[i];
        pos = i - 1; // previous position
        while(++comparisons && 0 <= pos && ++comparisons &&  value_i < arr[pos])
        {
            //shift up value of pos to pos + 1
            arr[pos + 1] = arr[pos];
            pos --;
        }

        //pos = - 1 or arr[pos] <= value_i  
        //add value i to pos + 1
        arr[pos + 1] = value_i;
    }
}

void Flashsort(int *arr, int n, int &comparisons)
{
    double start = clock(); //get current time

    if(++comparisons && n <= 0)
        return;
    //find min and max of the array to be sorted
    int min, max;
    min = max = arr[0];
    for(int i = 0; ++comparisons && i < n; i++)
    {
        if(++comparisons && arr[i] < min)
            min = arr[i];
        if(++comparisons && arr[i] > max)
            max = arr[i];
    }

    //if the element in arr are the same, don't need arrange
    if(++comparisons && min == max)
        return;

    //Step 2: Declare 1 dynamic array class with m element
    int m = std::floor(0.45 * n); // number of classes
    int *cls = new int[m];
    for(int i = 0; ++comparisons && i < m; i++)
        cls[i] = 0;

    //Step 3: count number of element in classes to rule
    //element arr[i] will of class k với k = floor( (m - 1) * (arr[i] - min) / (max - min) )
    for(int i = 0; ++comparisons && i < n; i++)
    {
        int k = std::floor( 1.0 * (m - 1) * (arr[i] - min) /  (max - min));
        cls[k] ++;
    }

    //Step 4 Calc end position of each class z according to the formula
    //cls[z] = cls[z] + cls[z-1];
    for(int i = 1; ++comparisons && i < m; i++)
        cls[i] += cls[i-1];
    

    //Step 5 global permutation
    //Put the element to be subclassed in the appropriate position
    //-> lift the currently occupied element
    //-> continue the cycle with the new element to be subclassed
    //-> repeat until it returns to the original position, then complete the loop
    
    int move = 0, i = 0;
    while(++comparisons && move < n - 1)
    {
        //k is position of class a[i]
        int k = std::floor( 1.0 * (m - 1) * (arr[i] - min) / (max - min));
        //When i >= cls[k] means that arr[i] is already in its subclass position
        //so we ignore and continue to increase i to consider the next elements

        while(++comparisons && i >= cls[k])
        {
            i++;
            k = std::floor( 1.0 * (m - 1) * (arr[i] - min) / (max - min));
        }
        int flash = arr[i]; // element ready to be subclassed
        // When i = cls[k] is equivalent to subclassing k is full, so when it is not full, we continue to iterate
        // every time we return an element that matches its subclass, we reduce the last position of that subclass
        // at the same time increase the night variable the number of swaps by one unit
        while(++comparisons && i != cls[k])
        {
            k = std::floor( 1.0 * (m - 1) * (arr[i] - min) / (max - min));
            cls[k]--;
            int hold = arr[cls[k]];
            arr[cls[k]] = flash;
            flash = hold; // put the element in the wrong place and assign it to the molecule and prepare it for subclassing
            move++;
        }
    }
    InsertionSort(arr,n, comparisons);
}

void flashSort_counting(int arr[], int n, int &comparisons, double &duration)
{
    double start = clock(); //get current time
    Flashsort(arr, n, comparisons);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END FLASH SORT
////////////////////////////////////////
////////////////////////////////////////

// main for debugging
int number_of_element[] = {10000, 30000, 50000, 100000, 300000, 500000};
int main () {
    int arr[500000];
    int n = 10;
    unsigned long long count;
    double duration;
    cout << "comparisons,duration" << endl;
    for (int i = 0; i < 6; i++) {
        n = number_of_element[i];
        GenerateRandomData(arr, n);
        heapSort_counting(arr, n, count, duration);
        cout << count << "," << duration << endl;
    }
    return 0;
}