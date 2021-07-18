#include <iostream>
using namespace std;

#define nl '\n'

struct Node {
    int data;
    Node *next;
    Node (int d) {
        data = d;
        next = NULL;
    }
};

struct Stack {
    Node *front;
    int stackSize;
    Stack() {
        stackSize = 0;
        front = NULL;
    }
    bool isEmpty() {return stackSize == 0;}
    int size() {return stackSize;}
    void top();
    void push(int x);
    void pop();
};

void Stack :: top() {
    if (front == NULL) {
        cout << "Stack is empty." << nl;
        return;
    }
    cout << front -> data << nl;
}

void Stack :: push(int x) {
    Node *temp = new Node(x);
    if (front == NULL) {
        front = temp;
        stackSize++;
        return;
    }
    temp -> next = front;
    front = temp;
    stackSize++;
}

void Stack :: pop() {
    if (front == NULL) {
        cout << "Underflow" << nl;
        return;
    }
    Node *temp = front;
    front = front -> next;
    delete(temp);
    stackSize--;
}

int main() {
    Stack s;

    cout << "1 isEmpty " << nl;
    cout << "2 size " << nl;
    cout << "3 Top Element " << nl;
    cout << "4 Insert Element " << nl;
    cout << "5 Delete Element " << nl;
    cout << "  Any other to exit " << nl << nl;
    while (1) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            if (s.isEmpty())
                cout << "Stack is empty" << nl;
            else
                cout << "Stack is not empty" << nl;
        }
        else if (choice == 2) {
            cout << s.size() << nl;
        }
        else if (choice == 3)
            s.top();
        else if (choice == 4) {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (choice == 5)
            s.pop();
        else
            break;
    }
}