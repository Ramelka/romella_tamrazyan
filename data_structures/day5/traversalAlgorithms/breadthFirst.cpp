#include <iostream>
#include <queue>

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
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* queue = q.front();
        if (queue->data <= min) {
            min = queue->data;
        }
        q.pop();

        if (queue->left) {
            q.push(queue->left);
        } 
        if (queue->right) {
            q.push(queue->right);
        } 
    } 
    return min;

}

int FindMax(Node* node) {

    if (node == NULL) {
        return 0;
    }

    int max = node->data;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* queue = q.front();
        if (queue->data >= max) {
            max = queue->data;
        }
        q.pop();

        if (queue->left) {
            q.push(queue->left);
        } 
        if (queue->right) {
            q.push(queue->right);
        } 
    } 
    return max;
}

int GetSum(Node* node) {

     if (node == NULL) {
        return 0;
    }

    int sum = 0;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        Node* queue = q.front();
        sum += queue->data;
        q.pop();

        if (queue->left) {
            q.push(queue->left);
        } 
        if (queue->right) {
            q.push(queue->right);
        } 
    } 
    return sum;
}

void Insert(Node* node, int value) {

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

        if (queue->left == NULL) {
            queue->left = temp;
            return;
        } 
        if (queue->right == NULL) {
            queue->right = temp;
            return;
        }
        else {
            q.push(queue->right);
            q.push(queue->left);
        }
    }
}

void Print(Node* node) {

    if (node == NULL)
        return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* queue = q.front();
        cout << queue->data << ", ";
        q.pop();

        if (queue->left) {
            q.push(queue->left);
        } 
        if (queue->right) {
            q.push(queue->right);
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