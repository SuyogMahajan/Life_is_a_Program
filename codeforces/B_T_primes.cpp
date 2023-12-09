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

// bool isPerfectSquare(ll x)
// {
//     long long left = 1, right = x;
 
//     while (left <= right) {
//         long long mid = (left + right) / 2;
 
//         // Check if mid is perfect square
//         if (mid * mid == x) {
//             return true;
//         }
 
//         // Mid is small -> go right to increase mid
//         if (mid * mid < x) {
//             left = mid + 1;
//         }
 
//         // Mid is large -> to left to decrease mid
//         else {
//             right = mid - 1;
//         }
//     }
//     // cout <<"*" << endl;
//     return false;
// }
// bool isSquarePrime(ll n) {
//     ll int i = 2;

//     for(; i*i < n;i++) {
//         if(n%i == 0) {
//             return false;       
//         }
//     }
//     return true;
// }
int main() {

int t;
cin >> t;

vector<bool> v(int(1e7+1),1);
v[1] = 0;
v[0] = 0;
for(int i = 2; i*i <= (1e7);i++){
    if(v[i]) 
    for(int j = 2*i;j <= (1e7);j+=i) v[j] = false;
}

while(t--) {
    ll int n;
    cin >> n;

    bool flag = true;
    ll int t = sqrt(n);
    ll int k = t*t;

    if(k == n && v[t]){
        cout <<"YES" << endl;
    }else{
        cout <<"NO"<< endl;
    }
}

return 0;
}