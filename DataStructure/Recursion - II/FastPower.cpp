#include<iostream>
using namespace std;

int fastPower(int m,int n) {
  if(n == 1 ) return m;
  if(n == 0) return 1;

  int x = fastPower(m,n/2);
  x *= x;

  if(n&1) x *= m;

  return x;
}

int main() {
    
    int n,m;
    cin >> m >> n;
    cout << fastPower(m,n) << endl;

    return 0;
}