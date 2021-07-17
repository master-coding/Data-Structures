#include <iostream>
using namespace std;

#define nl '\n'

struct Deque {
    int *arr;
    int front, size, cap;
    Deque(int c) {
        cap = c;
        arr = new int[cap];
        size = front = 0;
    }

    bool isEmpty();
    bool isFull();
    int getRear();
    int getFront();
    void insertFront(int x);
    void insertRear(int x);
    void deleteFront();
    void deleteRear();
};

bool Deque :: isEmpty() {
    return size == 0;
}

bool Deque :: isFull() {
    return size == cap;
}

int Deque :: getRear() {
    if (isEmpty())
        return -1;
    return arr[(front + size - 1) % cap];
}

int Deque :: getFront() {
    if (Deque :: isEmpty())
        return -1;
    return arr[front];
}

void Deque :: insertFront(int x) {
    if (Deque :: isFull())
        return;
    front = (front + cap - 1) % cap;
    arr[front] = x;
    size++;
}

void Deque :: insertRear(int x) {
    if (Deque :: isFull())
        return;
    int rear = (front + size) % cap;
    arr[rear] = x;
    size++;
}

void Deque :: deleteFront() {
    if (isEmpty())
        return;
    front = (front + 1) % cap;
    size--;
}

void Deque :: deleteRear() {
    if (isEmpty())
        return;
    size--;
}


int main() {
    Deque d(5);

    cout << "1 isEmpty() " << nl;
    cout << "2 isFull() " << nl;
    cout << "3 Rear Element " << nl;
    cout << "4 Front Element " << nl;
    cout << "5 Insert Element at Front " << nl;
    cout << "6 Insert Element at Rear " << nl;
    cout << "7 Delete Element from Front " << nl;
    cout << "8 Delete Element from Rear " << nl;
    cout << "  Any other to exit " << nl;

    while (1) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            if (d.isEmpty())
                cout << "Deque is Empty. " << nl;
            else
                cout << "Deque is not Empty " << nl;
        }
        else if (choice == 2) {
            if (d.isFull())
                cout << "Deque is Full. " << nl;
            else
                cout << "Deque is not Full " << nl;
        }
        else if (choice == 3) {
            if (d.getRear() == -1)
                cout << "Deque is Empty. " << nl;
            else
                cout << d.getRear() << nl;
        }
        else if (choice == 4) {
            if (d.getFront() == -1)
                cout << "Deque is Empty. " << nl;
            else
                cout << d.getFront() << nl;
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