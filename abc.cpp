#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool cmpr(pair<int,int> a,pair<int,int> b) {
    return a.second > b.second;
}

int solve(vector<int> a,vector<int> b,int s) {

int n = a.size();
vector<pair<int,int>> ans(n);

for(int i = 0;i<n;i++) {
    ans[i] = make_pair(i,b[i]-a[i]);
}

sort(ans.begin(),ans.end(),cmpr);


int max_profit = 0;
int stock_price = 0;

for(auto x: ans) {
    if(stock_price +a[ x.first] <= 250 ) {
        // cout << x.first << endl;
        max_profit += x.second;
        stock_price += a[x.first];
    }   
}

return max_profit;

}

int main() {

vector<int> a = {175,133,109,210,97};
vector<int> b = {200,125,128,228,133};

cout << solve(a,b,250) << endl;
return 0;
}