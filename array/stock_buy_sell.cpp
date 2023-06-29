// stock buy and sell
// find the maximum profit that can be gained
// eg {5, 2, 1, 10, 2, 7} o/p: 14

#include <bits/stdc++.h>
using namespace std;

int stockBuySell(int arr[], int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            res += arr[i] - arr[i - 1];
        }
    }

    return res;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << stockBuySell(arr, n);
}
