// https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2023-09-24

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double champagneTower(int p, int ti, int tj) {

        vector<vector<double>> ans(ti+1,vector<double>(ti+1,0.0));
        
        int i = 0;
        ans[0][0] = p;

        while(i < ti) {
            int j = 0;
            for(;j<=i;j++) {
                if(ans[i][j] > 1) {
                    double t = ans[i][j]-1;
                    ans[i][j] = 1.0;
                    ans[i+1][j] += (t/2);
                    ans[i+1][j+1] += (t/2);
                }
            }

            i++;
        }
        for(auto x:ans){
             for(auto y:x) cout << y<<" ";

             cout << endl;}
        return ans[ti][tj];
    }
};

int main() {
    int p,i,j;

    cin >> p >> i >> j;
    Solution* s = new Solution();
    cout << s->champagneTower(p,i,j) << endl;
    
    return 0;
}