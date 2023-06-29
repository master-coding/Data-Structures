// Problem: Equilibrium point
// equilibrium point is one whose left and right sum is same

#include <iostream>
using namespace std;

// time complexity: O(n**2)
bool equilibriumPointMt1(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int rightSum = 0, leftSum = 0;

        for (int j = i + 1; j < n; j++) rightSum += arr[j];
        for (int j = 0; j < i; j++) leftSum += arr[j];

        if (leftSum == rightSum)
            return true;
    }

    return false;
}

// time complexity: O(n)[3 traversals], auxillary space: O(n)
bool equilibriumPointMt2(int arr[], int n) {
    int leftSum[n], rightSum[n];
    leftSum[0] = 0;
    rightSum[n - 1] = 0;

    for (int i = 1; i < n; i++) {
        leftSum[i] = leftSum[i - 1] + arr[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        rightSum[i] = rightSum[i + 1] + arr[i + 1];
    }

    for (int i = 0; i < n; i++) {
        if (leftSum[i] == rightSum[i])
            return true;
    }

    return false;
}

/*
    1. Compute prefix sum
    2. compute suffix sum
    3. check if prefixSum[i - 1] == suffixSum[i + 1]
    4. corner cases: 0 == suffixSum[0] - arr[0]
                    prefixSum[n - 1] - arr[n - 1] == 0
*/

// time complexity: O(n), auxillary space: O(1)
bool equilibriumPointMt3(int arr[], int n) {
    int sum = 0, leftSum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    for (int i = 0; i < n; i++) {
        sum -= arr[i];
        if (sum == leftSum) 
            return true;
        
        leftSum += arr[i];
    }

    return false;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << equilibriumPointMt1(arr, n);
    // cout << equilibriumPointMt2(arr, n);
    cout << equilibriumPointMt3(arr, n);
}
