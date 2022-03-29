#include <iostream>
#include <string>
#include <fstream>

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
      for (; i < 6; i++) {
      getline(f, data);
      s[i] = data;
         
      if (i == 5) {
          info[j].country = s[0];
          info[j].capital = s[1];
          info[j].domain = s[2];
		 /* info[j].population = stoi(s[3]);
		  info[j].area = stoi(s[4]);
		  info[j].gdp = stoi(s[5]);
          info[j].phonecode = arr_phonecode[j];*/
          i = 0;
          j++;
       }
    }
  } 
      
  f.close();


    


return 0;

}
