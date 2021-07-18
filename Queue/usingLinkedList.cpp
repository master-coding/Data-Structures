#include <iostream>
using namespace std;

#define nl '\n'

struct Node {
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

struct Queue {
    Node *head, *tail;
    int size;
    Queue() {
        head = tail = NULL;
        size = 0;
    }
    bool isEmpty();
    void qsize();
    void getFront();
    void getRear();
    void enque(int x);
    void deque();
};

bool Queue :: isEmpty() {
    return size == 0;
}

void Queue :: qsize() {
    cout << "Size of Queue is " << size << nl;
}

void Queue :: getFront() {
    if (head == NULL) {
        cout << "Queue is empty." << nl;
        return;
    }
    cout << head -> data << nl;
}

void Queue :: getRear() {
    if (head == NULL) {
        cout << "Queue is empty." << nl;
        return;
    }
    cout << tail -> data << nl;
}

void Queue :: enque(int x) {
    Node *temp = new Node(x);
    if (head == NULL) {
        head = tail = temp;
        size++;
        return;
    }
    tail -> next = temp;
    tail = tail -> next;
    size++;
}

void Queue :: deque() {
    if (head == NULL) {
        cout << "Queue is empty." << nl;
        return;
    }
    Node *temp = head;
    head = head -> next;
    if (head == NULL) {
        tail = NULL; // tail is changed in only one condition when queue is having 1 element
    }
    delete(temp);
    size--;
}

int main() {
    Queue q;

    cout << "1 isEmpty() " << nl;
    cout << "2 size " << nl;
    cout << "3 Front Element " << nl;
    cout << "4 Rear Element " << nl;
    cout << "5 Enqueue " << nl;
    cout << "6 Deque " << nl;
    cout << "  Any other to exit " << nl << nl;

    while(1) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            if (q.isEmpty())
                cout << "Queue is empty" << nl;
            else
                cout << "Queue is not empty" << nl;
        }
        else if (choice == 2)
            q.qsize();
        else if (choice == 3)
            q.getFront();
        else if (choice == 4)
            q.getRear();
        else if (choice == 5) {
            int x;
            cin >> x;
            q.enque(x);
        }
        else if (choice == 6)
            q.deque();
        else
            break;
    }
}