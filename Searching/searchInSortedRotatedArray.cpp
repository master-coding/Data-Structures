// Problem: Search in a sorted rotated array
// eg: {10, 20, 30, 40, 1, 2} element = 2 return 5
// eg: {10, 20, 30, 40, 1, 2} element = 50 return -1

#include <iostream>
using namespace std;

// time: O(n), space: O(1)
int method1(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element)
            return i;
    }

    return -1;
}

// time: O(logn)
int method2(int arr[], int n, int element) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element) return mid;

        // right half is sorted
        if (arr[mid] <= arr[high]) {
            if (element > arr[mid] && element <= arr[high]) low = mid + 1;
            else high = mid - 1;
        } else {
            if (element >= arr[low] && element < arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n, x; cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << method1(arr, n, x);
    cout << method2(arr, n, x);
}
