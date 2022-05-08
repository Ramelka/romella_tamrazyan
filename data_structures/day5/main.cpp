#include "binaryTree.hpp"

int main() {

    Tree t;
    t.InsertNode(1);
    t.InsertNode(2);
    t.InsertNode(3);
    t.InsertNode(4);
    t.InsertNode(20);
    t.InsertNode(30);
    t.GetMin();
    t.GetMax();
    t.GetSum();
    t.PrintBfs();
    t.PrintDfs();

    return 0;
}