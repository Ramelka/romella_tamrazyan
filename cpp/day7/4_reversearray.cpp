#include <iostream>
#include <cstdlib>
 
using namespace std;

void reverse(int *arr, int size);

int main() {
  const int n = 6;
  int arr[n];

  cout << "Input: ";
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
    cout << arr[i] << " ";
  }

  cout << endl;
  
  reverse(arr, n);
  
  return 0;
}

void reverse(int *arr, int size) {
  int tmp;
  for (int i = 0; i < size / 2; i++) {
    tmp = * (arr + i);
    *(arr + i) = * (arr + size - 1 - i);
    *(arr + size - 1 - i) = tmp;

  }
  cout << "Output: ";
  
  for (int i = 0; i < size; i++) {
    cout << * (arr + i) << " ";
  }
}

