#include<iostream>
using namespace std;

int rec_fibo(int n) {
    // base case
    if(n == 0 or n == 1) return n;
    
    // recursive call
    return rec_fibo(n-1) + rec_fibo(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << rec_fibo(n) << endl;
    return 0;
}