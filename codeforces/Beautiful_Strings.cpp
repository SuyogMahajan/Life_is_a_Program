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
cin >>t ;
while(t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> freq(26,0);
    for(auto x:s) {
        freq[x-'a']++;
    }

    int ans = 1;

    for(int i =0;i <26;i++) {
        if(freq[i]!=0)
        ans = (ans*(freq[i]+1))%mod;
    }
    ans--;
    
    cout << ans<< endl;


}

return 0;
}