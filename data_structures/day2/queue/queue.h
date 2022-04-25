#ifndef QUEUE_H
#define QUEUE_H

#include "../day1/linked_list.h"

class Queue {
    private:
        LinkedList _queue;
    public:
        Queue() = default;
        ~Queue() = default;
        void PushBack(int);
        int PopFront();
        bool isEmpty();
        friend ostream& operator << (ostream& COUT, const Stack&);
};

#endif

