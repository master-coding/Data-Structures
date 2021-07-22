#include <bits/stdc++.h>
using namespace std;


int left(int i) {return 2 * i + 1; }
int right(int i) {return 2 * i + 2; }
int parent(int i) {return (i - 2) / 2; }

void heapify(int arr[], int size, int i) {
    int lft = left(i), rgt = right(i);
    int smallest = i;
    if (lft < size && arr[i] > arr[lft])
        smallest = lft;
    if (rgt < size && arr[rgt] < arr[smallest])
        smallest = rgt;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, size, smallest);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int pos = (n - 2) / 2;
    for (int i = pos; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
