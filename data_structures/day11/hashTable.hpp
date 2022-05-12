#include <iostream>
#include <cstring>

using namespace std;

class Node {
    public:
        Node();
        Node(string, int);
        int _value;
        string _key;
        Node *_next;
        ~Node();     
};

Node::Node() {

    _value = 0;
    _key = "";
    _next = NULL;
}

Node::Node(string key, int value) {

    _key = key;
    _value = value;
}

Node::~Node() {

    delete _next;
}

class LinkedList {
    public:
        Node *_head;
};

class HashTable {
    private:
        int size;
        LinkedList *table;
    public:
        HashTable(int);
        int HashFunction(string);
        void Insert(string, int);
        void Delete(string);
        void Search(string);
        void PrintTable();
        ~HashTable();
};

HashTable::HashTable(int n) {
        
    size = n;
    table = new LinkedList[size];
    
    for (int i = 0; i < size; ++i) {
        table[i]._head = NULL;
    }
}

int HashTable::HashFunction(string key) {

    unsigned int index = 23;
    
    for (int i = 0; i < key.size(); i++) {
        index = (index * 'A') ^ (key[i] * 'B');
    }
    return index % size;
}

void HashTable::Insert(string newKey, int data) {

    int index = HashFunction(newKey);
    Node *new_node = new Node(newKey, data);
    
    if(table[index]._head == NULL) {
        table[index]._head = new_node;
    } else {
        new_node->_next = table[index]._head;
        table[index]._head = new_node;
    }
}

void HashTable::Delete(string newKey) {

    int index = HashFunction(newKey);
    Node *temp = table[index]._head;
    
    if(temp->_key == newKey) {
        table[index]._head = table[index]._head->_next;
        delete temp;
    } else {
        while(temp->_next->_key != newKey) {
            temp = temp->_next;
        }
        Node *tmp;
        tmp = temp->_next;
        temp->_next = tmp->_next;
        delete tmp;
    }
}

void HashTable::Search(string newKey) {

    int index = HashFunction(newKey);
    
    if(table[index]._head == NULL) {
        cout << "There is no data at that key" << endl;
    } else {
        Node* new_node= table[index]._head;
        while(new_node) {
            if(new_node->_key == newKey) {
                cout << new_node->_value << endl;
            }
                new_node = new_node->_next;
        }
    }
}

void HashTable::PrintTable() {

    for (int i = 0; i < size; ++i) {
        cout << i << "--> ";
        Node *temp = table[i]._head;
        while(temp != NULL) {
            cout << temp->_key << " ";
            cout << temp->_value << " ";
            temp = temp->_next;
        }
        cout << endl;
    }
    cout << endl;
}

HashTable::~HashTable() {

    delete[] table;
}