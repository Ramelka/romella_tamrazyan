#ifndef STACK_H
#define STACK_H

#include "../../day1/linked_list.h"

class Stack {
    private:
        LinkedList _stackContainer;
    public:
        Stack() = default;
        ~Stack() = default;
        void Push(int);
        int Pop();
        int Peek();
		bool isEmpty();
        friend ostream& operator << (ostream& COUT, const Stack&);
};

#endif
