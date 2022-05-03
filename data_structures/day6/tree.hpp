#ifndef TREE_H
#define TREE_H

#include "node.hpp"
#include <queue>

class Tree {
    private:
        Node* _root;
    public:
        Node* GetRoot() const;
        Node* Insert(Node* &, int);
        void PrintBfs(Node*);
        void PrintIncreasingOrder(Node*);
        Tree(int);
        Tree();
        ~Tree();
};

Node* Tree::GetRoot() const {
    return _root;
}

Node* Tree::Insert(Node* &root, int value){

    if (root == NULL) {
        root = new Node(value);
        return root;
    }
    if (value < root->_data) {
        root->_left = Insert(root->_left, value);
    } else { 
        root->_right = Insert(root->_right, value);
    }
    return root;
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

void Tree::PrintIncreasingOrder(Node* root) {

    if (root == NULL) {
        return;
    }
   
    PrintIncreasingOrder(root->_left);
    cout << root->_data << ", ";
    PrintIncreasingOrder(root->_right);
}

Tree::Tree(int data) {

    _root = new Node(data);
}

Tree::Tree() {

    _root = NULL;
}

Tree::~Tree() {

    delete _root;

}

#endif