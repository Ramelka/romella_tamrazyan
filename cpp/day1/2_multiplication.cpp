#include <iostream>

using namespace std;

int main () {

  int num1;
  int num2 = 0;
  int sum = 0;  
  
  cout << "Please enter a number." << endl;
  cin >> num1;
  cout << endl << "			Multiplication table of " << num1 << endl;  
  
  while (num2 < 10) {
      sum = num1 * num2;
      cout << "				" << num1 << " x " << num2 << " = " << sum << endl;
      num2++;
  }
  
  return 0;
}
