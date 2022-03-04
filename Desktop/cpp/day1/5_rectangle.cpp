#include <iostream>
#include <cstdlib>
using namespace std;

int main () {

    int a, b;
  
    //Answering the sides of rectangle.
    cout << "What are the sides of a rectangle?" << endl;
    cin >> a >> b;
    
    system("clear");
    
    //Counting the perimeter(P) and area(S).
    cout << "a = " << a << "," << "b = " << b << endl;
    int P = 2 * (a + b);
    cout << "P = " << P << endl;
    int S = a * b;
    cout << "S = " << S;
    
    return 0;
}
