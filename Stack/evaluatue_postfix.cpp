#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);

long long evaluate(string s) {
    stack <int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
            continue;
        
        else if (isdigit(s[i])) {
            // push the complete number to the stack till we get a space
            long long num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            st.push(num);
            i--;
            // we will break out of the while loop when we got the space or string ends
            // so we are doing i-- to reduce i to get the s[i] = ' '
        }
        else {
            long long value2, value1;
            if (st.size() > 1) {
                // to check whether the stack has 2 operands or not
                value2 = st.top(); st.pop();
                value1 = st.top(); st.pop();
            }
            else
                return -1;

            if (s[i] == '+') {
                st.push(value1 + value2);
            }
            else if (s[i] == '-') {
                st.push(value1 - value2);
            }
            else if (s[i] == '*')
                st.push(value1 * value2);
            else
                st.push(value1 / value2);
        }
    }
    // in the end stack should only contain only one value which is the ans
    if (st.size() != 1)
        return -1;
    else
        return st.top();
}

int main() {
    speedio;
    string s;
    getline(cin, s);
    if (evaluate(s) == -1)
        cout << "The given postfix expression is not correct.\n";
    else
        cout << evaluate(s);
    // this program is written under consideration that the user will provide the 
    // correct postfix expression
}