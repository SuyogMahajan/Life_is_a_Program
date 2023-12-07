#include<iostream>
using namespace std;

// Given a number n number people we have and max m number ofbikes we have 
// in how many ways they can go

int ways(int n) {
    if(n == 0 or n== 1) return 1;
    if(n == 2) return 2;
    return ways(n-1) + ((n-1)*ways(n-2));

    }

int main() {
int n;
cin >> n;

cout << ways(n) << endl;
return 0;
}