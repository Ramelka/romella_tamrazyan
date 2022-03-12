#include <iostream>
#include <cstdlib>

using namespace std;

int perimeter(int a, int b);
int area(int a, int b);

int main () {

  int a, b, P, S;
 
  cout << "What are the sides of a rectangle?" << endl;
  cin >> a >> b;
    
  system("clear");
    
  cout << "a = " << a << "," << "b = " << b << endl;
  P = perimeter(a, b);
  cout << "P = " << P << endl;
  S = area(a, b);
  cout << "S = " << S;
  return 0;
}
int perimeter(int a, int b) {
  return (2 * (a + b));
}
int area(int a, int b) {
  return (a * b);
}


