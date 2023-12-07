#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(int a[],int n,int k) {

    for(int i = 0; i < n;i++) {
        for(int j = i+1; j < n;j++) {
                if(a[i]+a[j] == k)
                return {i,j};       
    }
    return {-1 , -1};
}

// vector<int> binSolve(int a[],int n,int k) {



// }

int main() {

int n;
cin >> n;
int a[n];

for(int i = 0;i < n;i++) {
    cin >> a[i];
}

int k;
cin >> k;

vector<int> ans = solve(a,n,k);

cout << ans[0] <<" " << ans[1] << endl;

return 0;
}