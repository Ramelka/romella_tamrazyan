#include <iostream>

using namespace std;

const int size = 4;
//Declaration of function.
int initialize(int[size][size],int);

int main() {

  int arr1[size][size]; 
  int arr2[size][size]; 
  int sum[size][size];

//To initialize the first array.
  cout << "Array 1:" << endl;
  initialize(arr1,size);
  cout << endl;
  
//To initialize the second array.
  cout << "Array 2:" << endl;
  initialize(arr2,size);
  cout << endl;
  
//Amount of two arrays.
  cout << "Sum of arrays:" << endl;
  
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      sum[i][j] = arr1[i][j] + arr2[i][j];
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

//Definition of function.
int initialize(int arr1[size][size],int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      arr1[i][j] = rand() % 10;
      cout << arr1[i][j] << " ";
      }
    cout << endl;
    }
  return 0;
}

