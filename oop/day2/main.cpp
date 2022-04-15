#include "polynomial.h"

using namespace std;
  
int main() {

  Polynomial first;
  Polynomial second;
  Polynomial result;

  first.InputPolynomial();
  second.InputPolynomial();

  result.Add(first, second);
  result.Subtract(first, second);
  result.Multiply(first, second);
  result.MultiplyByNumber(3, first);
  return 0;
}

