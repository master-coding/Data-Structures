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

void middle(Node *head) {
    if (head == NULL)
        return;
    Node *first = head, *second = head;
    while (second != NULL && second -> next != NULL) {
        first = first -> next;
        second = second -> next -> next;
    }
    cout << first -> value;
}
int main() {
    Node *head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);

    middle(head);
}