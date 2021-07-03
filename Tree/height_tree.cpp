#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tlp int tc; cin >> tc; while (tc--)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sp ' '
#define nl '\n'
#define newline cout << '\n'
#define ll long long int


struct Node {
    int key;
    Node *left, *right;
    Node(int value) {
        key = value;
        left = right = NULL;
    }
};

// height is the number of the nodes on the longest path
// or the no of edges on the longest path
// for edges subtract -1 from this ans
int height(Node *root) {
    if (root == NULL)
        return 0;
    else {
        return max(height(root -> left), height(root -> right)) + 1;
    }
}


int main() {
    Node *root = new Node(1);  // creating a root node with value 1
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);

    cout << "Height of the tree is " << height(root);
}
