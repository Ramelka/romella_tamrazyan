#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int main() {

  srand(time(0));

  int arr[10];
  int a, b , c = 0, m = 0;
  for (int i = 0; m < 10; i++) {
      a = rand() % 20;
      b = rand() % 20;
      c = pow(a, 2) + pow(b, 2);
      
      if (c % 5 == 0) {
          arr[m] = c;
          cout << a << '*' << a << "+" << b << '*' << b << '=' <<  arr[m] << endl;
	  m++;
      }
  }
  return 0;
}
