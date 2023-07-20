//#include "sorting_implementation.cpp"
#include <iostream>
#include <ctime>
#include <random>

using namespace std;
//-------------------------------------------------
///////////////////////////////////////
////////////////////////////////////////
//PRINT ARR
void printArr(int arr[], int n,int comparision, double times) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Comparisions: " << comparision << endl;
    cout << "Running time: " << times << endl;
}
//END OF PRINT ARR
///////////////////////////////////////
////////////////////////////////////////

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void genRandomData(int a[], int n)
{
    mt19937 mt(time(nullptr));

    for (int i = 0; i < n; i++) {
        a[i] = mt()%90 + 10;
    }
}

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
}

///////////////////////////////////////
////////////////////////////////////////
// MERGE SORT

//func to merge two subarrays
void mergeSort_merge (int arr[], int const left, int const mid, int const right, int &comparisions) {
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
        if (++comparisions && leftArr[subArr1Index] <= rightArr[subArr2Index]) {
            arr[mergeArrIndex] = leftArr[subArr1Index];
            subArr1Index++;
        } else {
            arr[mergeArrIndex] = rightArr[subArr2Index];
            subArr2Index++;
            comparisions++;
        }
        mergeArrIndex++;
    }

    //Copy the remaining elements
    while (++comparisions && subArr1Index < subArr1) {
        arr[mergeArrIndex] = rightArr[subArr1Index];
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
void mergeSort_divide(int arr[], int &comparisions, int const begin, int const end) {
    comparisions++;
    if (begin >= end) {
        comparisions++;
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort_divide(arr, comparisions, begin, mid);
    mergeSort_divide(arr, comparisions, mid + 1, end);
    mergeSort_merge(arr, begin, mid, end, comparisions);
}

void mergeSort_counting(int arr[], int n, int &comparision, double &duration) {
    double start = clock(); //get current time

    mergeSort_divide(arr, comparision, 0, n - 1);
    duration = (clock() - start)/(double) CLOCKS_PER_SEC;
}
// END MERGE SORT
////////////////////////////////////////
////////////////////////////////////////

int main() {
    const int n = 10;
    int arr[n], comparision = 0;
    double duration = 0;

    genRandomData(arr, n);
    printArr(arr, n, comparision, duration);
    mergeSort_counting(arr, n, comparision, duration);
    printArr(arr, n, comparision, duration);

    return 0;
}
