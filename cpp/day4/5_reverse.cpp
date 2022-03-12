#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  int n, i;
  do {
    cout << "How many numbers do you want to generate?" << endl;
    cin >> n;
  } while (n > 100);

  int array1[100];
  int array2[100];
  srand(time(0));

  cout << "Input: ";

  for (i = 0; i < n; i++) {
    array1[i] = rand()%100 + 1;
    cout << array1[i] << " ";
  }

  cout << endl;
    
  for (i = 0; i < n; i++) {
    array2[i] = array1[n - i - 1];
  }
  
  cout << "Output: ";
  
  for (i = 0; i < n; i++) {
    cout << array2[i] << " ";
  }  
  
  return 0;
}

