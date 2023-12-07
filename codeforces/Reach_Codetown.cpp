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

bool check(string s) {

    int a[8] = {1,0,1,0,1,0,1,1};
    if(s.length() != 8) {
        return false;
    }else{
    for(int i = 0; i < 8;i++) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            if(a[i]) {
                return false;
                }
        }else{
            if(!a[i]) {
                return false;
            }
        }
    }
    }
    return true;
}

int main() {
int t;
cin >> t;

while(t--) {
    string s;
    cin >> s;

    if(check(s)) cout <<"Yes" << endl;
    else cout << "No" << endl;

}
return 0;
}