#include "node.h"

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