#include <iostream>

using namespace std;

int main () {

  int n;

  do {
    cout << "Please enter a month number to know the total days of that month." << endl;
    cin >> n;
  } while (n < 1 || n > 12);

  switch (n) {
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10 :
    case 12 :
      cout << "The total number of days in the month is 31.";
      break;
    case 2 :
      cout << "The total number of the month is 28 or 29.";
      break;
    case 4 :
    case 6 :
    case 9 :
    case 11 :
      cout << "The total number of the month is 30.";
      break;
  }	   
  return 0;
}
