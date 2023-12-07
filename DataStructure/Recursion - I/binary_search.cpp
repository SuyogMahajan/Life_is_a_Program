#include<iostream>
using namespace std;


int binary_search(int* a,int s,int e,int t) {
   if(s > e) return -1;

   int m = s + (e-s)/2;

   if(a[m] == t) {
    return m;
   }else if(a[m] < t) {
     return binary_search(a,m+1,e,t);
   }

   return binary_search(a,s,m-1,t);
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i =0 ;i<n;i++) {
        cin >> a[i];
    }

    int t;
    cin >> t;

    cout << binary_search(a,0,n-1,t) << endl;

    return 0;
}