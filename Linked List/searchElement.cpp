#include <iostream>
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

int searchList(Node *head, int value) {
    int index = 1;
    while (head != NULL) {
        if (head -> data == value) {
            return index;
        }
        index++;
        head = head -> next;
    }
    return -1;
}

int main() {
    speedio;
    
    Node *head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);

    for(int i = 0; i < 6; i++)
        cout << "Element " << i << " is at index " << searchList(head, i) << '\n';
}