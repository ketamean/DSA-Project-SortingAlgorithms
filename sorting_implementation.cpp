#include "DataGenerator.cpp"
enum SORTING_ALGORITHM {
    SELECTION_SORT,
    INSERTION_SORT,
    BUBBLE_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT,
    RADIX_SORT,
    SHAKER_SORT, 
    SHELL_SORT,
    COUNTING_SORT,
    FLASH_SORT
};
///////////////////////////////////////
////////////////////////////////////////
// SELECTION SORT
void selectionSort_sort(int arr[], int n, unsigned long long &comparisions) {
    for (int i = 0; ++comparisions && i < n; i++) {
        int minIndex = i, minVal = arr[i];

        for (int j = i + 1; ++comparisions && j < n; j++) {
            if (++comparisions && arr[j] < minVal) {
                minVal = arr[j];
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void selectionSort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    comparisions = 0;
    duration = 0;
    double start = clock(); //get current time

    selectionSort_sort(arr, n, comparisions);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END SELECTION SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// INSERTION SORT
void insertion_sort(int arr[], int n, unsigned long long &comparisions)
{
    int i, key, j;
    for (i = 1; ++comparisions && i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements that are greater than the key 
        //(which also is +1 index greater than the sorted part ending index) to one position ahead of their current position
        while (++comparisions && j >= 0 && ++comparisions && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertion_sort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    comparisions = 0;
    duration = 0;
    double start = clock(); //get current time
    insertion_sort(arr, n, comparisions);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
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

////////////////////////////////////////
////////////////////////////////////////
// SHAKER SORT
void shakerSort_sort(int arr[], int n, unsigned long long &comparisions) {
    bool swapped = true;
    int begin = 0, end = n - 1;

    while (++comparisions && swapped) {
        //set swap = false
        swapped = false;

        //loop from left to right
        for (int i = begin; ++comparisions && i < end; ++i) {
            if (++comparisions && arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }

        //if the arr is already sorted, end loop
        if (++comparisions && !swapped) break;

        end--;

        //loop from right to left w same comparisions
        for (int i = end - 1; ++comparisions && i >= begin; --i) {
            if (++comparisions && arr[i] >= arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        //increase the starting point
        ++begin;
    }
}

void shakerSort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    comparisions = 0;
    duration = 0;
    double start = clock();

    shakerSort_sort(arr, n, comparisions);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
}
// END SHAKER SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// SHELL SORT
void shellsort(int arr[], int n, unsigned long long &comparisions) {
    // Pick a big interval value, in this case is n/2
    for (int interval = n/2; ++comparisions && interval > 0; interval/= 2)
    {
        // Keep adding more element until the array is sorted 
        for (int i = interval; ++comparisions && i < n; i += 1)
        {
            int j; 
            // add a[i] to the elements that have been gap sorted
            // save a[i] to a temporary variable to make a gap at position i
            int temp = arr[i];
            // push already sorted elements up until the correct location for a[i] is founded     
            for (j = i; ++comparisions && j >= interval && ++comparisions && arr[j - interval] > temp; j -= interval)
                arr[j] = arr[j - interval];
              
            // insert a[i] 
            arr[j] = temp;
        }
    }
    return;
}

void shellSort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    comparisions = 0;
    duration = 0;
    double start = clock(); //get current time
    shellsort(arr, n, comparisions);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
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

////////////////////////////////////////
////////////////////////////////////////
// MERGE SORT

//func to merge two subarrays
//src: https://www.geeksforgeeks.org/merge-sort/
void mergeSort_merge (int arr[], int const left, int const mid, int const right, unsigned long long &comparisions) {
    int const subArr1 = mid - left + 1;
    int const subArr2 = right - mid;

    int *leftArr = new int[subArr1]; //first tmp arrays
    int *rightArr = new int[subArr2]; //second tmp arrays

    //Copy data to tmp arr
    for (int i = 0; ++comparisions && i < subArr1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; ++comparisions && j < subArr2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int subArr1Index = 0, subArr2Index = 0;
    int mergeArrIndex = left;

    //merge the tmp arrays back into array
    while (++comparisions && subArr1Index < subArr1 && subArr2Index < subArr2) {
        if (++comparisions && leftArr[subArr1Index] < rightArr[subArr2Index]) {
            arr[mergeArrIndex] = leftArr[subArr1Index];
            subArr1Index++;
        } else {
            arr[mergeArrIndex] = rightArr[subArr2Index];
            subArr2Index++;
        }
        mergeArrIndex++;
    }

    //Copy the remaining elements
    while (++comparisions && subArr1Index < subArr1) {
        arr[mergeArrIndex] = leftArr[subArr1Index];
        subArr1Index++;
        mergeArrIndex++;
    }

    while (++comparisions && subArr2Index < subArr2) {
        arr[mergeArrIndex] = rightArr[subArr2Index];
        subArr2Index++;
        mergeArrIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

//function to divide arr
//begin = left index, end = right index of the sub-array of arr to be sorted
void mergeSort_divide(int arr[], unsigned long long &comparisions, int const begin, int const end) {
    if (comparisions++ && begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    comparisions++;
    mergeSort_divide(arr, comparisions, begin, mid);
    comparisions++;
    mergeSort_divide(arr, comparisions, mid + 1, end);
    mergeSort_merge(arr, begin, mid, end, comparisions);
}

void mergeSort_counting(int arr[], int n, unsigned long long &comparision, double &duration) {
    comparision = 0;
    duration = 0;
    double start = clock(); //get current time

    mergeSort_divide(arr, comparision, 0, n - 1);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END MERGE SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// QUICK SORT
int MedianOfThree(int arr[], int left, int right, unsigned long long &comparisons)
{
    //l <= m <= r
    int mid = (left + right)/2;
    if(++comparisons && arr[left] > arr[right])
        swap( arr[right], arr[left]);
    if(++comparisons && arr[mid] > arr[right])
        swap(arr[right], arr[mid]);
    if(++ comparisons && arr[left] > arr[mid])
        swap(arr[mid], arr[left]);
    int median = arr[mid];
    swap(arr[mid], arr[right - 1]);
    return median;
}
int partition(int arr[], int low, int high, unsigned long long &comparisons)
{
    int pivot = MedianOfThree(arr, low, high, comparisons);
    
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int ind_p1 = low - 1;
    for (int i = low; i < high - 1; i++) {
        if (arr[i] <= pivot)
        {
            ind_p1 ++;
            swap(arr[ind_p1], arr[i]);
        }
    }
    swap(arr[ind_p1 + 1], arr[high - 1]);
    return (ind_p1 + 1);
}
 
void quickSort(int arr[], int start, int end, unsigned long long &comparisons)
{ 
    // base case
    if (++comparisons && start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end, comparisons);
 
    // Sorting the left part
    quickSort(arr, start, p - 1, comparisons);
 
    // Sorting the right part
    quickSort(arr, p + 1, end, comparisons);
}

void quickSort_counting(int arr[], int n, unsigned long long &comparisons, double &duration)
{
    comparisons = 0;
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
void countingSort_counting(int a[], int n, unsigned long long &comparisons, double &duration) {

}
// END COUNTING SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// RADIX SORT
//https://www.geeksforgeeks.org/radix-sort/

/*-----------Supporting functions-----------*/
// Getting the max value in arr[]
int getMax(int arr[], int n, unsigned long long &comparisons)
{
    int mx = arr[0];
    for (int i = 1; ++comparisons && i < n; i++)
        if (++comparisons && arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Using counting sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp, unsigned long long &comparisons)
{
    int *output = new int[n]; //Create boxes to store indie values
    int i, count[10] = {0};

    // Store number of occurrences in count[] for each exp
    for (i = 0; ++comparisons && i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position of this digit in output[]
    for (i = 1; ++comparisons && i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; ++comparisons && i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; ++comparisons && i < n; i++)
        arr[i] = output[i];
    delete []output;
}

/*-----------Main function-----------*/
void radixSort(int arr[], int n, unsigned long long &comparisons) {
    // Find the maximum number to
    // know number of digits
    int m = getMax(arr, n, comparisons);

    // Do counting sort for every digit.
    // NOTE: exp is passed instead of digit number. 
    // exp is 10^i where i is current digit number.
    for (int exp = 1; ++comparisons && m / exp > 0; exp *= 10)
        countSort(arr, n, exp, comparisons);   
}

void radixSort_counting(int arr[], int n, unsigned long long &comparisons, double &duration) {
    comparisons = 0;
    double start = clock();
    radixSort(arr, n, comparisons);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
}
// END RADIX SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// FLASH SORT
//reference: https://www.studocu.com/vn/document/truong-dai-hoc-su-pham-ky-thuat-thanh-pho-ho-chi-minh/computer-architecture-and-assembly-language/flash-sort/60588066
void Flashsort(int *arr, int n, unsigned long long &comparisons)
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
    insertion_sort(arr, n, comparisons);
}

void flashSort_counting(int arr[], int n, unsigned long long &comparisons, double &duration)
{
    comparisons = 0;
    double start = clock(); //get current time
    Flashsort(arr, n, comparisons);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END FLASH SORT
////////////////////////////////////////
////////////////////////////////////////

// main for debugging
// int number_of_element[] = {10000, 30000, 50000, 100000, 300000, 500000};
// int main () {
//     int arr[500000];
//     int n = 10;

//     unsigned long long count;
//     double duration;
//     cout << "comparisons,duration" << endl;
//     for (int i = 0; i < 1; i++) {
//         n = number_of_element[i];
//         GenerateRandomData(arr, n);
//         cout << "Heap: ";
//         quickSort_counting(arr, n, count, duration);
//         cout << count << "," << duration << endl;
//         for(int i = 0; i < n - 1; i++)
//             if(arr[i] > arr[i+1])
//                 cout << "false";
        
//     }

//     /* unsigned long long count2;
//     double duration2;
//     for (int i = 0; i < 6; i++) {
//         n = number_of_element[i];
//         GenerateRandomData(arr, n);
//         cout << "Insert: ";
//         insertion_sort_counting(arr, n, count2, duration2);
//         cout << count2 << "," << duration2 << endl;
//     } */

//     /* unsigned long long count3;
//     double duration3;
//     for (int i = 0; i < 6; i++) {
//         n = number_of_element[i];
//         GenerateRandomData(arr, n);
//         cout << "Shell: ";
//         shellsort_counting(arr, n, count3, duration3);
//         cout << count3 << "," << duration3 << endl;
//     } */
//     return 0;
// }
