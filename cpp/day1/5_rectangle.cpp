#include <iostream>

using namespace std;

int main () {

  int length = 0, width = 0, P = 0, S = 0;
  
  do {
  cout << "What are the sides of a rectangle?" << endl;
  cout << "width = "; cin >> width;
  cout << "length = "; cin >> length;
  } while (length < width);

  cout << "______________" << endl;

  P = 2 * (width + length);

  cout << "P = " << P << endl;

  S = width * length;

  cout << "S = " << S << endl;
    
  return 0;
}
