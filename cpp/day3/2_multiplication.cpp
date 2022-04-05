#include <iostream>

using namespace std;

int multiplicate(int, int);
int main () {

  int num = 0;

  cout << "Please enter a number." << endl;
  cin >> num;

  for (int quant = 0; quant < 10; quant++) {
    cout << num << " x " << quant << " = " << multiplicate(num, quant) << endl; 
  }

  return 0;
}
int multiplicate(int num, int quant) {
  int sum = 0;
  sum = num * quant;

  return sum;
}


