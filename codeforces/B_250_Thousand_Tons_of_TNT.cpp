#include <bits/stdc++.h>
using namespace std;
#define intl long long int
#define mod 1000000007
#define mod2 998244353
#define endl '\n' 
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}
#define printp(x) {for(auto v: x) {cout << v.first << ':' << v.second << ' ';} cout << endl;},
#define printv(x) { for (auto v: x){ print(v) }}

void solve() {
    intl n;
    cin >> n;

    vector<intl> v(n);
    intl N = 150000+1;

    for(intl i = 0; i < n;i++) {
        cin >> v[i];
    }

    vector<vector<intl>> div(N);

    for(intl i = 1; i < N;i++) {
        for(intl j = i*2; j < N; j+= i) {
            div[j].push_back(i);
        }
    }
    intl ans = 0;

    for(auto x:div[n]) {
        intl minn = 1e18;
        intl maxx = -1e18;

        for(int j = 0; j < n;j+=x) {
          
            intl sum = accumulate(v.begin()+j,v.begin()+j+x,011);
            minn = min(minn,sum);
            maxx = max(maxx,sum);
        }

        ans = max(ans,(maxx-minn));
    }
    cout << ans << endl;
    }

int main() {

int t;
cin >> t;

while(t--) {
    solve();
}

return 0;
}