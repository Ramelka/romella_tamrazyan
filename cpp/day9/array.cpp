#include <iostream>

using namespace std;

int main() {

  int row, column;
  cout << "Enter size for array." << endl;
  cout << "Rows: "; 
  cin >> row ;
  cout << "Columns: ";
  cin >> column;

  int** arr = new int*[row];
  
  for (int **ptr1 = arr; ptr1 < arr + row; ptr1++) {
    *ptr1 = new int[column];
       
    for (int *ptr2 = *ptr1; ptr2 < *ptr1 + column; ptr2++) {
      *ptr2 = rand() % 10;
      cout << *ptr2 << " ";
    }
      cout << endl;
  }
  return 0;
}
