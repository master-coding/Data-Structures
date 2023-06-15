// frequencies of elements in a sorted array

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sp ' '
#define nl '\n'

// time complexity: O(n**2)
void sortedArrayFrequenciesMt1(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
                i++;
            } else {
                break;
            }
        }

        cout << arr[i] << " : " << count << nl;
    }
}

// time complexity: O(n)
void sortedArrayFrequenciesMt2(int arr[], int n) {
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

// time complexity: O(n), auxillary space: O(n)
void sortedArrayFrequenciesMt3(int arr[], int n) {
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    for (auto element : m) {
        cout << element.first << " : " << element.second << nl;
    }
}

int main() {
    speedio;
    
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // sortedArrayFrequenciesMt1(a, n);
    // sortedArrayFrequenciesMt2(a, n);
    sortedArrayFrequenciesMt3(a, n);
}