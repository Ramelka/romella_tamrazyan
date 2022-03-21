#include <iostream>
#include <cstdlib>

using namespace std;

void increasePart(int arr[], int size);
int main() {

  srand(time(0));
  
  int size;
  cout << "Enter size of array: "; cin >> size;
  int arr[size];

  for (int i = 0; i < size; i++) {
    arr[i] =  + rand() % 21;
    cout << arr[i] << " ";
  }
  cout << endl;
  
  increasePart(arr, size);
  
  return 0;
}

void increasePart(int arr[], int size) {
  
  int temp = 1, max = 1, first_index = 0;

  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[i - 1])
      temp++;
    else {
      if (temp > max) {
        max = temp;
        first_index = i - max;
      }
      temp = 1;
    }
  } 

  if (temp > max) {
    max = temp;
    first_index = size - max;
  }
  
  for (int i = first_index; i < first_index + max; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

