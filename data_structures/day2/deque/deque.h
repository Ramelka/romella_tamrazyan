#ifndef DEQUE_H
#define DEQUE_H

#include "../../day1/linked_list.h"

class Deque {
    private:
        LinkedList _dequeContainer;
    public:
        Deque() = default;
        ~Deque();
        void PushFront(int);
        void PushBack(int);
        int PopFront();
        int PopBack();
        int PeekFront();
        int PeekBack();
		bool isEmpty();
        friend ostream& operator << (ostream& COUT, const Deque&);
};

#endif
