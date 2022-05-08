#include <iostream>
#include <queue>
#include <stack>
#include "../day6/node.hpp"

using namespace std;

class Tree {
    private:
        Node* _root;
        void Insert(Node *&, int);
        int GetMin(Node *);
        int GetMax(Node *);
        int GetSum(Node *);
        void PrintBfs(Node *);
        void PrintDfs(Node *);
    public:
        Tree();
        ~Tree();
        void InsertNode(int);
        void GetMin();
        void GetMax();
        void GetSum();
        void PrintBfs();
        void PrintDfs();
};

Tree::Tree() {

    _root = NULL;
}

Tree::~Tree() {

    delete _root;
}

void Tree::Insert(Node *&node, int value) {

    if (node == NULL) {
        node = new Node(value); 
        return;
    }

    queue<Node*> q;
    q.push(node);   
    Node* temp = new Node(value);
    
    while(!q.empty()) {
        Node* queue = q.front();
        q.pop();

        if (queue->_left == NULL) {
            queue->_left = temp;
            return;
        } 
        if (queue->_right == NULL) {
            queue->_right = temp;
            return;
        }
        else {
            q.push(queue->_right);
            q.push(queue->_left);
        }
    }
}

void Tree::InsertNode(int value) {

    Insert(_root, value);
}

int Tree::GetMin(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int min = node->_data;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* queue = q.front();
        if (queue->_data <= min) {
            min = queue->_data;
        }
        q.pop();

        if (queue->_left) {
            q.push(queue->_left);
        } 
        if (queue->_right) {
            q.push(queue->_right);
        } 
    } 
    return min;
}

void Tree::GetMin() {

    cout << "Min = " << GetMin(_root) << endl;
}

int Tree::GetMax(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int max = node->_data;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* queue = q.front();
        if (queue->_data >= max) {
            max = queue->_data;
        }
        q.pop();

        if (queue->_left) {
            q.push(queue->_left);
        } 
        if (queue->_right) {
            q.push(queue->_right);
        } 
    } 
    return max;
}

void Tree::GetMax() {

    cout << "Max = " << GetMax(_root) << endl;
}

int Tree::GetSum(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int sum = 0;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* queue = q.front();
        sum += queue->_data;
        q.pop();

        if (queue->_left) {
            q.push(queue->_left);
        } 
        if (queue->_right) {
            q.push(queue->_right);
        } 
    } 
    return sum;
}

void Tree::GetSum() {

    cout << "Sum = " << GetSum(_root) << endl;
}

void Tree::PrintBfs(Node* node) {

    if (node == NULL)
        return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* queue = q.front();
        cout << queue->_data << ", ";
        q.pop();

        if (queue->_left) {
            q.push(queue->_left);
        } 
        if (queue->_right) {
            q.push(queue->_right);
        }
    }
    cout << endl;
}

void Tree::PrintBfs() {

    PrintBfs(_root);
}

void Tree::PrintDfs(Node* node) {
    
    if (node == NULL) {
        return;
    }

    stack<Node*> s;
    s.push(node);   
    
    while(!s.empty()) {
        Node* stack = s.top();
        cout << stack->_data << ", ";
        s.pop();

        if (stack->_right) {
            s.push(stack->_right);
        } 
        if (stack->_left) {
            s.push(stack->_left);
        } 
    }
    cout << endl;
}

void Tree::PrintDfs() {

    PrintDfs(_root);
}