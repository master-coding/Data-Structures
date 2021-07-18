#include <iostream>
using namespace std;

#define nl '\n'

struct Node {
    int data;
    Node *next, *prev;
    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

struct Deque {
    int size;
    Node *rear, *front;
    Deque() {
        front = rear = NULL;
        size = 0;
    }

    bool isEmpty();
    int Dequesize();
    void getFront();
    void getRear();
    void insertFront(int x);
    void insertRear(int x);
    void deleteFront();
    void deleteRear();
};

bool Deque :: isEmpty() {
    return size == 0;
}

int Deque :: Dequesize() {
    return size;
}

void Deque :: getFront() {
    if (front == NULL)
        return;
    cout << front -> data << nl;
}

void Deque :: getRear() {
    if (front == NULL)
        return;
    cout << rear -> data << nl;
}

void Deque :: insertFront(int x) {
    Node *temp = new Node(x);
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        size++;
        return;
    }
    temp -> next = front;
    front -> prev = temp;
    front = front -> prev;
    size++;
}

void Deque :: insertRear(int x) {
    Node *temp = new Node(x);
    if (front == NULL && rear == NULL) {
        rear = front = temp;
        size++;
        return;
    }
    rear -> next = temp;
    temp -> prev = rear;
    rear = rear -> next;
    size++;
}

void Deque :: deleteFront() {
    if (front == NULL) {
        return;
    }
    else {
        Node *temp = front;
        if (front -> next == NULL) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front -> next;
        }
        delete(temp);
    }
    size--;
}

void Deque :: deleteRear() {
    if (front == NULL) {
        return;
    }
    else {
        Node *temp = rear;
        if (front -> next == NULL) {
            front = NULL;
            rear = NULL;
        }
        else {
            rear = rear -> prev;
        }
        delete(temp);
    }
    size--;
}

int main() {
    Deque d;

    cout << "1 isEmpty() " << nl;
    cout << "2 size " << nl;
    cout << "3 Rear Element " << nl;
    cout << "4 Front Element " << nl;
    cout << "5 Insert Element at Front " << nl;
    cout << "6 Insert Element at Rear " << nl;
    cout << "7 Delete Element from Front " << nl;
    cout << "8 Delete Element from Rear " << nl;
    cout << "  Any other to exit " << nl << nl;

    while (1) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            if (d.isEmpty())
                cout << "Deque is Empty. " << nl;
            else
                cout << "Deque is not Empty ";
        }
        else if (choice == 2) {
            cout << d.Dequesize() << nl;
        }
        else if (choice == 3) {
            d.getRear();
        }
        else if (choice == 4) {
            d.getFront();
        }
        else if (choice == 5) {
            int element;
            cin >> element;
            d.insertFront(element);
        }
        else if (choice == 6) {
            int element;
            cin >> element;
            d.insertRear(element);
        }
        else if (choice == 7) {
            if (d.isEmpty())
                cout << "Deque is empty. " << nl;
            else
                d.deleteFront();
        }
        else if (choice == 8) {
            if (d.isEmpty())
                cout << "Deque is empty. " << nl;
            else
                d.deleteRear();
        }
        else
            break;   
    }
}