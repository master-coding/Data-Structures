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

void rotate_by_d(int arr[], int n, int d) {
    if (d >= n) {
        d = d - n;
    }

    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
// time complexity : O(n)
// auxillary space : O(1)
}

int main() {
    speedio;
    int n, d;
    cin >> n >> d;
    int arr[n];
    rep(i, 0, n)
        cin >> arr[i];
    
    rotate_by_d(arr, n, d);
    rep(i, 0, n)
        cout << arr[i] << sp;
}