#include <iostream>

using namespace std;

void sum1(int *a, int *b, int *sum) {
  *sum = *a + *b;
  cout << "Sum1 = " << *sum << endl;
}

void sum2(int &a, int &b, int &sum) {
  sum = a + b;
  cout << "Sum2 = " << sum << endl;
}

void sum3(int a, int b, int &sum) {
  sum = a + b;
  cout << "Sum3 = " << sum << endl;
}

void sum4(int a, int *b, int &sum) {
  sum = a + *b;
  cout << "Sum4 = " << sum << endl;
}
void sum5(int *a, int *b, int &sum) {
  sum = *a + *b;
  cout << "Sum5 = " << sum << endl;
}

int main() {
    
  int num1, num2, sum;
  cout << "Enter two numbers to summarize them." << endl;
  cin >> num1;
  cin >> num2;
  cout << "Number1 = " << num1 << " " << "Number2 = " << num2 << endl;
 
  sum1(&num1, &num2, &sum);
  
  sum2(num1, num2, sum);
  
  sum3(num1, num2, sum);
  
  sum4(num1, &num2, sum);
  
  sum5(&num1, &num2, sum);
    
  return 0;
}
