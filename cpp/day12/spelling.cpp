#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  string text; 
  cout << "Please enter a text to check it." << endl;
  getline(cin, text);
  
  string filename = "words.txt";
  ifstream word;
  word.open(filename);
  string line;
  int incorrect = 0; 
  
  ofstream corr;
  corr.open("corrected.txt");

  try {
    if (!word) {
      throw (filename);
    }
    while (word.is_open()) {
      getline(word, line);
        for (int i = 0; text[i] != '\0';i++) {
	  if (text != line) {
	    incorrect = 1;
	    break; 
	  } 	  
         
	}
    }
     word.close();
     corr.close();
    if (incorrect != 1) {
    }
  }
  catch (string s) {
    cout << "File " << s << " isn't opened" << endl;
  }
  return 0;
}
