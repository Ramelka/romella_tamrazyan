#include <iostream>

using namespace std;

int legcount(int ch, int c, int p) {
  return (ch * 2 + (c + p) * 4);
}

int main () {

  int chickens = 0, cows = 0, pigs = 0, legs = 0; 

  cout << "How many chickens,cows and pigs do you have?" << endl; 
  cout << "chickens = "; cin >> chickens;
  cout << "cows = "; cin >> cows;
  cout << "pigs = "; cin >> pigs;
  
  legs = legcount(chickens, cows, pigs);
  
  cout << "Total legs = " << legs << endl;
  
  return 0;
}
