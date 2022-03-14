#include <iostream>

using namespace std;

void swap(int *a, int *b);

int main() {
  
  int x, y;
  
  cout << "Please enter two numbers." << endl;
  cin >> x;
  cin >> y;
  cout << "x = " << x << "  "  << "y = " << y << endl;
  
  swap(&x, &y);
  
  cout << "x = " << x << "  "  << "y = " << y << endl;
  
  return 0;
}

void swap(int *a, int *b) {
    
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}
