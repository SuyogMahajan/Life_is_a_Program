#include<iostream>
#include<vector>
using namespace std;

void mergeArrays(int* a,int s,int e) {
int i = s;
int m = s+ (e-s)/2;
int j = m+1;

vector<int> v;

while(i <= m and j <= e) {
    if(a[i] < a[j]) {
        v.push_back(a[i++]);
    }else{
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

}

void mergeSort(int* a,int s,int e) {
    if(s >= e) return;

    int m = s +(e-s)/2;
    // for(int i = s;i<=e;i++) {
    //     cout << a[i] <<" ";
    // }
    // cout << endl;

    mergeSort(a,s,m);
    mergeSort(a,m+1,e);

    mergeArrays(a,s,e);
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    mergeSort(a,0,n-1);

    for(auto x:a) cout << x << " ";
    cout << endl;
    return 0;
}