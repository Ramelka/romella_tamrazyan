#include <iostream>

using namespace std;

void sum(int *arr, int size);

int main() {
 
  int arr[20] = { 10, 0, 2, -5, -15, 30 };
  sum(arr, 20);
 
  return 0;
}

void sum(int *arr, int size) {
    
  int sum = 0;
  int *ptr;
  ptr = arr;
  for (int i = 0; i < size; i++) {
    sum = sum + *(arr + i);
  }
    cout << "Sum of array numbers = " << sum << endl;
}
  
