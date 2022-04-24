#include <iostream>
#include <cassert>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    
        Node() 
        {
            next = NULL;
        }
};

class LinkedList {
    private: 
        Node *head;
        Node *tail;  
    public:
        LinkedList() 
        {
            head = NULL;
            tail = NULL;    
        }
    
        void Add(int);              // Add a node at the end of list
        void AddAt(Node *, int);    // Add a node after the given node 
        void Remove();              // Remove the last node of list
        //void RemoveAt();          // Remove node of the given index
        int GetElement(int);        // Get element of the given node
        int CountOfNodes();         // Get count of nodes
        void Print();               // Print the data of nodes

};

void LinkedList::Add(int num) {

    Node *new_node = new Node;
    new_node->data = num;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = tail->next;
    }   
}

void LinkedList::AddAt(Node *prev_node, int value) {

    if (prev_node == NULL) {
        cout << " The previous node mustn't be NULL" << endl; 
        //return;   
    }   
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void LinkedList::Remove() {
    Node *temp1 = head;
    if (temp1 == NULL) {
        cout << "List is empty" << endl;
    } else if (temp1->next == NULL) {
        delete(temp1);
        temp1 = NULL;
    } else {
        Node *temp2 = head;
        while (temp2->next->next != NULL) {
            temp2 = temp2->next;
        }
        delete(temp2->next);
        temp2->next = NULL;
    }   
}

/*void LinkedList::RemoveAt() {


}*/

int LinkedList::GetElement(int index) {

    int count = 0;
    Node *temp = head;

    while (temp != NULL) {
        if (count == index) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    assert(0);
}

int LinkedList::CountOfNodes() {

    Node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;

}

void LinkedList::Print() {

   if (head == NULL) {
        cout << "Linked list is empty" << endl;
    } else {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {

    Node *head = NULL;
    LinkedList l;

    for (int i = 0; i < 6; i++) {
        l.Add(rand() % 10);
    }
    l.Print();
    l.AddAt(head, 5);
    l.Print();
    int a = l.CountOfNodes();
    cout << a << endl;
    int b = l.GetElement(2);
    cout << "Element = " << b << endl;

    l.Remove();
    l.Print();

    return 0;

}

