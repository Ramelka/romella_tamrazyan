#include <iostream>

using namespace std;

int main() {
  
  float num1, num2;
  char op;

  cout << "Please enter two numbers to start calculation.\n";
  cout << "First number: "; cin >> num1;
  cout << "Operator: "; cin >> op;
  cout << "Second number: "; cin >> num2;
  cout << "Result: ";

  switch (op) {
      case '+' :
          cout << num1 + num2 << endl;
          break;
      case '-' :
          cout << num1 - num2 << endl;
          break;
      case '*' :
          cout << num1 * num2 << endl;
          break;
      case '/' :
          if (num2 == 0) {
              cout << "Can't divide by zero.\n";
          } else if (num2 != 0) {
              cout << num1 / num2 << endl;
          } break;
      default :
          cout << "This operator isn't defined.Please use +,-,*,/ \n";
  }
  return 0;
}
