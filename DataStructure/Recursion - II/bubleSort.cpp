#include<iostream>
using namespace std;

void bubleSort(int* a,int j,int n) {
    // base case
    if(n == 1) return;
    for(int i = 0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    if(j == n-1) return bubleSort(a,0,n-1);

    
    if(a[j] > a[j+1]) {
        swap(a[j],a[j+1]);
    }

    return bubleSort(a,j+1,n);
}

int main() {
    int n;
    cin  >> n;

    int a[n];

    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }

    bubleSort(a,0,n);

    for(int i = 0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout<< endl;
    return 0;
}