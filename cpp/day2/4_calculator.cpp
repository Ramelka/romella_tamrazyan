#include <iostream>

using namespace std;

int main() {
  
  float num1, num2;
  char op;
  cout << "Please enter two numbers to start calculation." << "\n";
  cout << "First number:", cin >> num1, "\n";
  cout << "Operator:", cin >> op, "\n";
  cout << "Second number:", cin >> num2, "\n";
  cout << "Result:";
  switch (op) {
    case '+' :
      cout << num1 + num2;
      break;
    case '-' :
      cout << num1 - num2;
      break;
    case '*' :
      cout << num1 * num2;
      break;
    case '/' :
      if (num2 == 0) {
        cout << "Can't divide by zero.";
      } break; 
      cout << num1 / num2;
      break;
    default :
      cout << "This operator isn't defined.Please use +,-,*,/";
  }
  return 0;
}
