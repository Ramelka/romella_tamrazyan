#include "queue.h"

void Queue::PushBack(int value) {
        
    _queue.Add(value);
}

int Queue::PopFront() {
    
    int value = _queue.GetElementAt(0);
    _queue.RemoveAt(0);
    return value;
}

bool Queue::isEmpty() {
    
    return _queue.CountOfNodes() == 0;
}

ostream& operator << (ostream &COUT, const Queue& queue) {
    
    return COUT << queue._queue;
}
