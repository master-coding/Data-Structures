// Cirular linked list implementation

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

void printCircularLL(Node *head) {
    if (head == NULL)
        return;
    Node *curr = head;
    do {
        cout << curr -> value << ' ';
        curr = curr -> next;
    }while(curr != head);
}

int main() {
    Node *head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = head;

    printCircularLL(head);
}