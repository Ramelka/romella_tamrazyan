#include <iostream>

using namespace std;

int main () {

  int num;
  int sum;
  
  cout << "Please enter a number " << endl;
  cout << "Num = "; cin >> num;

  sum = num;
  
  while (num > 1) {
      num--;
      sum = sum * num;
  }

  cout << "Factorial" << " = " << sum << endl;
  	
	return 0;
}
