#include <iostream>
using namespace std;


void towerOfHanoi(int n, char from_tower, char aux_tower, char to_tower) {
    if (n == 1) {
        cout << "Move disk 1 from " << from_tower << " to " << to_tower << '\n';
        return;
    }
    towerOfHanoi(n - 1, from_tower, to_tower, aux_tower);
    cout << "Move disk " <<  n << " from " << from_tower << " to " << to_tower << '\n';
    towerOfHanoi(n - 1 , aux_tower, from_tower, to_tower);

}

int  main() {
    int n; cin >> n;
    towerOfHanoi(3, 'A', 'B', 'C');
}
