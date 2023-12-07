#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> suffix(string s) {
    int n = s.length();
    vector<int> p(n);

    for(int i = 0 ;i < n;i++) {
        p[i] = i;
    }

    // this return indexes according to lexiographical order
    // for input : bcad , output vector: 2 0 1 3
    
    struct Compare{
        string str;  
        Compare(string s): str(s){}
        bool operator()(int a,int b) {
            return str.substr(a) < str.substr(b);
        }
    };

    sort(p.begin(),p.end(),Compare(s));
    return p;
}

int solve(string s,vector<string> q) {
    int n = s.length();
    vector<int> t = suffix(s);
    for(auto x:t)  {
        cout <<x <<" ";
    }
    cout << endl;
    int ans = 0;

    for(auto x:q) {
        int l = 0,r = n, o = x.length();
        while(l + 1 < r) {
            int m = (l+r)/2;
            if(s.substr(t[m],o) < x){
                l = m;
            }else{
                r = m;
            }
        }

        if(s.substr(t[r],o) == x){
            ans += (n - t[r]);
        }
    }

    return ans%1000000007;

}

// mzadpoghyykht
// 1
// yk

int main() {
    int n;
    string s;
    vector<string> q;

    cin >> s >> n;

    for(int i = 0 ;i <n;i++) {
        string t;
        cin >> t;
        q.push_back(t);
    }

    cout << solve(s,q) << endl;

    return 0;
}