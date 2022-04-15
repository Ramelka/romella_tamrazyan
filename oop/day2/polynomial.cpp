#include "polynomial.h"
#include <iostream>

using namespace std;

void Polynomial::InputPolynomial() {
  cout << "Enter a degree for a polynomial: ";
  cin >> _degree;
  
  coeff = new int[_degree + 1];  
  for (int i = _degree; i >= 0; i--) {
      cout << "   Enter a coefficient of x^" << i << ": ";
      cin >> coeff[i];
  }
  PrintPolynomial(_degree, coeff);
}

void Polynomial::PrintPolynomial(int _degree, int *coeff) {
  for (int i = _degree; i >= 0; i--) {
      if (coeff[i] != 0) {
          cout << coeff[i] << "x^" << i;
      } else if (coeff[i] == 0) {
          cout << "0";
      }
      if (i != 0) {
          cout << "+";    
      }
  } 
    cout << endl;
}

void Polynomial::Add(Polynomial p1, Polynomial p2) {
  int max = 0;
  if (p1._degree >= p2._degree) 
       max = p1._degree;
  else 
       max = p2._degree;
  
  int *temp = new int[max + 1];
  
  if (p1._degree > p2._degree) {
      for (int i = 0; i <= p1._degree; i++) {
          if (i <= p2._degree) {
              temp[i] = p1.coeff[i] + p2.coeff[i];
          } else {
              temp[i] = p1.coeff[i];
          }
      }  
  } else if (p1._degree < p2._degree) {
      for (int i = 0; i <= p2._degree; i++) {
          if (i <= p1._degree)  {
              temp[i] = p1.coeff[i] + p2.coeff[i];
          } else {
              temp[i] = p2.coeff[i];
          }
       } 
  } else if (p1._degree = p2._degree) {
      for (int i = 0; i <= p2._degree; i++) {
          temp[i] = p1.coeff[i] + p2.coeff[i];
      } 
  }
  PrintPolynomial(max, temp);
  delete temp;
} 

void Polynomial::Subtract(Polynomial p1, Polynomial p2) {
  int max = 0;
  if (p1._degree >= p2._degree) 
      max = p1._degree;
  else 
      max = p2._degree;
  
  int *temp = new int[max + 1]; 

  if (p1._degree > p2._degree) {
      for (int i = 0; i <= p1._degree; i++) {
          if (i <= p2._degree) {
              temp[i] = p1.coeff[i] - p2.coeff[i];
          } else {
              temp[i] = p1.coeff[i];
          }
      }  
  } else if (p1._degree < p2._degree) {
      for (int i = 0; i <= p2._degree; i++) {
          if (i <= p1._degree)  {
              temp[i] = p1.coeff[i] - p2.coeff[i];
          } else {
              temp[i] = p2.coeff[i];
          }
      } 
       
  } else if (p1._degree = p2._degree) {
      for (int i = 0; i <= p2._degree; i++) {
          if (p1.coeff[i] - p2.coeff[i] != 0) {
              temp[i] = p1.coeff[i] - p2.coeff[i];
          }
      } 
  }
    
  PrintPolynomial(max, temp);
  delete temp;
}

void Polynomial::Multiply(Polynomial p1, Polynomial p2) {
  int max = 0;
  max = p1._degree + p2._degree;
    
  int *temp = new int[max + 1]; 

  for (int i = 0; i <= p1._degree; i++) {
      for (int j = 0; j <= p2._degree; j++) {
          temp[i + j] += p1.coeff[i] * p2.coeff[j];
      }
  } 
  PrintPolynomial(max, temp);
  delete temp;
}

void Polynomial::MultiplyByNumber(int num, Polynomial p1) {
  int max = p1._degree;
  
  int *temp = new int[max + 1]; 

  for (int i = 0; i <= p1._degree; i++) {
      temp[i] = num * p1.coeff[i];
     
  } 
  PrintPolynomial(max, temp);
  delete temp;
} 
  
