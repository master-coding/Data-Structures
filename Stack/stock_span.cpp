// ST0CK SPAN PROBLEM

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

int main() {
    speedio;
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n)
        cin >> a[i];

    stack <int> s;
    rep(i, 0, n) {
        while (s.empty() == false && a[i] >= a[s.top()]) {
            s.pop();
        }
        int span = s.empty() ? i + 1 : i - s.top();
        cout << "Span of " << a[i] << " is " << span << nl;
        s.push(i);
    }
    /* span in an increasing array is increasing  
    eg [10 20 30] span is [1 2 3]
    span of all elements in a decreasing array is 1 
    eg [30 20 10] span is [1 1 1]*/
}
/* example
10
3 5 10 7 8 23 11 1 20 8

output
Span of 3 is 1
Span of 5 is 2
Span of 10 is 3
Span of 7 is 1
Span of 8 is 2
Span of 23 is 6
Span of 11 is 1
Span of 1 is 1
Span of 20 is 3
Span of 8 is 1

*/