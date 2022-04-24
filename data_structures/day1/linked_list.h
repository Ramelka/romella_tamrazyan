#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {
    public:
        int data;
        Node *next;
        Node();
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        LinkedList();
		Node* GetHead(); 
        void Add(int);              // Add a node at the end of list
        void AddAt(Node *, int);    // Add a node after the given node 
        void Remove();              // Remove the last node of list
        void RemoveAt(Node *);      // Remove node of the given index
        int GetElement(int);        // Get element of the given node
        int CountOfNodes();         // Get count of nodes
        void Print();               // Print the data of nodes
};

#endif
