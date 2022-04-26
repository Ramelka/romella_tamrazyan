#include "../../day1/linked_list.h"
#include "deque.h"
#include <iostream>

int main() {

    Deque d;

    // Initializing the deque 
	for (int i = 0; i < 20; i++) {
        d.PushBack(rand() % 10);
    }   
    cout << d;

    // Adding value at the beginning
    d.PushFront(12);
    cout << d;

    // Adding value in the end
    d.PushBack(20);
    cout << d;

    // Deleting the first and last values
    d.PopFront();
    d.PopBack();
    cout << d;

    // Getting the first and  the last values 
    cout << "The deleted value from the beginning is " << d.PeekFront() << endl;
    cout << "The deleted value from the end is " << d.PeekBack() << endl;
    
    return 0;
}