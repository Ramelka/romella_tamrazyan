#include <iostream>
#include <stack>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        
        Node(int _data) {
            data = _data;
            left = NULL;
            right = NULL;
        }
};

int FindMin(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int min = node->data;
    stack<Node*> s;
    s.push(node);

    while(!s.empty()) {
        Node* stack = s.top();
        if (stack->data <= min) {
            min = stack->data;
        }
        s.pop();

        if (stack->right) {
            s.push(stack->right);
        } 
        if (stack->left) {
            s.push(stack->left);
        } 
    } 
    return min;

}

int FindMax(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int max = node->data;
    stack<Node*> s;
    s.push(node);

    while(!s.empty()) {
        Node* stack = s.top();
        if (stack->data >= max) {
            max = stack->data;
        }
        s.pop();

        if (stack->right) {
            s.push(stack->right);
        } 
        if (stack->left) {
            s.push(stack->left);
        } 
    } 
    return max;
}

int GetSum(Node* node) {

     if (node == NULL) {
        return 0;
    }

    int sum = 0;
    stack<Node*> s;
    s.push(node);

    while(!s.empty()) {
        Node* stack = s.top();
        sum += stack->data;
        s.pop();

        if (stack->right) {
            s.push(stack->right);
        } 
        if (stack->left) {
            s.push(stack->left);
        } 
    } 
    return sum;
}

void Insert(Node* node, int value) {

     if (node == NULL) {
        node = new Node(value); 
        return;
     }

    stack<Node*> s;
    s.push(node);   
    Node* temp = new Node(value);
    
    while(!s.empty()) {
        Node* stack = s.top();
        s.pop();

        if (stack->right == NULL) {
            stack->right = temp;
            return;
        } 
        if (stack->left == NULL) {
            stack->left = temp;
            return;
        }
        else {
            s.push(stack->right);
            s.push(stack->left);
        }
    }
}

void Print(Node* node) {
    
    if (node == NULL) {
        return;
    }

    stack<Node*> s;
    s.push(node);   
    
    while(!s.empty()) {
        Node* stack = s.top();
        cout << stack->data << ", ";
        s.pop();

        if (stack->right) {
            s.push(stack->right);
        } 
        if (stack->left) {
            s.push(stack->left);
        } 
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Insert(root, 30);
    Print(root);
    cout << endl;
    cout << "Min = " << FindMin(root) << endl;
    cout << "Max = " << FindMax(root) << endl;
    cout << "Sum = " << GetSum(root) << endl;

    return 0;
}