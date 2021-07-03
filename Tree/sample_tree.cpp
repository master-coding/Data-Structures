// sample tree implementation

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tlp int tc; cin >> tc; while (tc--)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sp ' '
#define nl '\n'
#define newline cout << '\n'
#define ll long long int

#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define yes cout << "YES" << nl
#define no cout << "NO" << nl

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

// preorder follows ROOT LEFT RIGHT
void preorder(Node *root) {
    if (root != NULL) {
        cout << root -> key << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

// postorder follows LEFT RIGHT ROOT  
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> key << " ";        
    }
}

int main() {
    Node *root = new Node(1);  // creating a root node with value 1
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    cout << "Inorder traversal "; inorder(root); newline;
    cout << "Preorder traversal "; preorder(root); newline;
    cout << "Postorder traversal "; postorder(root); newline;
}
