// Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.

#include <bits/stdc++.h>

using namespace std;

// time complexity: O(n**2)
int maximumDiffMt1(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int ans = arr[1] - arr[0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(arr[j] - arr[i], ans);
        }
    }

    return ans;
}

// time complexity: O(n)
int maximumDiffMt2(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int ans = arr[1] - arr[0], smallest = arr[0];

    for (int i = 1; i < n; i++) {
        ans = max(ans, arr[i] - smallest);
        smallest = min(smallest, arr[i]);
    }

    return ans;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << maximumDiffMt1(arr, n);
    cout << maximumDiffMt2(arr, n);
}