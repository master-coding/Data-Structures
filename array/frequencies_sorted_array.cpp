// frequencies of elements in a sorted array

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sp ' '
#define nl '\n'

void sortedArrayFrequencies(int arr[], int n) {
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        }
        else {
            cout << arr[i - 1] << " : " << count << nl;
            count = 1;
        }
    }
    cout << arr[n - 1] << " : " << count << nl;
}

int main() {
    speedio;
    
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sortedArrayFrequencies(a, n);
}