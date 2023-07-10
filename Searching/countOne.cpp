// Problem: Count no of ones in a sorted binary array

#include <iostream>
using namespace std;

// time: O(logn), space: O(1)
int firstOccurenceOfOne(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == 0) low = mid + 1;
        else {
            if (mid == 0 || arr[mid - 1] == 0) return mid;
            else high = mid - 1;
        }
    }

    return -1;
}

int countOnes(int arr[], int n) {
    int first = firstOccurenceOfOne(arr, n);
    if (first == -1) return 0;

    return n - first;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << countOnes(arr, n);
}
