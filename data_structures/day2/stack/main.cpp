#include "../../day1/linked_list.h"
#include "stack.h"
#include <iostream>

int main() {

    Stack s;
	
	// Initializing the stack 
	for (int i = 0; i < 20; i++) {
        s.Push(rand() % 10);
    }   
    cout << s;
    
	cout << "Removing the last value" << endl;
	s.Pop();
	cout << s;

	// Showing the last value
	int value = s.Peek();
	cout << "The last value is " << value << endl;

    return 0;
}

