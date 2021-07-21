// implementation of min heap and inserting an item in it

#include <iostream>
using namespace std;

// internally binary heap is represented as an array
struct Heap{
    int *arr;
    int size, capacity;
    Heap (int c) {
        capacity = c;
        size = 0;
        arr = new int [capacity];
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    // insertion in a min heap
    void insert(int x) {
        arr[size] = x;
        size++;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i]; ) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
    }
};

int main() {
    int capacity;
    cin >> capacity;
    Heap h(capacity);
    int x;
    cin >> x;
    h.insert(x);
    h.printHeap();
}