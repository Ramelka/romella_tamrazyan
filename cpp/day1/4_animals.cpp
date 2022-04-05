#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

  int chickens = 0, cows = 0, pigs = 0, legs = 0;
    
  cout << "\t How many chickens, cows and pigs do you have?" << endl; 
  cout << "Chickens = "; cin >> chickens;
  cout << "Cows = "; cin >> cows;
  cout << "Pigs = "; cin >> pigs;
    
  legs = chickens * 2 + 4 * (cows + pigs);
  cout << "________________" << endl;
  cout << "Legs = " << legs << endl;

  return 0;
}   
