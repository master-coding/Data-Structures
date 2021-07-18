// implementation of stack using array

#include <iostream>
using namespace std;

#define nl '\n'


struct Stack {
    int *arr;
    int top, cap;
    Stack (int c) {
        cap = c;
        top = -1;
        arr = new int[cap];
    }
    bool isEmpty() {return top == -1;}
    int size() {return top + 1;}
    void peek();
    void push(int x);
    void pop();
};

void Stack :: peek() {
    if (top == -1) {
        cout << "Stack is empty." << nl;
        return;
    }
    cout << arr[top] << nl;
}

void Stack :: push(int x) {
    if (top + 1 == cap) {
        cout << "overflow" << nl;
        return;
    }
    top++;
    arr[top] = x;
}

void Stack :: pop() {
    if (top == -1) {
        cout << "Underflow" << nl;
        return;
    }
    top--;
}

int main() {
    int capacity;
    cin >> capacity;
    Stack s(capacity);

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
            s.peek();
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