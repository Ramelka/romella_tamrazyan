#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  int n, i, j, x;
  do {
    cout << "How many numbers do you want to generate?" << endl;
    cin >> n;
  } while (n > 100);

  int array[100];
  srand(time(0));

  cout << "Input: ";

  for (int i = 0; i < n; i++) {
    array[i] = rand()%100 + 1;
    cout << array[i] << " ";
  }
  
  cout << endl;

  for (i = 0; i < n; i++) {

    for (j = i + 1; j < n; j++) {
      if (array[i] > array[j]) {
        x = array[i];
        array[i] = array[j];
        array[j] = x;
      }
    }
  }

  cout << "Output: ";

  for (int i = 0;  i < n; i++) {
    cout << array[i] << " ";
  }
  return 0;
}
