#include <iostream>
using namespace std;

#define nl '\n'

struct Queue {
    int size, cap, front;
    int *arr;
    Queue(int c) {
        cap = c;
        arr = new int[cap];
        size = front = 0;
    }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap; }
    void getFront();
    void getRear();
    void enqueue(int x);
    void dequeue();

};

void Queue :: getFront() {
    if (isEmpty()) {
        cout << "Queue is Empty." << nl;
        return;
    }
    cout << arr[front] << nl;
}

void Queue :: getRear() {
    if (isEmpty()) {
        cout << "Queue is Empty." << nl;
        return;
    }
    cout << arr[(front + size - 1) % cap] << nl;
}

void Queue :: enqueue(int x) {
    if (isFull()) {
        cout << "Can't add element. Queue is full." << nl;
        return;
    }

    int rear = (front + size) % cap;
    arr[rear] = x;
    size++;
}

void Queue :: dequeue() {
    if (isEmpty()) {
        cout << "Can't deque. Queue is empty" << nl;
        return;
    }
    front = (front + 1) % cap;
    size--;
}

int main() {
    int capacity;
    cin >> capacity;
    Queue q(capacity);

    cout << "1 isEmpty " << nl;
    cout << "2 isFull " << nl;
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
                cout << "Queue is empty." << nl;
            else
                cout << "Queue is not empty" << nl;
        }
        else if (choice == 2) {
            if (q.isFull())
                cout << "Queue is full." << nl;
            else
                cout << "Queue is not full" << nl;
        }
        else if (choice == 3)
            q.getFront();
        else if (choice == 4)
            q.getRear();
        else if (choice == 5) {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (choice == 6)
            q.dequeue();
        else
            break;
    }

}