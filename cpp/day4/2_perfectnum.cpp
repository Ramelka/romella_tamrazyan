#include <iostream>
#include <cmath>

using namespace std;

bool perfnum(int);

int main() {
  
  int n;
  cout << "Please enter a natural number." << endl;
  cin >> n;
  if (perfnum(n) == true)
       cout << "The number is perfect." << endl;
  else cout << "The num isn't perfect." << endl;

  return 0;
}

bool perfnum (int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) 
      sum = sum + i;  
  }

  if (n == sum)
       return true;
  else return false;

}  
