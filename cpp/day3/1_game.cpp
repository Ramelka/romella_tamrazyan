#include <iostream>
#include <cstdlib>

using namespace std;

void compare (int, int);
int main () {

  int number, yournumber;

  while (!(number >= 1 && number <=100)) {
      cout << "Please enter a number" << endl;
      cin >> number;
  }   
  
  system ("clear");
    
  cout << "Try to guess the number" << endl;
  cin >> yournumber;
    
  do {
      compare (yournumber, number);
      cin >> yournumber;
  } while (number != yournumber);
      cout << "Good job! You won!\n";

  return 0;
}
void compare (int num1, int num2) {
  if (num1 > num2) {
      cout << "The memorized number is smaller than your number\n";
  } else if (num1 < num2) {
      cout << "The memorized number is bigger than your number\n";
  }
}
