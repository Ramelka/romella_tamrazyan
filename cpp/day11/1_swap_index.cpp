#include <iostream>

using namespace std;

void PrintArray(int arr[], int m);

int main() {
  int p1, p2, temp;
  const int m = 5;
  int arr[m] = {1, 2, 3, 4, 5};
 
  //cout << "Enter a number to swap indexes" << endl;
 
  PrintArray(arr, m);
  cout << endl <<"Enter index positions to swap" << endl << "p1 = ";
  cin >> p1;
  cout << "p2 = ";
  cin >> p2;
  
  temp = arr[p1];
  arr[p1] = arr[p2];
  arr[p2] = temp;
  
  PrintArray(arr, m);
  
  return 0;
}
void PrintArray(int arr[], int m) {
    for (int i = 0; i < m; i++) {
      cout << arr[i] << " ";
    }
}


