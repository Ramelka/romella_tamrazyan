#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

string translate1(string text);
string translate2(string text);

int main() {

  setlocale(LC_ALL, "Armenian");
  cout << "					TRANSLATION \n";
  cout << "				   Select a translator mode\n";
  cout << "				   For en-hy mode(enter 1)\n";
  cout << "				   For hy-en mode(enter 2)\n";
  int mode;
  cin >> mode;

  ofstream f3;
  f3.open("result.txt");
  
  string text;
  cout << "Enter your text to translate: ";
  getline(cin, text);
  getline(cin, text); 
  text += " ";

  string split;  
  string sort = "" ;
  
  int i = 0;
  while(text[i] != '\0') {
      split = "";
      for(;text[i] != ' '; i++) {
          split += text[i];
      }  
      i++;
      if (mode == 2) {
          sort += translate2(split);
          sort += " ";
      } else if (mode == 1) {
          sort += translate1(split);
          sort += " ";
      }
  }
  
  f3 << sort;
  f3.close();
  return 0;
}

string translate1(string text) {
  
  ifstream f1;
  f1.open("en-hy.txt");
  
  string words;
  string str= "";
  
  while(!f1.eof()) {
      int count = 0;
      getline(f1, words);
      for (int i = 0; words[i] != '-'; i++) {
          if (text[i] == words[i]) {
              count++;
        } else {
	      break;
	}
      }
      
      if (count == text.length()) {
          count += 3;
      
          for(int m = count; words[m] != '\0'; m++) {
              str += words[m];
          }
      }  
  }
  f1.close();
  return str;
}

string translate2(string text) {
  
  ifstream f2;
  f2.open("hy-en.txt");
  
  string words;
  string str= "";
  
  while(!f2.eof()) {
      int count = 0;
      getline(f2, words);
      for (int i = 0; words[i] != '-'; i++) {
          if (text[i] == words[i]) {
              count++;
          } else {
	      break;
	  }
      }

      if (count == text.length()) {
          count += 3;

      for(int m = count - 1; words[m] != '\0'; m++) {
          str += words[m];
      }
      }
  }
  f2.close();
  return str;
}
