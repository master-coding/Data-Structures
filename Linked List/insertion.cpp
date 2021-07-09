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

void displayList(Node *head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node *insertBeginning(Node *head, int value) {
    Node *temp = new Node(value);
    temp -> next = head;
    return temp;
}


int main() {
    speedio;
    
    Node *head = new Node(1);
    head -> next = new Node(2);
    int times;
    cin >> times;
    cout << "Enter the number of nodes you want to add : " << times << "\n";
    for (int i = 0; i < times; i++) {
        int value;
        cin >> value;
        cout << "Value" << i + 1 << " : " << value << '\n';
        head = insertBeginning(head, value);
    }
    cout << "Linked list : ";
    displayList(head);
}