// Problem: Find the square root of a number
// eg 4 => 2, 16 => 4, 15 => 3, 8 => 2 [i.e, floor of sq root] 

#include <iostream>
using namespace std;

// time: O(x**1/2)
int sqRootMt1(int n) {
    int i = 1;
    while (i * i <= n) {
        i++;
    }

    return i - 1;
}

// time: O(logx)
int sqRootMt2(int n) {
    int low = 1, high = n, res = -1;
    
    if (n < 0) 
        return res;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid == n / mid) return mid;
        else if (mid > n / mid) high = mid - 1;
        else {
            res = mid;
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    int n; cin >> n;
    // cout << sqRootMt1(n);
    cout << sqRootMt2(n);
}
