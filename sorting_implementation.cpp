#pragma once
#include "DataGenerator.cpp"
// enum SORTING_ALGORITHM {
//     SELECTION_SORT,
//     INSERTION_SORT,
//     BUBBLE_SORT,
//     HEAP_SORT,
//     MERGE_SORT,
//     QUICK_SORT,
//     RADIX_SORT,
//     SHAKER_SORT,
//     SHELL_SORT,
//     COUNTING_SORT,
//     FLASH_SORT
// };
///////////////////////////////////////
////////////////////////////////////////
// SELECTION SORT
void selectionSort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    double start = clock(); //get current time
    comparisions = 0;
    
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
void shakerSort_counting(int arr[], int n, unsigned long long &comparisions, double &duration) {
    double start = clock();
    bool swapped = true;
    int begin = 0, end = n - 1;
    comparisions = 0;

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
void heapSort_heapRebuild(int a[], int n, int pos, unsigned long long &comparisons) {
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
void heapSprt_heapConstruction(int a[], int n, unsigned long long &comparisons) {
    for (int i = n/2 - 1; ++comparisons && i >= 0; --i) {
        heapSort_heapRebuild(a, n, i, comparisons);
    }
}

void heapSort(int a[], int n, unsigned long long &comparisons) {
    heapSprt_heapConstruction(a, n, comparisons);
    unsigned int sorted_part = n - 1;
    while (++comparisons && sorted_part > 0) {
        swap(a[0], a[sorted_part]);
        heapSort_heapRebuild(a, sorted_part, 0, comparisons);
        sorted_part--;
    }
}

void heapSort_counting(int a[], int n, unsigned long long &comparisons, double &duration) {
    comparisons = 0;
    duration = 0;
    double start = clock();
    heapSort(a, n, comparisons);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END HEAP SORT
////////////////////////////////////////
////////////////////////////////////////

////////////////////////////////////////
////////////////////////////////////////
// MERGE SORT

//func to merge two subarrays
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
    while (++comparisions && subArr1Index < subArr1 && ++comparisions && subArr2Index < subArr2) {
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
    if (begin >= end) {
        comparisions++;
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
    double start = clock(); //get current time
    comparision = 0;

    mergeSort_divide(arr, comparision, 0, n - 1);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
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
    comparisons = 0;
    double start = clock(); //get current time
    quickSort(arr, 0, n - 1, comparisons);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}

//reference: https://www.studocu.com/vn/document/truong-dai-hoc-su-pham-ky-thuat-thanh-pho-ho-chi-minh/computer-architecture-and-assembly-language/flash-sort/60588066

// END QUICK SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// COUNTING SORT
// src: https://www.geeksforgeeks.org/counting-sort/
int* countingSort(int a[], int n, unsigned long long &comparisons) {
    // it was guranteed that all a[i] are non-negative integers
    int i;

    // find max of array `a`
    int max_element = a[0];
    for (i = 1; ++comparisons && i < n; ++i) {
        if (++comparisons && a[i] > max_element) max_element = a[i];
    }

    int* occurrences = new int[max_element + 1]{0};
    for (i = 0; ++comparisons && i < n; ++i) {
        occurrences[a[i]]++;
    }

    // change occurrences[i] so that occurrences[i] now contains actual positions of this character in output array
    for (i = 1; ++comparisons && i < max_element + 1; ++i) {
        occurrences[i] = occurrences[i] + occurrences[i - 1];
    }

    // build output array
    int* output_array = new int[n];
    for (i = 0; ++comparisons && i < n; i++) {
        output_array[occurrences[a[i]]] = a[i];
        occurrences[a[i]]--;
    }

    return output_array;
}
void countingSort_counting(int a[], int n, unsigned long long &comparisons, double &duration) {
    comparisons = 0;
    double start = clock();
    int* res = countingSort(a, n, comparisons);
    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++) a[i] = res[i];
    delete[] res;
}
// END COUNTING SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// RADIX SORT
void radixSort(int a[], int n, unsigned long long &comparisons) {
    
}
void radixSort_counting(int a[], int n, unsigned long long &comparisons, double &duration) {
    comparisons = 0;
}
// END RADIX SORT
////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////////
////////////////////////////////////////
// FLASH SORT
void InsertionSort(int *arr, int n, unsigned long long &comparisons)
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
    InsertionSort(arr,n, comparisons);
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
