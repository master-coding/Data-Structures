// count the number of set bits in a number

#include <iostream>
using namespace std;

// this method used Brain Kerningham alogrithm
int countSetBits(unsigned int n) {
    int noOfSetBits = 0;
    while (n > 0) {
        n = n & (n - 1);
        noOfSetBits++;
    }
    return noOfSetBits;
}

int main() {
    unsigned int n;  cin >> n;
    cout << countSetBits(n);
}