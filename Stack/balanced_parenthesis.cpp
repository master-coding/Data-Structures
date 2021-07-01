// BALANCED PARENTHESIS
// parenthesis allowed are {} () []

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


unordered_map <char, int> m = {{'(', 1}, {'[', 2}, {'{', 3},
{')', -1}, {']', -2}, {'}', -3},};

bool balancedParenthesis(const string &s, int n) {
    stack <char> check;
    rep(i, 0, n) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            check.push(s[i]);
        }
        else {
            if (check.empty() == true) {
                return false;
            }
            else {
                if (m[s[i]] + m[check.top()] != 0)
                    return false;
                else
                    check.pop();
            }
        }
    }
    return true;
}

int main() {
    speedio;
    string s;
    cin >> s;
    int n = s.length();
    if (balancedParenthesis(s, n))
        cout << "Parenthesis are balanced." << nl;
    else
        cout << "Unbalanced parenthesis" << nl;
}

// time complexity O(n)
/* example
([]){}
Parenthesis are balanced.

([]))
Unbalanced parenthesis

*/
