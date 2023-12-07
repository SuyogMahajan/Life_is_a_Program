#include <bits/stdc++.h>
using namespace std;
#define intl long long
#define mod 1000000007
#define mod2 998244353
#define endl '\n' 
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define print(x) {for(auto v: x) {cout << v<< ' ';} cout << endl;}
#define printp(x) {for(auto v: x) {cout << v.first << ':' << v.second << ' ';} cout << endl;},
#define printv(x) { for (auto v: x){ print(v) }}
 
// int rec(string s,unordered_map<string,int>&mp) {

//     if(mp.find(s) != mp.end()) return mp[s];
//     int ans = int(s.length());

//     for(int i = 1; i < s.length();i++) {
//         string temp = s;
//         if(s[i] != s[i-1]) {
//             temp.erase(i-1,2);
//             ans = min(ans,rec(temp,mp));
//         }
//     }

//     return mp[s] = ans;

// }

int main() {

int t;
cin >> t;

while(t--) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> freq(26,0);
    int maxc= 0;
    for(auto x:s) {
        freq[x-'a']++;
        maxc = max(maxc,(freq[x-'a']));
    }

    if(maxc > n/2) {
        cout << 2*maxc-n << endl;
    }else{
        cout << n%2 << endl;
    }
}

return 0;
}