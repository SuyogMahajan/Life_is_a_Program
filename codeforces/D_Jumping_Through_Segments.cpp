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

bool check(ll int k,vector<pair<ll int,ll int>> &v) {
        ll int x = 0, y = 0;
        for(auto t: v) {
            ll int a = t.first, b = t.second;
            x -= k;
            y += k;
            x = max(x,a);
            y = min(y,b);

            if(x > y) {
                return false;
            }
        }
        return true;
}

int main() {

ll int t;
cin >> t;

while(t--) {
    ll int n;
    cin >> n;

    vector<pair<ll int,ll int>> v(n);

    for(ll int i = 0 ; i < n;i++) {
        ll int a,b;
        cin >> a >> b;
        v[i] = {a,b};
    }

    ll int x = 0,y = 0;
    ll ans = 1e9;
    ll int low = 0,high = 1e9,mid;
    while(low <= high) {
        
        mid = (low+high)/2;
      
        if(check(mid,v)) {
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << ans << endl;

}

return 0;
}