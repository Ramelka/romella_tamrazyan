#include <iostream>

using namespace std;

int main () {

  int year = 2022;
  int quant = 0;
  
  cout << "  		       Next 20 leap years from " << year << " are:" << endl;
  
  while (quant < 20) {
      if (year % 4 == 0) {
          cout << year << ",";
          quant++;
      }   
      year++;
  }   
  
  cout << endl;
 
  return 0;
}

