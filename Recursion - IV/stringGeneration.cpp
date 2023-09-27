#include<iostream>
#include<string>
#include<vector>
using namespace std;

void generateStrings(int i,string s,string temp,vector<string> &ans) {
    if(i == s.length()) {
     ans.push_back(temp);
     return;
    }

    generateStrings(i+1,s,temp,ans);
    temp += s[i];
    generateStrings(i+1,s,temp,ans);
}

int main() {
string a;
cin >> a;

vector<string> ans;
generateStrings(0,a,"",ans);

for(auto x:ans) cout << x <<" ";
cout << endl;

return 0;
}
