#include <iostream>

using namespace std;

int perimeter(int a, int b);
int area(int a, int b);

int main () {

  int width = 0, length = 0, P = 0, S = 0;
 
  cout << "What are the sides of a rectangle?" << endl;
  cout << "width = "; cin >> width; 
  cout << "length = "; cin >> length;

  P = perimeter(width, length);
  cout << "P = " << P << endl;

  S = area(width, length);
  cout << "S = " << S << endl;

  return 0;
}
int perimeter(int a, int b) {
  return (2 * (a + b));
}
int area(int a, int b) {
  return (a * b);
}


