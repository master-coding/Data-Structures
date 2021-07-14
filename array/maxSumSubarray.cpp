// find the maximum sum in the array possible
// arr[] = {1, 2, 3, -8, 3}     8
// arr[] = {1, 2, 3}    6

#include <iostream>
using namespace std;

void maxSumSubarray(int arr[], int n) {
    int ans = arr[0], sum = arr[0];
    if (n < 1) {
        cout << "Array have 0 elements";
        return;
    }

    for (int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);
        ans = max(sum, ans);
    }

    cout << ans;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    maxSumSubarray(arr, n);
}