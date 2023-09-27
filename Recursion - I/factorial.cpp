#include<iostream>
using namespace std;

int rec(int n) {
    // base case
    if(n == 0) return 1;
    
    // recursive call
    return n*rec(n-1);
}


int main() {
    int n;
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}