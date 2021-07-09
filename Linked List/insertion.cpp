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

Node *insertEnd(Node *head, int value) {
    Node *temp = new Node(value);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr -> next != NULL)
        curr = curr -> next;
    
    curr -> next = temp;
    return head;
}

int main() {
    speedio;
    
    Node *head = NULL;
    cout << 1. << " Insert at the beginning \n";
    cout << 2. << " Insert at the end \n";
    cout << 3. << " Display the linked list \n";
    cout << "  Any other key to exit \n";

    while (true) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            int value;
            cin >> value;
            head = insertBeginning(head, value);
        }
        else if (choice == 2) {
            int value;
            cin >> value;
            head = insertEnd(head, value);
        }
        else if (choice == 3) {
            cout << "Linked list : " ;
            displayList(head);
            cout << "\n";
        }
        else {
            cout << "Linked list : " ;
            displayList(head);
            cout << "\n";
            break;
        }
    }
}