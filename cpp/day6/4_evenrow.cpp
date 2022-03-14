#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  const int m = 3, n = 3;
  int arr[m][n];  
  bool isEven = true;
 
  cout << "Enter array numbers" << endl;
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  
  system("clear");
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  int x = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] % 2 != 0) 
        isEven = false;
      else { 
        isEven = true;
        x++;
      }
    }

    if (isEven == true && x == n) {
      cout << "row is " << i + 1;
      break;
    }
    x = 0;
  }
  
  if (isEven == false)
    cout << "No row to show";
    
  return 0;
}
