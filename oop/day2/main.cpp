#include "polynomial.h"
#include <iostream>

using namespace std;
void Polynomial::InputPolynomial() {
  cout << "Enter a degree for the first polynomial: ";
  cin >> _degree1;
    
  for (int i = _degree1; i >= 0; i--) {
      cout << "   Enter a coefficient of x^" << i << ": ";
      cin >> arr1[i];
  }

  cout << "Enter a degree for the second polynomial: ";
  cin >> _degree2;
    
  for (int i = _degree2; i >= 0; i--) {
      cout << "   Enter a coefficient of x^" << i << ": ";
      cin >> arr2[i];
  }   
}

int main() {

  Polynomial x;
  x.InputPolynomial();
  x.Add();
  x.Subtract();
  x.Multiply();

  return 0;
}

