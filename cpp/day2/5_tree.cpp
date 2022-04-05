#include <iostream>

using namespace std;

int main() {
  int size;
  cout << "Enter a size for tree" << endl;
  cin >> size;

  //Number 1
  for (int i = 0; i < size; i++) {
      for (int j = 0; j <= i; j++) {
          cout << "*";
      }
      cout << endl;
  }

  cout << endl;

  //Number 2
  for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
          cout << "*";
      }
      cout << endl;
  }

  cout << endl;

  //Number 3
  for (int i = 0; i < size; i++) {
      for (int j = i; j < size - 1; j++) {
          cout << " ";
      }
      for (int k = 0; k <= i; k++) {
          cout << "*";
      }
      cout << endl;
  }

  cout << endl;

  //Number 4
  for (int i = 0; i < size; i++) {
      for (int j = i; j < size - 1; j++) {
          cout << " ";
      }
      for (int k = 0; k < 2 * i - 1; k++) {
          cout << "*";
      }
      cout << endl;
  }

  cout << endl;

  return 0;
}
