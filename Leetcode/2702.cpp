#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> dp;
    unordered_set<string> mpp;
    
    int rec(int b,int till,string s){
           
        // if(dp[b] != -1) return dp[b];
        int ans = s.length()-till;
        int longest = 1;

        for(int i = b;i <s.length();i++) {
            for(int j = 1;i+j <= s.length();j++) {
                string t = s.substr(i,j);
                if(mpp.find(t)!= mpp.end()){
                    ans = min(ans, rec(i+j,till+j,s));

                }
            }
        }
        ans = min(ans, int(s.length() - till));
        if(ans == 2)
        cout << b << " " << ans << endl; 
        
        return ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto x:dictionary) {
            mpp.insert(x);
        }
        dp = vector<int>(s.length()+1,-1);

        return rec(0,0,s);
    }
};

int main() {
string s;
cin >> s;

vector<string> v;

int n;
cin >> n;
while(n--) {
    string k;
    cin >> k;
    v.push_back(k);
} 

Solution sol;
cout << sol.minExtraChar(s,v) << endl;

return 0;
}


// octncmdbgnxapjoqlofuzypthlytkmchayflwky
// 47

// m  its  imaby  pa  ijmnvj  k  mhka  n  y  nc  wq  p  mjqqa  ht  dfoa  yqa  kk  pixq  ixsdln  rh  dwl  dbgnxa  kmpfz  nhxjm  wg  wky  oct  og  uhin  zxb  qz  tpf  hlrc  j  l  tew  xbn  a  uzypt  uvln  mchay  onnbi  hlytk  pjoqlo  dxsjr  u  uj
