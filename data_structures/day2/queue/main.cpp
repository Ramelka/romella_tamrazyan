#include "../../day1/linked_list.h"
#include "queue.h"
#include <iostream>

int main() {

    Queue q;
	
	// Initializing the stack 
	for (int i = 0; i < 20; i++) {
        q.PushBack(rand() % 10);
    }   
    cout << q;
    
	cout << "Removing the first value " << endl;
	q.PopFront();
	cout << q;

    return 0;
}
