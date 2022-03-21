#include <iostream>
#include <cstring>

using namespace std;

void swap(char* a, char* b);
void permute(char*, int, int);

int main() {
  
  char word[30];
  cout << "Please enter a word" << endl; 
  cin >> word;
  
  int size = strlen(word); 
  permute(word, 0, size);
      
  return 0;
}

void swap(char* a, char* b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void permute(char* a, int left, int right) {
  if (left == right) {
    cout << a << endl;
    } else {
        for (int i = left; i < right; i++) {
          swap((a + left),(a + i));
          permute(a, left + 1, right);
          swap((a + left),(a + i));
        }
      }  
}
