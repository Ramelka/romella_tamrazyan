#include <iostream>

using namespace std;

int legcount(int ch, int c, int p) {
  return (ch * 2 + (c + p) * 4);
}

int main () {

  int ch, c, p, legs; // ch for chicken; c for cow; p for pig 

  cout << "How many chickens,cows and pigs do you have?" << endl;
  cin >> ch >> c >> p;
  
  cout << "chickens = " << ch << endl;
  cout << "cows = " << c << endl;
  cout << "pigs = " << p << endl;
  
  legs = legcount(ch, c, p);
  
  cout << "Total legs = " << legs;
  
  return 0;
}
