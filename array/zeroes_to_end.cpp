// move zeroes to end
// a[] = {1, 2, 0, 0, 3} 
// a[] = {1, 2, 3, 0, 0}

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tlp int tc; cin >> tc; while (tc--)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sp ' '


// method 1
void ZereosEnd(int arr[], int n) {
    int temp[n];
    int j = 0, k = n - 1;
    rep(i, 0, n) {
        if (arr[i] == 0) {
            temp[k] = arr[i];
            k--;
        }
        else {
            temp[j] = arr[i];
            j++;
        }
    }
    rep(i, 0, n)
        cout << temp[i] << sp;
// time complexity O(n)
// auxillary space O(n)
}


// method 2
void ZeroesToEnd(int arr[], int n) {
    int count = 0;
    rep(i, 0, n) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
// time complexity - O(n)
// auxillary space - O(1)
}

int main() {
    speedio;
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n)
        cin >> arr[i];

    ZeroesToEnd(arr, n);
    rep(i, 0, n)
        cout << arr[i] << sp;
    // ZereosEnd(arr, n);    
}