#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
  private:
      int _degree1, _degree2;
      int *arr1 = new int[_degree1 + 1];
      int *arr2 = new int[_degree2 + 1];
      int *arr3 = new int[10];
  public:
      void InputPolynomial();
      void Add();
      void Subtract();
      void Multiply();
};

#endif
