// find the peak element in the array

#include <iostream>
using namespace std;

int peak(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if ((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == n - 1 || arr[mid + 1] < arr[mid]))
            return mid;
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (peak(arr, n) == -1)
        cout << "There is no peak element.";
    else
        cout << arr[peak(arr, n)];
}