#include "linked_list.h"
#include <iostream>

Node::Node() {

    _next = NULL;
}

LinkedList::LinkedList() {

    _head = NULL;
    _tail = NULL;
    _count = 0;
}

LinkedList::~LinkedList() {

    RemoveAll();
}

void LinkedList::Add(int value) {

    Node *new_node = new Node;
    new_node->_data = value;
    new_node->_next = NULL;

    if (_head == NULL) {
        _head = new_node;
        _tail = new_node;
    } else {
        _tail->_next = new_node;
        _tail = _tail->_next;
    }
    ++_count;
}

void LinkedList::AddAt(int index, int value) {

    Node *temp = _head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->_next;
    }
    Node *new_node = new Node();
    new_node->_data = value;
    new_node->_next = temp->_next;
    temp->_next = new_node;
    ++_count;
}

void LinkedList::RemoveLast() {

    RemoveAt(Count() - 1);
}

void LinkedList::RemoveAt(int index) {

    if (Count() > 1) {
        Node *prev = _head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev->_next;
        }
        Node *temp;
        temp = prev->_next;
        prev->_next = temp->_next;
        delete temp;
        --_count;
    } else {
        _head = NULL;
        _tail = NULL;
        _count = 0;
    }
}

void LinkedList::RemoveAll() {

    while (_count > 0) {
        RemoveLast();
    }
}

int LinkedList::GetElementAt(int index) {

    int count = 0;
    Node *temp = _head;
    while (temp != NULL) {
        if (count == index) {
            return temp->_data;
        }
        ++count;
        temp = temp->_next;
    }
    return 0;
}

int LinkedList::Count() {

    return _count;
}

ostream& operator << (ostream& COUT, const LinkedList& list) {

    Node *temp = list._head;
    while (temp != NULL) {
        COUT << temp->_data << ", ";
        temp = temp->_next;
    }
    COUT << endl;
    return COUT;
}
