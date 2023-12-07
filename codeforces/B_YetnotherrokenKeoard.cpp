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
    string s;
    cin >> s;

    int l = s.length();

    stack<int> upp;
    stack<int> low;
    string ans = "";
    int j = 0;
    for(int i = 0;i < l;i++) {
        if(s[i] == 'b') {
            if(!low.empty()) {
                int t = low.top();
                low.pop();
                ans[t] ='0';
            }
        }else if(s[i] == 'B') {
            if(!upp.empty()) {
                int t = upp.top();
                upp.pop();
                ans[t] = '0';
            }
        }else{
            ans.push_back(s[i]);
            if(isupper(s[i])) upp.push(j);
            else low.push(j);
            j++;
        }
    }
    string ans1 = "";
    for(int i = 0; i <ans.length();i++) {
        if(ans[i] !='0') { ans1.push_back(ans[i]);
        }
    }
    cout << ans1 << endl;
}

return 0;
}