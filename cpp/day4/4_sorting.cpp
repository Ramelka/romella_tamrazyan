#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  int quant = 0, x = 0;
  do {
      cout << "How many numbers do you want to generate?" << endl;
      cin >> quant;
  } while (quant > 100);

  int array[100];
  srand(time(0));

  cout << "Input: ";

  for (int i = 0; i < quant; i++) {
      array[i] = rand() % 100 + 1;
      cout << array[i] << " ";
  }
  
  cout << endl;

  for (int i = 0; i < quant; i++) {
      for (int j = i + 1; j < quant; j++) {
          if (array[i] > array[j]) {
              x = array[i];
              array[i] = array[j];
              array[j] = x;
          } 
      }
  }

  cout << "Output: ";

  for (int i = 0;  i < quant; i++) {
      cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
