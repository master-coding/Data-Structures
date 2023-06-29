// Problem: Minimum Group Flip to make whole array same
// You are given an array of 0 and 1. You need to make minimum flip so that whole array become same
// eg: {1, 1, 0, 0, 1} => op {from 2 to 3}

#include <iostream>
using namespace std;

void minGroupFlip(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            if (arr[i] != arr[0]) {
                cout << "From " << i << " To ";
            } else {
                cout << i - 1 << '\n';
            }
        }
    }

    if (arr[n - 1] != arr[0]) {
        cout << n - 1;
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    minGroupFlip(arr, n);
}
