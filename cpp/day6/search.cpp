#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  
  srand(time(0));

  const int size = 4;
  char letter;
  char arr[size][size];

  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      
      arr[i][j] = rand() % ('Z' - 'A' + 1) + 'A' + rand() % 2 * ('z' - 'Z');
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << "Which letter do you want to find?" << endl;
  cin >> letter;

  for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

      if (letter == arr[i][j])	
        cout << "Row: " << i + 1 << " " << "Column: " << j + 1 << endl;
    }
    cout << endl;
  } 

  return 0;
}
