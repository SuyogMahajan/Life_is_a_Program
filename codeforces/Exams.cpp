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

int t;
cin >> t;

while(t--) {
    int x,y,z;

    cin >> x >> y >> z;

    int t = x*y;
    if(z > t/2) {
        cout <<"Yes" << endl;
    }else{
        cout <<"No" << endl;
    }

}

return 0;
}