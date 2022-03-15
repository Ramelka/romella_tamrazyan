#include <iostream>
#include <cstdlib>

using namespace std;

int sumOfArray(int *arr, int size);

int main() {
  const int n = 5;
  int arr[n];
 
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
    cout << arr[i] << " ";
  }
  
  cout << endl;
  
  int sum = sumOfArray(arr, n);
  
  cout << "Sum of array numbers = " << sum << endl;
  return 0;
}

int sumOfArray(int *arr, int size) {
    
  int sum = 0;
  for (int *ptr = arr; ptr != (arr + size); ptr++) {
    sum += *ptr;
  }
  return sum;
fghfhfhfh}
