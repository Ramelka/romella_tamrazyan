#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
struct diary {
    string date = "";
    string note = "";
    string command = "";
    string button = "";
}d;
 
struct date {
    int d;
    int m;
    int y;
}num;
 
int dayofweek(int d, int m, int y) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}
 
int main() {
 
  do {
      cout << "Please enter date in this format dd_mm_yyyy" << endl;
      getline(cin, d.date);
 
      ofstream file_date;
      string s1 = "./notes/" + d.date + ".txt";
      file_date.open(s1.c_str(), ios::app);
 
      string s;
      string split[3];
      
      int i = 0, j = 0;
      while (i <= d.date.length()) {
          if (d.date[i] != '_')
              s += d.date[i];
          if (d.date[i] == '_' || d.date[i] == '\0') {
              split[j] = s;
              s = "";
              j++;
          }  
              i++;
      }
      string weekday = "";
      num.d = stoi(split[0]);
      num.m = stoi(split[1]);
      num.y = stoi(split[2]);
 
      int w =  dayofweek(num.d, num.m, num.y);
      switch (w) {
          case 0:
              weekday = "Sun";
              break;
          case 1:
              weekday = "Mon";
              break;
          case 2:
              weekday = "Tue";
              break;
          case 3:
              weekday = "Wed";
              break;
          case 4:
              weekday = "Thu";
              break;
          case 5:
              weekday = "Fri";
              break;
          case 6:
              weekday = "Sat";
              break;
       }
 
       file_date << '\t' << d.date << " " << weekday;
 
       do {
            cout << "Enter your notes for that day" << endl;
            getline(cin, d.note);
            file_date << endl << "   " << d.note;
            cout << "If you want to add another note for that date enter <add> else <stop>" << endl;
            getline(cin, d.button);
       } while (d.button != "stop");
 
       cout << "Select command: add / exit" << endl;
       getline(cin, d.command);
 
       if (d.command == "exit") {
            break;
       }
  }
 
  while (d.command == "add");
 
  return 0;
}
