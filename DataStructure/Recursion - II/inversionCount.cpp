#include<iostream>
#include<vector>
using namespace std;

// using merge sort

int mergeArrays(int* a,int s,int e) {
int i = s;
int m = s+ (e-s)/2;
int j = m+1;
int cnt = 0;

vector<int> v;

while(i <= m and j <= e) {
    if(a[i] < a[j]) {
        v.push_back(a[i++]);
    }else{
        cnt += m-i+1;
        v.push_back(a[j++]);
    }
}

while(i <= m) {
v.push_back(a[i++]);
}

while(j <= e) {
v.push_back(a[j++]);
}

for(int k = 0;k< v.size();k++) {
    a[s+k] = v[k];
}

return cnt;
}

int mergeSort(int* a,int s,int e) {
    if(s >= e) return 0;
    int x,y,z;
    int m = s +(e-s)/2;
    // for(int i = s;i<=e;i++) {
    //     cout << a[i] <<" ";
    // }
    // cout << endl;

    x = mergeSort(a,s,m);
    y = mergeSort(a,m+1,e);

    z = mergeArrays(a,s,e);
    return x+y+z;
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    cout << mergeSort(a,0,n-1) << endl;

    // for(auto x:a) cout << x << " ";
    // cout << endl;
    return 0;
}