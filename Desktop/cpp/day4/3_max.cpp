#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  int n;
  do {
    cout << "How many numbers do you want to generate?" << endl;
    cin >> n;
  } while (n > 100);
  
  int array[100];
  srand(time(0));
  
  for (int i = 0; i < n; i++) {
    array[i] = rand()%1000 + 1;
    cout << array[i] << ",";
  }
    cout << endl;
    
    int max = array[0];
  
  for (int i = 0; i < n; i++) {
    if (max < array[i])
      max = array[i];
  }
    cout <<  "Max" << "=" << max << endl;
  return 0;
}

