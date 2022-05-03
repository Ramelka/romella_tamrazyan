#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    public:
        int _data;
        Node* _left;
        Node* _right;
        Node(int);
        Node();
        ~Node();
};

#endif