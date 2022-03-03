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
    
    do {
        cout << "Try to guess the number" << endl;
        cin >> yournumber;
    }
    while (number != yournumber);
    cout << "Good job!";
    
    return 0;
}
