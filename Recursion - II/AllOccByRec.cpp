#include<iostream>
#include<vector>
using namespace std;

vector<int> getAllOcc(int i,vector<int> a,int t) {
    vector<int> ans;
    int n=  a.size();
    if(i >= n) return ans;

   if(a[i] == t) {
    ans.push_back(i);
    vector<int> k = getAllOcc(i+1,a,t);
    ans.insert(ans.end(), k.begin(), k.end());
    return ans;
    }

   return getAllOcc(i+1,a,t);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    int t;
    cin >> t;

    vector<int> ans = getAllOcc(0,a,t);

    for(auto x:ans) cout << x << " ";
    return 0;
}