#include <iostream>

using namespace std;

int main() {
  string words;
  cout << "Enter the words:" << endl;
  getline(cin, words);
  
  int B = 0;
  int count = 0;
  
  for (int i = 0; i < words.size(); i++) {
    if (words[i] == 'B')
      B++;
    if (words[i] == ' ' || i == words.size() - 1) {
      if (B == 2) {
        count ++;
      } 
      B = 0;
    }
  }
  cout << "Count of words with two B is " << count << endl;
  return 0;
}
