#include <iostream>
#include <ctime>

using namespace std;

void Print(int arr[], int size1) {
    for (int i = 0; i < size1; ++i) { 
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void Merge(int* arr, int left, int middle, int right) {
    
    int leftArrSize = middle - left + 1;
    int rightArrSize = right - middle;

    int *leftArr = new int[leftArrSize];
    for (int i = 0; i < leftArrSize; ++i) {
        leftArr[i] = arr[left + i];
    }
    // Print(leftArr, leftArrSize);

    int *rightArr = new int[rightArrSize];
    for (int i = 0; i < rightArrSize; ++i) {
        rightArr[i] = arr[middle + 1 + i];
    }
    // Print(rightArr, rightArrSize);
    
    // l for left array index, r for right array index, m for merged array index
    int l = 0, r = 0, m = left;
    while (l < leftArrSize && r < rightArrSize) {
        if (leftArr[l] <= rightArr[r]) {
            arr[m] = leftArr[l];
            ++l;
        } else { 
            arr[m] = rightArr[r];
            ++r;
        }
        ++m;
    }

    while (l < leftArrSize) {
        arr[m] = leftArr[l];
        ++l;
        ++m;
    }

    while (r < rightArrSize) {
        arr[m] = rightArr[r];
        ++r;
        ++m;
    }
    
    delete leftArr;
    delete rightArr;
}

void MergeSort(int* arr, int left, int right) {
    int middle;
    if (left < right) {
        middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

int main() {

    const int size = 10;
    int arr[size];
    
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    cout << "Before sorting\n";
    Print(arr, size);
    
    int left = 0;
    int right = size - 1;
    MergeSort(arr, left, right);
    
    cout << "After sorting\n";
    Print(arr, size);
}