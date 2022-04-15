#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
  public:
      int _degree;
      int *coeff;
      void InputPolynomial();
      void PrintPolynomial(int _degree, int *coeff);
      void Add(Polynomial p1, Polynomial p2);
      Polynomial operator+(const Polynomial& poly);
      void Subtract(Polynomial p1, Polynomial p2);
      Polynomial operator-(const Polynomial poly);
      void Multiply(Polynomial p1, Polynomial p2);
      Polynomial operator*(const Polynomial poly);
      void MultiplyByNumber(int num, Polynomial p1);
};

#endif
