#include <iostream>

using namespace std;

int leap(int year);
int main () {

  int year = 2020;
    
  for (int n = 0; n < 20; n++) {
    if (leap(year)) {
      year += 4;
    } 
  }  
  return 0;
}
int leap(int year) {
  if (year % 4 == 0 && year % 100 != 0)
    cout << year << endl;
}
