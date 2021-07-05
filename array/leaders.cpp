// // print the leaders in an array
// // eg arr[] = {10, 50, 23, 73, 11, 10}
// // op 73 11 10

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);

#define sp ' '
#define nl '\n'

void leaders(int arr[], int n) {
    int leader = arr[n - 1];
    cout << leader << sp;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            cout << leader << sp;
        }
    }
}

int main() {
    speedio;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];    
    leaders(a, n);
}
