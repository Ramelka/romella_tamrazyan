#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int income(int arr[3], double p);
int main(int argc, char* argv[]) {
  int arr[3];
  for (int i = 0; i < 3; i++) {
      arr[i] = atoi(argv[i + 1]);
    //cout << arr[i] << endl;
  }
  int t = arr[0];
  double perc = (arr[1] / 12.0) / 100;  
  int x = income(arr, perc) - t;


  cout << endl <<  "			Profit of all months = " << x << endl;  
  return 0;
}
int income(int arr[3], double p) {
  double x;
  time_t now = time(0);
  char* date_time = ctime(&now);
  string date[5];

  int y = 0;
  for (int i = 0; date_time[i] != '\0'; i++) {
      if (date_time[i] == ' ') {
          y++;
          continue;
      }
      date[y] += date_time[i];
  }
  string str[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  
  int year = stoi(date[4]);
  int j = 0;
  for (int i = 0; i < 12; i++) {
      if (date[1] == str[i]) {
          j = i;
      }
  }

  cout << "			" << str[j] << " " << date[2] << " " << date[4] << endl;

  for (int i = 0; i < arr[2]; i++) {
      j++;
      if (j == 12) {
          j = 0;
	  year++;
      }
      x = arr[0] * p;
      cout << "Sum of the " << str[j]<< " = " << arr[0] << " " << " Income of the " << str[j] << " = " << x << " -> " << str[j] << " " << date[2] << " " << year;
      arr[0] += x;
      cout << endl;
  }  
  return arr[0];
}
