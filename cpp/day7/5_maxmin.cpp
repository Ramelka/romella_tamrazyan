#include <iostream>
#include <cstdlib>

using namespace std;

void maxMin(int *arr, int size);

int main() {
  const int n = 8;
  int arr[n];
 
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10;
    cout << arr[i] << " ";
  }
  
  cout << endl;
  
  maxMin(arr, n);
  
  return 0;
  
}
void maxMin(int *arr, int size) {
  int min = * arr;
  int max = * arr;
  int i = 0;
  
  while (i < size) {
    if (min > * (arr + i)) {
      min = * (arr + i);
    } else if (max < * (arr + i)) {
      max = * (arr + i);
    }
    i++;
  }
  
  cout << "Minimum = " << min << endl << "Maximum = " << max;
}
