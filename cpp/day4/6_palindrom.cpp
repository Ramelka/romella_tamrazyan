#include <iostream>
#include <cstring>

using namespace std;

int main() {
  bool b1 = true;
  char word[20];
  cout << "Enter a word to check it." << endl;
  cin >> word[20];
 
  int length = strlen(word);
 
  for (int i = 0; i < length; i++) {
   if (word[i] == word[length - i - 1]) 
    b1 = true;
    break;
 }
 
  if (b1)  cout << "Polindrom word" << endl;
  else     cout << "Not polindrom" << endl;
  
  return 0;
}

