// delete last node in LINKED LIST

#include <iostream>
using namespace std;


struct Node {
    int value;
    Node *next;
    Node (int data) {
        value = data;
        next = NULL;
    }
};

void printList(Node *head) {
    while (head != NULL) {
        cout << head -> value << " ";
        head = head -> next;
    }
}

Node *delLastNode(Node *head) {
    if (head == NULL)
        return NULL;
    if (head -> next == NULL) {
        delete(head);
        return NULL;
    }

    Node *current = head;
    while (current -> next -> next != NULL) {
        current = current -> next;
    }
    delete(current -> next);
    current -> next = NULL;

    return head;
}

int main() {
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);

    head = delLastNode(head);
    printList(head);
}