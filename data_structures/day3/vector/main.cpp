#include "vector.h"
#include <iostream>

int main() {
    
    Vector v;
    for (int i = 0; i < 5; ++i) {
        v.Add(rand() % 10);
    }
  
    cout << v;

    // Adding value at the beginning
    v.AddFront(20);
    cout << v;

    // Adding value at the given index
    v.AddAt(2, 10);
    cout << v;

    // Remove the value at the given index
    v.RemoveAt(6);
    cout << v;

    // Remove all the values
    v.RemoveAll();
    cout << v;
    
}