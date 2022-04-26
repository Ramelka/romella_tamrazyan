#include "queue.h"
#include <iostream>

void Queue::PushBack(int value) {
        
    _queueContainer.Add(value);
}

int Queue::PopFront() {
    
    int temp = _queueContainer.GetElementAt(0);
    _queueContainer.RemoveAt(0);
    return temp;
}

bool Queue::isEmpty() {
    
    return _queueContainer.Count() == 0;
}

ostream& operator << (ostream &COUT, const Queue& queue) {
    
    return COUT << queue._queueContainer;
}
