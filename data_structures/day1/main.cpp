#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {

    LinkedList l;

    // Initializing the linked list with 20 random values
    for (int i = 0; i < 20; i++) {
        l.Add(rand() % 10);
    }   
    cout << l;
   
    // Adding value at index three
    l.AddAt(3, 25);
    cout << l;  

    // Deleting the last value of the list
    l.RemoveLast();
    cout << l;

    // Deleting the value of index three
    l.RemoveAt(3);
    cout << l;

    // Getting the value at index one
    int value = l.GetElementAt(1);
    cout << "Second value = " << value << endl;

    // Getting the count of nodes
    int count = l.Count();
    cout << "Count of nodes = " << count << endl;

    // Removing all the values of list
    l.RemoveAll();
    cout << l;
        
    return 0;
}
