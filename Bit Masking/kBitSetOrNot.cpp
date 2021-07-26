// check if the kth bit is set or not

#include <iostream>
using namespace std;

bool kbitSetOrNot(unsigned int n, unsigned int k) {
    if (n >> (k - 1) & 1 == 1)
        return true;
    return false;
}

int main() {
    unsigned int number, k;
    cout << "Enter the number : "; cin >> number;
    cout << '\n';
    cout << "Which set bit to check : " ; cin >> k;
    cout << '\n';
    if(kbitSetOrNot(number, k))
        cout << "kth bit is set.";
    else
        cout << "kth bit is not set.";
}