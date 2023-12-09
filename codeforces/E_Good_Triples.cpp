#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mod2 998244353
#define endl '\n' 
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}
#define printp(x) {for(auto v: x) {cout << v.first << ':' << v.second << ' ';} cout << endl;},
#define printv(x) { for (auto v: x){ print(v) }}

int main() {

ll int t;
cin >> t;

vector<ll int> v(10);

for(int x = 0;x < 10;x++) {
    for(int i = 0; i <= x;i++) {
        for(int j = 0; j <= (x-i);j++) {
            v[x]++;
        }
    }
}

while(t--) {

  string n;
  cin >> n;

  ll int ans = 1;
  for(auto x: n) {
    ans *= v[x-'0'];
  }

  cout << ans << endl;
}

return 0;
}