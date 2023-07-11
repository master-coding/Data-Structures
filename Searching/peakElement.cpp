// Problem: Find the peak element (not smaller than neighbour)

#include <iostream>
using namespace std;

// time: O(n)
int method1(int arr[], int n) {
    if (n == 1) return 0;

    if (arr[0] >= arr[1]) return 0;
    if (arr[n - 1] >= arr[n - 2]) return n - 1;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }

    return -1;
}

// time: O(logn)
// an independent array always have a peak element
int method2(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ( (mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]) ) 
            return mid;
        
        if (mid > 0 && arr[mid] <= arr[mid - 1]) {
            // definitely a peak in left side
            high = mid - 1;
        } else {
            // definitely a peak in right side
            low = mid + 1;
        }

    }

    return -1;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << method1(arr, n);
    cout << method2(arr, n);
}
