// find the majority element in the array
// majority element is the element which occurs more than size/2 times in the array

#include <iostream>
using namespace std;


// it is solved using bore moore voting alogrithm
int majority(int arr[], int n) {
    int idx = 0, count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[idx])
            count++;
        else 
            count--;
        
        if (count == 0) {
            idx = i;
            count = 1;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[idx])
            cnt++;
    }
    if (cnt <= n/2) 
        return -1;
    
    return idx;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << majority(arr, n);
}