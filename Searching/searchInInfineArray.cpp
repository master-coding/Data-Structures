// Problem: Search in an infinte size array

#include <iostream>
using namespace std;

// time: O(pos), space: O(1)
int method1(int arr[], int element) {
    if (arr[0] == element) return 0;

    int i = 1;
    while (arr[i] < element) {
        if (arr[i] == element) return i;
        if (arr[i] > element) return -1;
        
        i++;
    }

    return -1;
}

int binarySearch(int arr[], int element, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element) return mid;
        else if (arr[mid] > element) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

// time: O(logpos)
int method2(int arr[], int element) {
    if (arr[0] == element) return 0;
    
    int i = 1;
    while (arr[i] <= element) {
        i *= 2;
    }

    if (arr[i] == element) return i;

    return binarySearch(arr, element, (i / 2) + 1, i - 1);
}

int main() {
    int n, x; cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << method1(arr, x);
    cout << method2(arr, x);
}
