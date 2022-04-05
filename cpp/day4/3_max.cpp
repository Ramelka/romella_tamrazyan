#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  int num;
  do {
      cout << "How many numbers do you want to generate?" << endl;
      cin >> num;
  } while (num > 100);
  
  int array[100];
  srand(time(0));
  
  for (int i = 0; i < num; i++) {
      array[i] = rand() % 100 + 1;
      cout << array[i] << ", ";
  }
  cout << endl;
    
  int max = array[0];
  
  for (int i = 1; i < num; i++) {
      if (max < array[i])
          max = array[i];
  }
  cout <<  "Max" << " = " << max << endl;
  return 0;
}

