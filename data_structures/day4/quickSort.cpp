#include <iostream>
#include <ctime>

using namespace std;

void Print(int arr[], int size1) {
    
    for (int i = 0; i < size1; ++i) { 
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void Swap(int arr[], int num1, int num2) {
    int temp;
    temp = arr[num1];
    arr[num1] = arr[num2];
    arr[num2] = temp;
}

int Partition(int* arr, int left, int right) {

    int middle = (right + left) / 2;
    int pivot = arr[middle];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            ++i;
        }
        while (arr[j] > pivot) {
            --j;
        }
        if (i <= j) {
            Swap(arr, i, j);
            ++i;
            --j;
        }
    }
    return i;
}
    
void QuickSort (int* arr, int left, int right) {

    int middle = (right + left) / 2;
    int pivot = arr[middle];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            ++i;
        }
        while (arr[j] > pivot) {
            --j;
        }
        if (i <= j) {
            Swap(arr, i, j);
            ++i;
            --j;
        }
    }
    
    if (left < j) {
        QuickSort(arr, left, j);
    }
    if ( i < right) {
        QuickSort(arr, i, right);
    }
}

int main() {

    const int size = 5;
    int arr[size];
    
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
    cout << "Before sorting\n";
    Print(arr, size);
    
    int left = 0;
    int right = size - 1;

    QuickSort(arr, left, right);
    cout << "After sorting\n";
    Print(arr, size);
}