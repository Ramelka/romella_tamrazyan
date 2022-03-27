#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string check(string);

int main() {
  string text; 
  cout << "Please enter a text to check it." << endl;
  getline(cin, text);
  text += " ";
  
  ofstream f1;
  f1.open("corrected.txt");
  
  string split;
  int i = 0;
  while (text[i] != '\0') {
      split = "" ;
      for (; text[i] != ' '; i++) {
          split += text[i];
      }
      i++;
    //cout << check(split) << endl;
      f1 << check(split) << endl;
  } 
  f1.close();
  return 0;
}

string check(string correct) {

  ifstream f;
  f.open("words.txt");

  string words;
  int count = 0;
  while (!f.eof()) {
      count = 0;
      getline(f, words);
      for (int i = 0; correct[i] != '\0'; i++) {
	  if (correct.length() == words.length()) {
              if (correct[i] != words[i]) {
	          count++;
	      }

	  }
      }
      if (count == 1)  {
          break;
      }	  
  }
  f.close();
  if (count != 1) {
      return correct;
  }
  return words;
}

