// find the maximum circular subbarray sum

#include <iostream>
using namespace std;


// this question is solved using kadane's alogrithm
int maxArraySum(int arr[], int n) {
    int ans = arr[0], sum = arr[0];
    for (int i = 1; i < n; i++) {
        sum = max(sum + arr[i], arr[i]);
        ans = max(ans, sum);
    }
    return ans;
}

int maxCircular(int arr[], int n) {
    int arraySum = maxArraySum(arr, n);
    if (arraySum < 0)
        return arraySum;
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
        arr[i] = -arr[i];
    }
    int circularSum = total + maxArraySum(arr, n);
    
    return max(arraySum, circularSum);

// time complexity: O(n)    
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxCircular(arr, n);
}