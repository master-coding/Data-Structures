// sample tree implementation

#include <iostream>
using namespace std;


struct Node {
    int key;
    Node *left, *right;
    Node(int value) {
        key = value;
        left = right = NULL;
    }
};

// inorder follows LEFT ROOT RIGHT
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root -> left);
        cout << root -> key << " ";
        inorder(root -> right);
    }
}

int main() {
    Node *root = new Node(1);  // creating a root node with value 1
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    inorder(root);
}
