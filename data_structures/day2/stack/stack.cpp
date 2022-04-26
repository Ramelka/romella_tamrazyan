#include "stack.h"

void Stack::Push(int value) {
        
    _stackContainer.Add(value);
}

int Stack::Pop() {
    
    int top = Peek();
    _stackContainer.RemoveLast();
    return top;
}

int Stack::Peek() {
    
    return _stackContainer.GetElementAt(_stackContainer.Count() - 1); 
}

bool Stack::isEmpty() {
    
    return _stackContainer.Count() == 0;
}

ostream& operator << (ostream &COUT, const Stack& stack) {
    
    return COUT << stack._stackContainer;
}
