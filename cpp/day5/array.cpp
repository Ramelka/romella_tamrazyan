#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  const int row = 3;
  const int column = 3;
  int arr[row][column];
  
  for(int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      arr[i][j] = (rand() % 10) + 1;
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
  
  for(int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
       if (i + j != row - 1 && i != j)
         sum = sum + arr[i][j];
    }
  }
    cout << "sum: " << 3 * sum << endl;

return 0;
}
