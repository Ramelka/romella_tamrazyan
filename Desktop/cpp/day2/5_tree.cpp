#include <iostream>

using namespace std;

int main() {
  
  int n;
  
  do {
      cout << "Enter a positive number" << "\n";
      cin >> n;
      
  } while (n < 0);

  //Number 1
  int tmp = n;
  
  while (tmp) {
    int i = tmp;
    while (i--) {
      cout << "*";
    }
      cout << endl;
      tmp--;
  }
  cout << endl;
  
  //Number 2
  tmp = n;
  
  while (tmp) {
    int i = tmp - 1;
    while (i--) {
      cout << " ";
    }
    i = n - tmp + 1;
    while (i--) {
      cout << "*";
    }
    cout << endl;
    tmp--;
  }  
  cout << endl;
  
  //Number 3
  tmp = n;
  while (tmp) {
    int i = n - tmp + 1;
    while (i--) {
      cout << "*";
    }
    cout << endl;
    tmp--;
  }
  cout << endl;
  
  //Number 4
  tmp = n;
  
  while (tmp) {
    int i = tmp - 1;
    while (i--) {
      cout << " ";
    }
  
    i = n - tmp + 1;
    while (i--) {
    cout << "* ";
    }
    cout << endl;
    tmp--;
  } 
  return 0;
}