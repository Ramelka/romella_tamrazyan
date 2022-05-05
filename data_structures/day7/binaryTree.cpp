#include <iostream>
#include "../day6/node.hpp"
#include <queue>
using namespace std;

class Tree
{
private:
    Node *root;
    void insert(Node *&node, int value);
    void PrintDFS(Node *node);
    int findSum(Node *root);
    int findMax(Node *&root);
    int findMin(Node *&root);

public:
    Tree() { root = nullptr; }
    ~Tree() { delete root; }
    void insertNode(int value) { insert(root, value); }
    void printDFS() { PrintDFS(root); }
    void Max() { cout << findMax(root); }
    void Min() { cout << findMin(root); }
    void Sum() { cout << findSum(root); }
};

void Tree::insert(Node *&node, int value)
{
    if (node == NULL)
    {
        node = new Node(value);
        return;
    }
    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->_left != NULL)
            q.push(temp->_left);
        else
        {
            temp->_left = new Node(value);
            return;
        }

        if (temp->_right != NULL)
            q.push(temp->_right);
        else
        {
            temp->_right = new Node(value);
            return;
        }
    }
}

int Tree::findSum(Node *root)
{
    if (root == NULL)
        return 0;

    int result = root->_data;
    int leftSum = findSum(root->_left);
    int rightSum = findSum(root->_right);

    result += leftSum;
    result += rightSum;

    return result;
}

int Tree::findMax(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }

    int result = root->_data;
    int leftMax = findMax(root->_left);
    int rightMax = findMax(root->_right);
    if (leftMax > result)
        result = leftMax;
    if (rightMax > result)
        result = rightMax;

    return result;
}

int Tree::findMin(Node *&root)
{
    if (root == NULL)
    {
        return 0;
    }
    int result = root->_data;
    int leftMin = findMin(root->_left);
    int rightMin = findMin(root->_right);
    if (leftMin < result)
        result = leftMin;
    if (rightMin < result)
        result = rightMin;

    return result;
}

void Tree::PrintDFS(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->_data << ", ";

    PrintDFS(node->_left);
    PrintDFS(node->_right);
}