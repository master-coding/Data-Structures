#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);

struct Node {
    int data;
    Node *next;
    Node (int value) {
        data = value;
        next = NULL;
    }
};

void displayList(Node *head) {
    while (head != NULL) {
        cout << head -> data << ' ';
        head = head -> next;
    }
}

int main() {
    speedio;
    
    Node *head = new Node(1);
    head -> next = new Node(5);
    head -> next -> next = new Node(10);
    head -> next -> next -> next = new Node(7);

    displayList(head);
}