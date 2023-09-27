#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void rec(int i,vector<int>& a,vector<bool> &visited,long long &ans,int k) {
if( i>= 0 && i < a.size()){
    // cout <<i << endl;
    long long smallest_diff = _LONG_LONG_MAX_;
    int next_ind = i;

    for(int j = i%k;j<a.size();j+=k) {
        if(!visited[j]){
            visited[j] = true;
            if(j+1 < a.size()){
            int d = abs(a[j+1]-a[j]);
            if(  smallest_diff >= d && !visited[j+1]  ){
                smallest_diff = d;
                next_ind = j+1;
            }
            }
        }
    }

   if(smallest_diff != _LONG_LONG_MAX_){ 
    //  cout<< smallest_diff<< endl;
     ans += smallest_diff;
   
   }
    for(auto x:visited) {
        if(!x) {
         rec(next_ind,a,visited,ans,k);
         break;
        }
    }
}
}

long long superMovement(int n,vector<int> &a,int k) {

vector<bool> visited(n,false);
long long ans =0;

rec(0,a,visited,ans,k);

return ans;
}

int main() {
int n,k;
cin  >> n>> k;
vector<int> v;

for(int i = 0;i<n;i++) {
int x;
cin >> x;
v.push_back(x);
}

cout << superMovement(n,v,k) << endl;
return 0;
}
