#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

    int number, yournumber;

    while (!(number >= 1 && number <=100)) {
        cout << "Please enter a number" << endl;
        cin >> number;
    }
    system ("clear");
    
    cout << "Try to guess the number" << endl;
    cin >> yournumber;
    
    do {
        while (yournumber > number) {
            cout << "The memorized number is smaller than your number" << endl;
            cin >> yournumber;
        }
        
        while (yournumber < number) {
            cout << "The memorized number is bigger than your number" << endl;
            cin >> yournumber;
        } 
    }
    while (number != yournumber);
        cout << "Good job! You won!";

  
  return 0;
}


