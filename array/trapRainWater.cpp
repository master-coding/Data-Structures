// trap rain water problem
// arr[] = {2, 0, 2}   return 2

#include <iostream>
using namespace std;

// time complexity: O(n**2)
int trapRainWaterMt1(int arr[], int n) {
    // no water can be trapped on first and last block
    int maxTrapWater = 0;
    for (int i = 1; i < n - 1; i++) {
        int leftMax = arr[i];
        for (int j = 0; j < i; j++)
            leftMax = max(leftMax, arr[j]);

        int rightMax = arr[i];
        for (int j = i + 1; j < n; j++)
            rightMax = max(rightMax, arr[j]);

        maxTrapWater += min(leftMax, rightMax) - arr[i];
    }

    return maxTrapWater;
}

// time complexity: O(n), auxillary space: O(n)
int trapRainWaterMt2(int arr[], int n) {
    int lmax[n], rmax[n];
    lmax[0] = arr[0], rmax[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        lmax[i] = max(arr[i], lmax[i -1]);

    for (int j = n - 2; j >= 0; j--)
        rmax[j] = max(arr[j], rmax[j + 1]);
    
    int trapWater = 0;
    for (int i = 1; i < n - 1; i++) {
        trapWater += min(lmax[i], rmax[i]) - arr[i];
    }

    return trapWater;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << trapRainWaterMt1(arr, n);
    cout << trapRainWaterMt2(arr, n);
}