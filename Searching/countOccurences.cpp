// Problem: Count occurences in a sorted array

#include <iostream>
using namespace std;

// time: O(logn), space: O(1)
int firstOccurence(int arr[], int n, int element) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > element) high = mid - 1;
        else if (arr[mid] < element) low = mid + 1;
        else {
            if (mid == 0 || arr[mid - 1] != arr[mid]) return mid;
            else high = mid - 1;
        }
    }

    return -1;
}

// time: O(logn), space: O(1)
int lastOccurence(int arr[], int n, int element) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > element) high = mid - 1;
        else if (arr[mid] < element) low = mid + 1;
        else {
            if (mid == n - 1 || arr[mid + 1] != arr[mid]) return mid;
            else low = mid + 1;
        } 
    }

    return -1;    
}

// time: O(n)
int countOccurencesMt1(int arr[], int n, int element) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element)
            count++;
    }

    return count;
}

// time: O(logn)
int countOccurencesMt2(int arr[], int n, int element) {
    int first = firstOccurence(arr, n, element);
    if (first == -1) return 0;

    int last = lastOccurence(arr, n, element);

    return last - first + 1;
}

int main() {
    int n, element; cin >> n >> element;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << countOccurencesMt1(arr, n, element);
    cout << countOccurencesMt2(arr, n, element);
}
