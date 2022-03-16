#include <iostream>
#include "atoi.h"

using namespace std;

int main(int argc, char* argv[]) {
  int sum1 = 0;
  int sum2 = 0;

  for (int i = 1; i < argc; i++) {
    sum1 += atoi(argv[i]);
  }
  for (int i = 1; i < argc; i++) {
    sum2 += own_atoi(argv[i]);
  }
  cout << "Atoi = " << sum1 << endl << "My atoi = " << sum2 << endl;
  return 0;

}
