#include <iostream>

using namespace std;

void binary(int);

int main() {
  
  int num;
  cout << "Enter a natural number to convert it to binary" << endl;
  cin >> num;

  binary(num);

  return 0;
}

void binary(int number) {
  
  int array[50];
  int i;
  
  for (i = 0; number > 0; i++) {
      array[i] = number % 2;
      number = number / 2;
  }
  
  for (int x = i - 1; x >= 0; x--) {
      cout << array[x];
  }
  cout << endl;
}
