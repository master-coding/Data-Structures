// print the leaders in an array, 
// an element is a leader if there is no element greater to the right side of it 
// arr[] = {10, 50, 23, 73, 11, 10}, op => 73 11 10

#include <bits/stdc++.h>
using namespace std;

#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL);

#define sp ' '
#define nl '\n'

void printVector(vector <int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << sp;
    }
}

// time complexity: O(n ** 2), auxillary space: O(1)
void leadersInArrayMt1(int arr[], int n) {
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        bool isGreaterOnRight = false;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isGreaterOnRight = true;
                break;
            }
        }

        if (!isGreaterOnRight) {
            ans.push_back(arr[i]);
        }
    }

    printVector(ans);
}

// time complexity: O(n), auxillary space: O(n)
void leadersInArrayMt2(int arr[], int n) {
    int leader = arr[n - 1];
    vector <int> ans;
    ans.push_back(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            ans.push_back(leader);
        }
    }

    reverse(ans.begin(), ans.end());
    printVector(ans);
}

int main() {
    speedio;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];    
    
    leadersInArrayMt1(a, n);
    leadersInArrayMt2(a, n);
}
