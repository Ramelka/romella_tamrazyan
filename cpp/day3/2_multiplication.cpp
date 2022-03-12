#include <iostream>

using namespace std;

int main () {

  int n;

  cout << "Please enter a number." << endl;
  cin >> n;

  for (int m = 0; m < 10; m++) {
    cout << n << " x " << m << " = " << (n * m) << endl; 
  }

  return 0;
}


