#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Enter a size for tree" << endl;
  cin >> n;
  
  //Number 1
  int i = 0, j = 0;
  while (i < n) {
    while (j <= i) {
      cout << "*";
      j++;
    }
    j = 0;
    cout << endl;
    i++;
  }
  
  cout << endl;
	  
  //Number 2
  i = n;
  while (i > 0) {
    while (j < i) {
      cout << "*";
      j++;
    }
    j = 0;
    cout << endl;
    i--;
  }

  cout << endl;

  //Number 3
  while (i < n) {
    while (j < ( n - i - 1)) {
      cout << " ";
      j++;
    }	
    int x = 0;
    while (x <= i) {
      cout << "*";
      x++;
    }
    j = 0;
    cout << endl;
    i++;
  }

  //Number 4
  int x = 0;
  i = 0, j = 0;
  while (i < n) {
    while (x <= (n - i - 1)) {
      cout << " ";
      x++;
    }
    x = 0;
    while (j < 2 * i - 1) {
      cout << "*";
      j++;
    }
    j = 0;
    cout << endl;
    i++;
  }
  return 0;
}
