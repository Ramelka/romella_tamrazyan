#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {

    LinkedList l;
    Node *head = NULL;

    // Initializing the linked list with 20 random values
    for (int i = 0; i < 20; i++) {
        l.Add(rand() % 10);
    }   
    l.Print();
   
    // Adding value after the third node 
    l.AddAt(l.GetHead()->next->next, 25);
    l.Print();  

    // Delete the last node of the list
    l.Remove();
    l.Print();

    // Deleting the fourth value of linked list
    l.RemoveAt(l.GetHead()->next->next);
    l.Print();

    // Getting the second value of linked list
    int elem = l.GetElement(1);
    cout << "Second Element = " << elem << endl;

    // Getting the count of nodes
    int count = l.CountOfNodes();
    cout << "Count of nodes = " << count << endl;

    return 0;
}

