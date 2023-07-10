// find the first occurrence of an element in an sorted array

#include <iostream>
using namespace std;


// time complexity: O(logn)
int firstOccurrenceIterative(int arr[], int n, int element) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < element) low = mid + 1;
        else if (arr[mid] > element) high = mid - 1;
        else {
            if (mid == 0 || arr[mid - 1] != arr[mid]) return mid;
            else high = mid - 1;
        }
    }

    return -1;
}


int helper(int arr[], int low, int high, int element) {
    if (low > high) return -1;

    int mid = low + (high - low)/2;
    if (arr[mid] > element)
        return helper(arr, low, mid - 1, element);
    else if (arr[mid] < element)
        return helper(arr, mid + 1, high, element);
    else {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return helper(arr, low, mid - 1, element);
    }
}


// time complexity: O(logn)
int firstOccurrenceRecursive(int arr[], int n, int element) {
    return helper(arr, 0, n - 1, element);
}


int main() {
    cout << "Enter the size of the array: ";
    int n; cin >> n;
    cout << "Enter the elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter the element to find: ";
    int element; cin >> element;

    cout << "\nFirst occurence (iterative) " << firstOccurrenceIterative(arr, n, element);
    cout << "\nFirst occurence (recursive) " << firstOccurrenceRecursive(arr, n, element);
}
