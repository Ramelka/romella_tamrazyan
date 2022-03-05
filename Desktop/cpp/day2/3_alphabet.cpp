#include <iostream>

using namespace std;

int main() {
    
  char letter;
  cout << "Write any letter of alphabet to determine its type." << "\n";
  cin >> letter;
  
  switch (letter) {
    case 'a' :
    case 'i' :
    case 'o' :
    case 'e' :
    case 'u' :
      cout << "It's a vowel sound.";
      break;
    default :
      cout << "It's a consonant sound";
      break;
  }
  return 0;
}

