#include <iostream>

using namespace std;

int main() {
    
  char letter;
  
  do {
    cout << "Write any letter of alphabet to determine its type." << "\n";
  } while (letter < 'A' || letter > 'z');
  
  cin >> letter;
  
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
      cout << "It's a vowel sound.";
      break;
    default :
      cout << "It's a consonant sound";
      break;
  }
  return 0;
}

