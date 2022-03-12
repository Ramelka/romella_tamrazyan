#include <iostream>

using namespace std;

int factorial(int x) {
  if (x > 1) {
    return x * factorial(x - 1);
  } else 
    return 1;
}

int main () {
  
  int x;
  
  cout << "Please enter a number " << endl;
  cin >> x;
  
  cout << "Result" << "=" << factorial(x);	
	
  return 0;
}
