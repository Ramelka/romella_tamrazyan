#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char lower(char letter);
string to_lower(string word);
string underscore(string);

int main() {
 
   
  cout << "\n\t\t\t\t\t\t\t\tWelcome to R/A American Hotel Registration Agency\n\n\n";
   
  int size = 16;
  string info[size];
   
  cout << "\t\t\t\t\t\t\t In which city is your hotel situated? > "; getline (cin, info[0]); cout << endl;
  info[0] = underscore(info[0]);
  cout << "\t\t\t\t\t\t\t Enter your hotel name > "; getline (cin, info[1]); cout << endl;
  info[1] = underscore(info[1]);
  cout << "\t\t\t\t\t How many single rooms do you have? (if you don't have print '0') > "; getline (cin, info[2]); cout << endl;
  if (info[2] != "0") {
      cout <<  "\t\t\t\t\t\t\t How much does one cost? > ";
      getline (cin, info[3]);
      cout << endl;
   } else {
      info[3] = "0";
  }
  
  cout << "\t\t\t\t\t How many double rooms do you have? (if you don't have print '0') > "; getline (cin, info[4]); cout << endl;
  if (info[4] != "0") {
      cout <<  "\t\t\t\t\t\t\t How much does one cost? > "; 
      getline (cin, info[5]); 
      cout << endl;
  } else {
      info[5] = "0";
  }

  cout << "\t\t\t\t\t How many triple rooms do you have? (if you don't have print '0') > "; getline (cin, info[6]); cout << endl;
  if (info[6] != "0") {
      cout <<  "\t\t\t\t\t\t\t How much does one cost? > "; 
      getline (cin, info[7]); 
      cout << endl;
  } else {
      info[7] = "0";
  }

  cout << "\t\t\t\t\t How many luxe rooms do you have? (if you don't have print '0') > "; getline (cin, info[8]); cout << endl;
  if (info[8] != "0") {
      cout <<  "\t\t\t\t\t\t\t How much does one cost? > ";
      getline (cin, info[9]);
      cout << endl;
  } else {
      info[9] = "0";
  }
restart:
  cout << "\t\t\t\t\t\t Do you have a pool in your hotel? (yes/no): "; getline(cin, info[10]); cout << endl;
  cout << "\t\t\t\t\t\t Do you have spa in your hotel? (yes/no): "; getline (cin, info[11]); cout << endl;
  cout << "\t\t\t\t\t\t Do you have fitness in your hotel? (yes/no): "; getline (cin, info[12]); cout << endl;
  cout << "\t\t\t\t\t\t Do you have a restaurant in your hotel? (yes/no): "; getline (cin, info[13]); cout << endl;
  cout << "\t\t\t\t\t\t Do you have free parking in your hotel? (yes/no): "; getline (cin, info[14]); cout << endl;

  int filter = 0;
  for (int i = 10; i < 15; i++) {
      if (to_lower(info[i]) == "yes") {
          filter++;  
      }      
  }
 
  if (filter == 5) {
      info[15] = "5";
  } else if (filter == 3 || filter == 4) {
      info[15] = "4";
  } else if (filter == 1 || filter == 2) {
      info[15] = "3";
  } else if (filter == 0) {
      cout << "\n\t\t\t\t\tSorry your registration failed.Enter at least one filter!" << endl;
      goto restart;
  }

  ofstream f;
  f.open("hotels.txt", ios::app);
  
  for (int i = 0; i < size; i++) {
      f << to_lower(info[i]) << " ";
  } 
  f << "\n";
  f.close();
  cout << "\n\t\t\t\t\t\t\t\tYour hotel is registered!\n\n\t\t\t\t\t\t\t\tThanks for using our services.\n\n\n\n";
  return 0;
}

char lower(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return letter + ('a' - 'A');
    }
    return letter;
}
string to_lower(string word) {
    string result = "";
    for (int i = 0; word[i] != '\0'; i++) {
        result += lower(word[i]);
    }
    return result;
}
string underscore(string word) {
    string result = "";
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == ' ') {
            word[i] = '_';
        }    
        result += word[i];
    }       
    return result;
}
