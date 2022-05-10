#include <iostream>
#include "linkedList.hpp"
using namespace std;

class Graph {

    private:
        LinkedList *arr;
        int verticeCount;
    public:
        Graph(int);
        void AddEdge(int, int);
        void RemoveEdge(int, int);
        void AddVertice();
        void RemoveVertice();
        bool IsEdgeExisted(int, int);
        void FindAdjacentVertices(int);
        //void FindConnections(int);
        void PrintList();
        ~Graph();
};

Graph::Graph(int verticeCount) {
    
    this->verticeCount = verticeCount;
    arr = new LinkedList [verticeCount];
    for (int i = 0; i < verticeCount; ++i) {
        arr[i]._head = NULL; 
        arr[i]._tail = NULL;  
    }
}

void Graph::AddEdge(int i, int j) {

    arr[i].Add(j);
    arr[j].Add(i);
}

void Graph::RemoveEdge(int i, int j) {

    arr[i].RemoveAt(j);
    arr[j].RemoveAt(i);
}

void Graph::AddVertice() {

    ++verticeCount;
    LinkedList *newArr = new LinkedList[verticeCount];

    for(int i = 0; i < verticeCount - 1; ++i) {
        newArr[i] = arr[i];
    }
    arr = newArr;
}

void Graph::RemoveVertice() {

    --verticeCount;
    LinkedList *newArr = new LinkedList[verticeCount];

    for (int i = 0; i < verticeCount - 1; ++i) {
        newArr[i] = arr[i];
    }
    arr = newArr;
}

bool Graph::IsEdgeExisted(int i, int j) {

    Node *temp = arr[i]._head;
    while (temp) {
        if (temp->_data == j) {
            return true;
        }
        temp = temp->_next;
    }
    return false;
}

void Graph::FindAdjacentVertices(int i) {

    Node *temp = arr[i]._head;
    cout << "Adjacent vertices of " << i << ": ";
    while (temp) {
        cout << temp->_data << " ";
        temp = temp->_next;
    }
    cout << endl;
}

void Graph::PrintList(){

    for(int i = 0; i < verticeCount; i++){
        cout << i << " --> ";
        Node* temp = arr[i]._head;
        while(temp) {
            cout << temp->_data << " ";
            temp = temp->_next;
        }
        cout << endl;
    }
    cout << endl;
}

Graph::~Graph() {

    delete [] arr;
}