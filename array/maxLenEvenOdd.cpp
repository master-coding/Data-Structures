// Problem: Maximum Length Even Odd Subarray
// Find the maximum length of the subarray which contains alternate even odd or vice versa.
// {1, 2, 3, 4, 4} => {1, 2, 3, 4} => 4

#include <iostream>
using namespace std;

bool isEven(int n) {
    return n % 2 == 0;
}

// time complexity: O(n**2)
int maxLenMt1(int arr[], int n) {
    int res = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (( isEven(arr[j - 1]) && !isEven(arr[j]) ) || (!isEven(arr[j - 1]) && isEven(arr[j]))) {
                count++;
            } else {
                break;
            }
        }

        res = max(res, count);
    }

    return res;
}

// time complexity: O(n)
int maxLenMt2(int arr[], int n) {
    int res = 1, count = 1;

    for (int i = 1; i < n; i++) {
        if (( isEven(arr[i - 1]) && !isEven(arr[i]) ) || (!isEven(arr[i - 1]) && isEven(arr[i]))) {
            count++;
            res = max(res, count);
        } else {
            count = 1;
        }
    }

    return res;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << maxLenMt1(arr, n);
    cout << maxLenMt2(arr, n);
}
