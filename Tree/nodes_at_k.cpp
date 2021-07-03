// print nodes at distance k

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

int height(Node *root) {
    if (root == NULL)
        return 0;
    else {
        return max(height(root -> left), height(root -> right)) + 1;
    }
}

void nodesAtK(Node *root, int k) {
    if (root == NULL)
        return;
    if (k >= height(root))
        cout << "No nodes at this distance" << nl;
    else {
        if (k == 0)
            cout << root -> key << sp;
        else {
            nodesAtK(root -> left, k - 1);
            nodesAtK(root -> right, k - 1);
        }
    }
}

int main() {
    Node *root = new Node(1);  // creating a root node with value 1
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);

    int k;
    cin >> k;
    cout << "nodes at distance " << k << " from root node are: "; nodesAtK(root, k);
}
