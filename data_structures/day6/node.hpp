#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
    public:
        int _data;
        Node* _left;
        Node* _right;
        Node(int);
        Node();
        ~Node();
};

Node::Node(int data) {

    _data = data;
    _left = NULL;
    _right = NULL;
}

Node::Node() {

    _data = 0;
    _left = NULL;
    _right = NULL;
}

Node::~Node() {

    delete _left;
    delete _right;
}

#endif
