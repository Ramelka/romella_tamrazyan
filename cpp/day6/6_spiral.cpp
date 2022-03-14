#include <iostream>

using namespace std;

int main() {

  const int size = 4;
  int n = size;
  int arr[size][size];
  int a = 1, x = 0;  
  
  while (a <= size * size) {
    for (int j = x; j < n; j++) {
      arr[x][j] = a;
      a++;
    }  

    for (int i = x + 1; i < n; i++) {
      arr[i][n - 1] = a;
      a++;
    }  

    for (int j = n - 2; j >= x; j--) {
      arr[n - 1][j] = a;
      a++;
    }

    for (int i = n - 2; i > x; i--) {
      arr[i][x] = a;
      a++;
    }

    x++;
    n -= 1;
 }


  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
