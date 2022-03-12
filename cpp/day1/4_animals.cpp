#include <iostream>
#include <cstdlib>
using namespace std;

int main () {

    int chickens, cows, pigs, legs;
    
    //Getting the numbers of each animal.
    cout << "How many chickens do you have?" << endl;
    cin >> chickens;
    cout << "How many cows do you have?" << endl;
    cin >> cows;
    cout << "How many pigs do you have?" << endl;
    cin >> pigs;
    
    system("clear");
    
    //Declare the data.
    cout << "chickens = " << chickens << endl;
    cout << "cows = " << cows << endl;
    cout << "pigs = " << pigs << endl;
    
    //Counting the total legs of animals.
    legs = chickens * 2 + 4 * (cows + pigs);
    cout << "legs = " << legs;
    return 0;
}   
