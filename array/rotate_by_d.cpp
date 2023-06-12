// rotate array by d
// eg arr[] = {10, 20, 30, 40, 50, 60} d = 3
// arr[] = {40, 50, 60, 10, 20, 30}

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tlp int tc; cin >> tc; while (tc--)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sp ' '
#define nl '\n'
#define newline cout << '\n'

void leftRotateByOne(int arr[], int n) {
    int temp = arr[0];

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = temp;
}

// time complexity: O(nd), auxillary space: O(1)
void rotateByDMt1(int arr[], int n, int d) {
    if (d >= n)
        d = d % n;
    
    for (int i = 0; i < d; i++) {
        leftRotateByOne(arr, n);
    }
}

// time complexity: O(n), space: O(d)
void rotateByMt2(int arr[], int n, int d) {
    if (d >= n) {
        d = d % n;
    }

    int temp[d];

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - d; i++) {
        arr[i] = arr[i + d];
    }

    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

// time complexity: O(n), auxillary space: O(1)
void rotateByDMt3(int arr[], int n, int d) {
    if (d >= n) {
        d = d - n;
    }

    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

int main() {
    speedio;
    int n, d;
    cin >> n >> d;
    int arr[n];
    rep(i, 0, n)
        cin >> arr[i];
    
    // rotateByDMt1(arr, n, d);
    // rotateByDMt2(arr, n, d);
    rotateByDMt3(arr, n, d);

    rep(i, 0, n)
        cout << arr[i] << sp;
}