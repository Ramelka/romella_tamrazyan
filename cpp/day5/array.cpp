#include <iostream>

using namespace std;

int main() {
  int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
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
          if (i < j) {                                 // for big upper triangle
              sum1 = sum1 + arr[i][j];
          } else if (i > j) {                          // for big lower triangle
              sum2 = sum2 + arr[i][j];
          }
          if (i + j <= 1){                             // for big rightside triangle
              sum3 = sum3 + arr[i][j];
          } else if (i + j >= 3) {                     // for big leftside triangle
              sum4 = sum4 + arr[i][j];
          }
          if (i < j && i + j < column - 1) {           // for small upper triangle
              sum5 = sum5 + arr[i][j];
          } else if (i > j && i + j < column - 1) {    // for small leftside triangle
              sum6 = sum6 + arr[i][j];
          } else if (i > j && i + j > column - 1) {    // for small lower triangle
              sum7 = sum7 + arr[i][j];
          } else if (i < j && i + j > column - 1) {    // for small rightside triangle
              sum8 = sum8 + arr[i][j];
          }   
      }   
  }
  cout << endl;
  cout << "sum1: " << sum1 << endl << "sum2: " << sum2 << endl << "sum3: " << sum3 << endl << "sum4: " << sum4 << endl;
  cout << "sum5: " << sum5 << endl << "sum6: " << sum6 << endl << "sum7: " << sum7 << endl << "sum8: " << sum8 << endl;

return 0;
}
