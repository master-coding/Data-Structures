// Index of last occurence in sorted array

#include <iostream>
using namespace std;

// time: O(logn)
int lastOccurrenceIterative(int arr[], int n, int element) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < element) low = mid + 1;
        else if (arr[mid] > element) high = mid - 1;
        else {
            if (mid == n - 1 || arr[mid + 1] != arr[mid]) return mid;
            else low = mid + 1;
        }
    }

    return -1;
}

// time: O(logn), space: O(logn)
int helper(int arr[], int n, int low, int high, int element) {
    if (low > high) return -1;

    int mid = low + (high - low)/2;
    if (arr[mid] > element)
        return helper(arr, n, low, mid - 1, element);
    else if (arr[mid] < element)
        return helper(arr, n, mid + 1, high, element);
    else {
        if (mid == n - 1 || arr[mid + 1] != arr[mid])
            return mid;
        else
            return helper(arr, n, mid + 1, high, element);
    }
}


int lastOccurrenceRecursive(int arr[], int n, int element) {
    return helper(arr, n, 0, n - 1, element);
}


// int lastOccurrenceIterative(int arr[], int n, int element) {
//     int low = 0, high = n - 1;
//     int res = -1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (arr[mid] < element) 
//             low = mid + 1;
//         else if (arr[mid] > element)
//             high = mid - 1;
//         else {
//             res = mid;
//             low = mid + 1;
//         }
//     }
//     return res;
// }

// int lastOccurrenceRecursive(int arr[], int n, int low, int high, int element, int res = -1) {
//     if (low > high) return res;
//     int mid = low + (high - low)/2;
//     if (arr[mid] > element)
//         return lastOccurrenceRecursive(arr, n, low, mid - 1, element, res);
//     else if (arr[mid] < element)
//         return lastOccurrenceRecursive(arr, n, mid + 1, high, element, res);
//     else {
//         res = mid;
//         return lastOccurrenceRecursive(arr, n, mid + 1, high, element, res);
//     }
//     return res;
// }


int main() {
    cout << "Enter the size of the array: ";
    int n; cin >> n;
    cout << "Enter the elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the element to find: ";
    int element; cin >> element;

    cout << "\nLast occurence (iterative) " << lastOccurrenceIterative(arr, n, element);
    cout << "\nLast occurence (recursive) " << lastOccurrenceRecursive(arr, n, element);
}