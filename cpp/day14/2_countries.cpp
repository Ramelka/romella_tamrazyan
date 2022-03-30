#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

struct Info {
  string country = "";
  string capital = "";
  string domain = "";
  int population;
  int area;
  int gdp;
  int phonecode; 
};

enum PhoneCodes {
  Armenia = 374,
  Russia = 7,
  France = 33,
  Italy = 39,
  USA = 1,
  Singapore = 65, 
};

void facts(Info i);

		
int main(int argc, char* argv[]) {
  
  ifstream f;
  f.open("countries.txt");

  enum PhoneCodes phonecode;
  int arr_phonecode[6] = {Armenia, Russia, France, Italy, USA, Singapore};
  struct Info info[7];
  string data = ""; 
  string s[6]; 
 
  int i = 0, j = 0;
  while (!f.eof()) {
      f >> data;
      s[i] = data;
      i++;
         
      if (i == 6) {
          info[j].country = s[0];
          info[j].capital = s[1];
          info[j].domain = s[2];
	      info[j].population = stoi(s[3]);
	      info[j].area = stoi(s[4]);
	      info[j].gdp = stoi(s[5]);
          info[j].phonecode = arr_phonecode[j];
          i = 0;
          j++;
       } 
  } 
      
  f.close();

  if (strcmp(argv[1], "search") == 0) {
      string mode = "";
      cout << "         Enter the mode you want to search country by: (country/capital/domain)" << endl;
      getline(cin, mode);
      string input = "";
      cout << "         Enter the " << mode << " to search" << endl;
      getline(cin, input);

      if (mode == "country") {
          for (int i = 0; i < 6; i++) {
              if (info[i].country == input) {
                  facts(info[i]);
              }    
          }  
      
      } else if (mode == "capital") {
          for (int i = 0; i < 6; i++) {
              if (info[i].capital == input) {
			      facts(info[i]);
              } 
          }  
      
      } else if (mode == "domain") {
          for (int i = 0; i < 6; i++) {
              if (info[i].domain == input) {
			      facts(info[i]);
              }
	      }  
      }
  
      else
          cout <<  "Error. That " << input << " isn't in my cities list. Try again" << endl;  
  }
   
  if (strcmp(argv[1], "compare") == 0) {
      string c1 = "";
      cout << "Enter the first country: ";
      (getline, c1);
      string c2 = "";
      cout << "Enter the second country: ";
      getline(cin, c2);
      
	  cout << "=========================================";

      for (int i = 0; i < 6; i++) {
	      if (c1 == info[i].country) {
		      
		  }
      }
      
	  for (int i = 0; i < 6; i++) {
	      if (c2 == info[i].country) {

		  }
	  }

  }

  return 0;
}

void facts(Info i) {
  cout << "Country -> " << i.country << endl;
  cout << "Capital -> " << i.capital << endl;
  cout << "Domain -> " << i.domain << endl;
  cout << "Population -> " << i.population << endl;
  cout << "Area -> " <<  i.area << endl;
  cout << "GDP -> " << i.gdp << endl;
  cout << "Phonecode -> " << "+" << i.phonecode << endl;
}

