#include<iostream>
#define INT_MAX 1e9
#include<vector>
using namespace std;

int rec(int i,int n,vector<int>& cost,vector<int>& dp) {
    if(i >= n) return INT_MAX;
    if(i == n-1) return 0;

    if(dp[i] != -1) return dp[i];
        
    int a = abs(cost[i]-cost[i+1]) + rec(i+1,n,cost,dp);
    int b = abs(cost[i]-cost[i+3]) + rec(i+3,n,cost,dp);

    return dp[i] = min(a,b);
}

int minimumCost(int n,vector<int> cost) {
    vector<int> dp(n,-1);
    return rec(0,n,cost,dp);
}

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0;i<n;i++) {
        cin >> v[i];
    }

    cout << minimumCost(n,v) << endl;

return 0;
}