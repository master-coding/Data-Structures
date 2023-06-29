// Problem: Maximum sum Subarray
// Find the maximum sum from all the subarrays
// eg: {1, 2, 3, -8, 3, 5}

#include <iostream>
using namespace std;

// time complexity: O(n**2)
// this method creates all the subarrays and find the maximum sum in all
int maxSumSubarrayMt1(int arr[], int n) {
    int maxSum = arr[0];

    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = i; j < n; j++) {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}


// time complexity: O(n)
// Uses Kadane's algo: Find the maximum subarray sum till that point (prevMaxSum + arr[i], arr[i])
int maxSumSubarrayMt2(int arr[], int n) {
    int maxSum = arr[0], maxSumSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        maxSumSoFar = max(maxSumSoFar + arr[i], arr[i]);
        maxSum = max(maxSumSoFar, maxSum);
    }
    
    return maxSum;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << maxSumSubarrayMt1(arr, n);
    cout << maxSumSubarrayMt2(arr, n);
}
