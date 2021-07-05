// // print the leaders in an array
// // eg arr[] = {10, 50, 23, 73, 11, 10}
// // op 73 11 10

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tlp int tc; cin >> tc; while (tc--)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sp ' '
#define nl '\n'
#define newline cout << '\n'
#define ll long long int

#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define yes cout << "YES" << nl
#define no cout << "NO" << nl

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
    rep(i, 0, n)
        cin >> a[i];  
    
    leaders(a, n);
}
