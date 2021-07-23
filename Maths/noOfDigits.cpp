#include <bits/stdc++.h>
using namespace std;

int noOfDigitsIterative(long long n) {
    int ans = 0;
    while (n) {
        ans++;
        n = n / 10;
    }
    return ans;
}

int noofDigitsRecursive(long long n) {
    if (n == 0)
        return 0;
    else
        return 1 + noofDigitsRecursive(n / 10);
}

int noOfDigits(long long n) {
    return floor(log10(n) + 1);
}

int main() {
    long long n;  cin >> n;
    cout << noOfDigitsIterative(n) << ' ' << noofDigitsRecursive(n) << ' ' << noOfDigits(n);
}