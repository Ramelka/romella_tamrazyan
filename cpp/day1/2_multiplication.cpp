#include <iostream>
using namespace std;

int main () {

    int num;
    int m = 0;
    
    cout << "Please enter a number." << endl;
    cin >> num;
    
    while (m < 10) {
        int sum = num * m;
        cout << num << " x " << m << " = " << sum << endl;
        m++;
    }
    
    
    return 0;
}
