#include<iostream>
using namespace std;

int multiply_withoutx(int n,int m) {
    if(m == 1) return n;

    return n + multiply_withoutx(n,m-1);
}

int main() {
    int n,m;
    cin >>  n >> m;
    cout << multiply_withoutx(n,m) << endl;
    return 0;
}