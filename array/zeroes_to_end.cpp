// move zeroes to end
// a[] = {1, 2, 0, 0, 3} 
// a[] = {1, 2, 3, 0, 0}

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tlp int tc; cin >> tc; while (tc--)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sp ' '

// time complexity: O(n**2), auxillary space: O(1)
void zeroesToEndMt1(int arr[], int n) {
    rep(i, 0, n) {
        if (arr[i] == 0) {
            rep(j, i + 1, n) {
                if (arr[j] != 0) {
                    swap(arr[j], arr[i]);
                    break;
                }
            }
        }
    }
}

// time complexity: O(n), auxillary space: O(n)
void zeroesToEndMt2(int arr[], int n) {
    int temp[n];
    int j = 0, k = n - 1;
    
    rep(i, 0, n) {
        if (arr[i] == 0) {
            temp[k--] = 0;
        }
        else {
            temp[j] = arr[i];
            j++;
        }
    }
    
    rep(i, 0, n) {
        arr[i] = temp[i];
    }
}

// time complexity: O(n), auxillary space: O(1)
void zeroesToEndMt3(int arr[], int n) {
    int nonNegative = 0;

    rep(i, 0, n) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonNegative]);
            nonNegative++;
        }
    }
}

int main() {
    speedio;
    int n; cin >> n;
    int arr[n];

    rep(i, 0, n)
        cin >> arr[i];

    // zeroesToEndMt1(arr, n);
    // zeroesToEndMt2(arr, n);
    zeroesToEndMt3(arr, n);

    rep(i, 0, n)
        cout << arr[i] << sp;
}