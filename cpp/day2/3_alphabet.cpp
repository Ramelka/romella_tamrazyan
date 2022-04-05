#include <iostream>

using namespace std;

int main() {
    
  char letter;
  
  do {
      cout << "Write any letter of alphabet to determine its type.\n";
      cin >> letter;
  } while ((letter < 'A' || letter > 'Z') && (letter < 'a' || letter > 'z'));
  
  switch (letter) {
      case 'a' :
      case 'i' :
      case 'o' :
      case 'e' :
      case 'u' :
      case 'A' :
      case 'I' :
      case 'O' :
      case 'E' :
      case 'U' :
          cout << "It's a vowel sound.\n";
          break;
      default :
          cout << "It's a consonant sound.\n";
          break;
  }
  return 0;
}

