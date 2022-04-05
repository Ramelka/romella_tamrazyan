#include <iostream>
#include <string.h>

using namespace std;

int main() {
  bool isPalindrome = true;
  char word[256];

  cout << "Enter a word to check it." << endl;
  cin >> word;
  
  int length = strlen(word);
 
  for (int i = 0; i < length / 2; i++) { 
      if (word[i] >= 'A' && word[i] <= 'Z') {
          word[i] += 'a' - 'A';
      }
      if (word[length - i - 1] >= 'A' && word[length - i - 1] <= 'Z') {
          word[length - i - 1] += 'a' - 'A';
      }
      if (word[i] != word[length - i - 1]) {
          isPalindrome = false;
          break;
      }
  }
  
  if (isPalindrome)  
      cout << "Palindrome word" << endl;
  else    
      cout << "Not palindrome word" << endl;
  
  return 0;
}
