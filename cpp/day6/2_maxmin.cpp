#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  const int m = 3, n = 4;
  int arr[m][n];
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = rand() % 10;
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
   int x;
   int max = arr[0][0], min = arr[0][0];
   int i_maxind = 0, i_minind = 0;
   int j_maxind = 0, j_minind = 0;
   
   for (int i = 0; i < m; i++) {
     for (int j = 0; j < n; j++) {
        if (arr[i][j] > max) {
          max = arr[i][j];
          i_maxind = i;
          j_maxind = j;
        }
      
        if (arr[i][j] < min) {
          min = arr[i][j];
          i_minind = i;
          j_minind = j;
        } 
        
      } 
   }
  cout << endl;
    x = arr[i_maxind][j_maxind];
    arr[i_maxind][j_maxind] = arr[i_minind][j_minind];
    arr[i_minind][j_minind] = x; 
       
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }    
  return 0;
}
