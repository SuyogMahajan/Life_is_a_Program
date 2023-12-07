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

int main() {

int t;
cin >> t;

while(t--) {
    unordered_map<char,int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;
    m['f'] = 6;
    m['g'] = 7;
    m['h'] = 8;

    string s;
    cin >> s;

    for(int i = 1;i <= 8;i++) {

        if(char('0'+i) != s[1])
        cout << s[0] << char('0'+i) <<endl;
    }

    for(int i = 0;i < 8;i++) {
        if(char('a'+i) != s[0])
        cout << char('a'+i) <<s[1] <<endl;
    }

    
}

return 0;
}