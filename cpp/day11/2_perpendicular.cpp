#include <iostream>
#include <cstdlib>

using namespace std;

void PrintArray(double *arr1, double *arr2);

int main() {  
  
  double x[4], y[4];
  cout << "Please enter coordinates for A, B, C, D points" << endl;  
  for (int i = 0; i < 4; i++) {
    cin >> x[i] >> y[i];
  }  
 
  system("clear");
  
  PrintArray(x, y);  
  
  if ((x[1] - x[0]) * (x[3] - x[2]) + (y[1] - y[0]) * (y[3] - y[2]) == 0) {
      cout << "AB and CD are perpendicular" << endl;
  } else {
      cout << "AB and CD aren't perpendicular" << endl;
  } 
  return 0;
}

void PrintArray(double *arr1, double *arr2) {
  char point = 'A';
  for (int i = 0; i < 4; i++) {
    cout << point << ": " <<  arr1[i] << " " << arr2[i] << endl;
    point++;
  }
}
