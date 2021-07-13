// trap rain water problem
// arr[] = {2, 0, 2}   return 2

#include <iostream>
using namespace std;

int trapwater(int arr[], int n) {
    int lmax[n], rmax[n];
    lmax[0] = arr[0], rmax[n-1] = arr[n - 1];
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
    cout << trapwater(arr, n);
}