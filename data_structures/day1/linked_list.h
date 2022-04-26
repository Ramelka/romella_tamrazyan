#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>

using namespace std;

class Node {
    public:
        int _data;
        Node *_next;
        Node();
};

class LinkedList {
    private:
        Node *_head;
        Node *_tail;
        int _count;
    public:
        LinkedList();
        ~LinkedList();
        void Add(int);              // Add a node at the end of list
        void AddAt(int, int);       // Add a node after the given node 
        void RemoveLast();          // Remove the last node of list
        void RemoveAt(int);         // Remove node of the given index
        void RemoveAll();           // Remove all the nodes
        int GetElementAt(int);      // Get element of the given node
        int Count();                // Get count of nodes
        friend ostream& operator << (ostream& COUT, const LinkedList& list);    
};

#endif
