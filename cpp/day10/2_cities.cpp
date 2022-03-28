#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void player(char p_end);
void computer(char c_end);

int x = 0;
int main() {

  int button;
  char letter;
  cout << "                                  --Game of Cities-- " << endl;
  cout << "                               Who will start the game? " << endl;
  cout << "                               If player(input 1)" << endl;
  cout << "                               If computer(input 2)" << endl;

  cin >> button;
  string city[30] = {"Amsterdam", "Moscow", "Vienna", "Berlin", "Paris", "Budapest", "Rome", "Madrid", "Kuwait", "Helsinki", "Islamabad", "Washington", "Nicosia", "Odessa", "London", "Hamburg", "Prague", "Oslo", "Tokyo", "Pekin", "Warsaw", "Jerusalem", "Jakarta", "Copenhagen", "Manchester", "Tehran", "Montreal", "Yerevan", "Stepanakert", "Athens"};
  int r = rand() % 30;
  while(1) {
      if (button == 1) {
          player(letter);
          break;
      } else if (button == 2) {
          cout << "Computer turn:\n   City name: " << city[r] << endl;
          x += 1;
          int  i = 0;
          while (city[r][i] != '\0') {
              i++;
          } 
          int a = 'a' - 'A';
          city[r][i - 1] -= a;
          letter = city[r][i - 1];
          player(letter);
          break;
      } else {
          cout << "Try again! \n";
          cin >> button;
  }
}
return 0;
}

void player(char p_end) {
  string p_name;
  cout << "Your turn:\n   City name: ";
  cin >> p_name;
  int m = 1, n = 0;
  string city[30] = {"Amsterdam", "Moscow", "Vienna", "Berlin", "Paris", "Budapest", "Rome", "Madrid", "Kuwait", "Helsinki", "Islamabad", "Washington", "Nicosia", "Odessa", "London", "Hamburg", "Prague", "Oslo", "Tokyo", "Pekin", "Warsaw", "Jerusalem", "Jakarta", "Copenhagen", "Manchester", "Tehran", "Montreal", "Yerevan", "Stepanakert", "Athens"};

  for (int i = 0; i < 30; i++) {
      if (p_name != city[i]) {
          n++;
          if (n == 30) {
              cout << "			You have lost! \n";
              m = 0;
          }
      }
      if (p_name == city[i]) {
          city[i] = "";
          m = 1;
          break;
      }
  }
  
  if (m == 1) {
      char first_letter = p_name[0];
      if (first_letter != p_end && x > 0) {
          cout << "                       You have lost! \n";
      } else {
          char end_letter;
          int i = 0;
      while (p_name[i] != '\0') {
          i++;
      }
      end_letter = p_name[i - 1];
      int a = 'a' - 'A';
      end_letter -= a;
      x += 1;
      computer(end_letter);
      }
  }  
}
void computer(char c_end) {
  string c_name = "null";
        cout << "Computer turn:\n   City name: ";

  string city[30] = {"Amsterdam", "Moscow", "Vienna", "Berlin", "Paris", "Budapest", "Rome", "Madrid", "Kuwait", "Helsinki", "Islamabad", "Washington", "Nicosia", "Odessa", "London", "Hamburg", "Prague", "Oslo", "Tokyo", "Pekin", "Warsaw", "Jerusalem", "Jakarta", "Copenhagen", "Manchester", "Tehran", "Montreal", "Yerevan", "Stepanakert", "Athens"};

  char first_letter;
  char end_letter;
  int b = 0;
  for (int i = 0; i <= 30; i++) {
      if (city[i][0] == c_end ) {
          c_name = city[i];
          cout << "  " << c_name << endl;
          break;
      }
  }
  if (c_name == "null") {
      cout << "			You Won! \n";
      b = 1;
  }
  if (b == 0) {
      int i = 0;
      while (c_name[i] != '\0') {
          i++;
  }
  end_letter = c_name[i - 1];
  int a = 'a' - 'A';
  end_letter -= a;
  player(end_letter);
  }
}

