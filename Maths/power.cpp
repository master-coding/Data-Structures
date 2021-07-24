#include <iostream>
using namespace std;

long long power(long long val, long long exp) {
    long long res = 1;
    while(exp > 0) {
        if (exp & 1)
            res = res * val;
        val = val * val;
        exp = exp >> 1;
    }
    return res;
// time complexity : O(logn)
// auxillary space : O(1)
}

int main() {
    cout << power(4, 20);
}