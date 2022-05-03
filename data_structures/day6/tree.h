#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>

using namespace std;

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

#endif