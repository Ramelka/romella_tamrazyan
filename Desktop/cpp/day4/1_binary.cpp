#include <iostream>

using namespace std;

void binary(int);

int main() {
  int n;
  cout << "Enter a natural number to convert it to binary" << endl;
  cin >> n;
  binary(n);

  return 0;
}

void binary(int n) {
  
  int array[50];
  int i;  
  for (i = 0; n > 0; i++) {
    array[i] = n % 2;
    n = n / 2;
  }
  
  for (int x = i - 1; x>= 0; x--) {
    cout << array[x];
  }
    cout << endl;
}
