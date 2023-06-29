// Problem: Maximum consecutive One
// eg {1, 1, 1, 0, 0, 1} op: 3

#include <iostream>
using namespace std;

// time complexity: O(n**2)
int maxConsecutiveOneMt1(int arr[], int n) {
    int maxConsecutiveOne = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] == 1) {
                    count++;
                } else {
                    break;
                }
            }

            maxConsecutiveOne = max(maxConsecutiveOne, count);
        }

    }

    return maxConsecutiveOne;
}

// time complexity: O(n)
// uses sliding window approach
int maxConsecutiveOneMt2(int arr[], int n) {
    int maxConsecutiveOne = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            maxConsecutiveOne = max(maxConsecutiveOne, count);
        } else {
            count = 0;
        }
    }

    return maxConsecutiveOne;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << maxConsecutiveOneMt1(arr, n);
    cout << maxConsecutiveOneMt2(arr, n);
}
