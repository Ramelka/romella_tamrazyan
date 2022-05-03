#include "tree.h"

using namespace std;

int main() {

    Tree* t = new Tree();
    Node* temp = t->GetRoot();
    t->Insert(temp, 10);
    t->Insert(temp, 4);
    t->Insert(temp, 12);
    t->Insert(temp, 13);
    t->Insert(temp, 6);
    t->Insert(temp, 2);
    t->PrintBfs(temp);
    t->PrintIncreasingOrder(temp);
    cout << endl;

    return 0;
}