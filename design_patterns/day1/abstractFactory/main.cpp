#include "abstractFactory.hpp"

int main() {
    
    cout << "Testing the client code with the first furniture type:\n";
    Furniture1 *furniture1 = new Furniture1();
    ClientCode(*furniture1);
    delete furniture1;
  
    cout << endl;

    cout << "Testing the same client code with the second furniture type:\n";
    Furniture2 *furniture2 = new Furniture2();
    ClientCode(*furniture2);
    delete furniture2;
    
    cout << endl;
    
    cout << "Testing the same client code with the third furniture type:\n";
    Furniture3 *furniture3 = new Furniture3();
    ClientCode(*furniture3);
    delete furniture3;

    return 0;
}