#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define mod2 998244353
#define endl '\n' 
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}
#define printp(x) {for(auto v: x) {cout << v.first << ':' << v.second << ' ';} cout << endl;},
#define printv(x) { for (auto v: x){ print(v) }}

signed main() {

int t;
cin >> t;

while(t--) {

int n;
cin >> n;

int k = n%3;

if(k == 1 || k == 2) {
cout << "First" << endl;
}else{
cout << "Second" << endl;
}

}

return 0;
}