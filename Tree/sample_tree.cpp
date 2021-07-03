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

int main() {
    Node *root = new Node(1);  // creating a root node with value 1
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);
}
