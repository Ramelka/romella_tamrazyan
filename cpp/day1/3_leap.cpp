#include <iostream>
using namespace std;

int main () {

    int year = 2020;
    int n = 0;
    
    while (n < 20) {
        year = year + 4;
        cout << year << ",";
        n++;
    }
   
    return 0;
}
