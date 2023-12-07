#include<iostream>
using namespace std;

bool is_sorted(int* a,int n) {
    // base case
    if(n <= 1) return true;

    // operations
    if(a[0] > a[1]) return false;

    // recursive call
    return is_sorted(a+1,n-1);
}

int main() {

    int n;
    cin >> n;

    int a[n];

    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    cout << is_sorted(a,n) << endl;
    return 0;
} 