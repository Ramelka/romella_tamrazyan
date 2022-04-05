#include <iostream>

using namespace std;

int main() {
    
  int weeknum;
    
  cout << "Please write a number of the week and I'll say the name of that day." << endl;
  cin >> weeknum;
    
  switch (weeknum) {
      case 1 :
          cout << "The first day of week is Monday.\n";
          break;
      case 2 :
          cout << "The second day of week is Tuesday.\n";
          break;
      case 3 :
          cout << "The third day of week is Wednesday.\n";
          break;
      case 4 :
          cout << "The fourth day of week is Thursday.\n";
          break;
      case 5 :
          cout << "The fifth day of week is Friday.\n";
          break;
      case 6 :
          cout << "The sixth day of week is Saturday.\n";
          break;
      case 7 :
          cout << "The seventh day of week is Sunday.\n";
          break;
      default :
          cout << "A week has only 7 days.\n";
          break;
  }
  return 0;	    
}
