#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  
  int quant = 0;
  
  do {
      cout << "How many numbers do you want to generate?" << endl;
      cin >> quant;
  } while (quant > 100);

  int array1[100];
  int array2[100];
  
  srand(time(0));

  cout << "Input: ";
  for (int i = 0; i < quant; i++) {
      array1[i] = rand()%100 + 1;
      cout << array1[i] << " ";
  }

  cout << endl;
    
  for (int i = 0; i < quant; i++) {
      array2[i] = array1[quant - i - 1]; 
  }
  
  cout << "Output: ";
  for (int i = 0; i < quant; i++) {
      cout << array2[i] << " ";
  }   
  cout << endl;

  return 0;
}
