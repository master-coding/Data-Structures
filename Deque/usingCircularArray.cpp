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
    void getRear();
    void getFront();
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

void Deque :: getRear() {
    if (isEmpty()) {
        cout << "Deque is empty." << nl;
        return;
    }
    cout << arr[(front + size - 1) % cap] << nl ;
}

void Deque :: getFront() {
    if (isEmpty()) {
        cout << "Deque is empty" << nl;
        return;
    }
    cout << arr[front] << nl;
}

void Deque :: insertFront(int x) {
    if (isFull())
        return;
    front = (front + cap - 1) % cap;
    arr[front] = x;
    size++;
}

void Deque :: insertRear(int x) {
    if (isFull())
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
    int capacity;
    cin >> capacity;
    Deque d(capacity);

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