#include "stack.h"

void Stack::Push(int value) {
        
    _stack.Add(value);
}

int Stack::Pop() {
    
    int top = Peek();
    _stack.RemoveLast();
    return top;
}

int Stack::Peek() {
    
    return _stack.GetElementAt(_stack.CountOfNodes() - 1); 
}

bool Stack::isEmpty() {
    
    return _stack.CountOfNodes() == 0;
}

ostream& operator << (ostream &COUT, const Stack& stack) {
    
    return COUT << stack._stack;
}
