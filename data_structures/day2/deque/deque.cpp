#include "deque.h"

Deque::~Deque() {

    _dequeContainer.~LinkedList();
}

void Deque::PushFront(int value) {

    _dequeContainer.AddAt(0, value);    
}

void Deque::PushBack(int value) {
    
    _dequeContainer.Add(value);
}
        
int Deque::PopFront() {

    int temp = _dequeContainer.GetElementAt(0);
    _dequeContainer.RemoveAt(0);
    return temp;
}

int Deque::PopBack() {

    int temp = _dequeContainer.GetElementAt(_dequeContainer.Count() - 1);
    _dequeContainer.RemoveLast();
    return temp;    
}
        
int Deque::PeekFront() {

    return _dequeContainer.GetElementAt(0);
}

int Deque::PeekBack() {

    return _dequeContainer.GetElementAt(_dequeContainer.Count() - 1);
}

bool Deque::isEmpty() {

    return _dequeContainer.Count() == 0;
}
        
ostream& operator << (ostream &COUT, const Deque& deque) {
    
    return COUT << deque._dequeContainer;
}