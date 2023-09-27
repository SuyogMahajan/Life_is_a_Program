#include<iostream>
using namespace std;

void rec_increasing(int* a,int n) {
  // base case
  if(n <= 0) {
    cout << endl;
    return;
  }
  
  // output first number
  cout<< a[0] <<" ";

  // making recursive call
  rec_increasing(a+1,n-1);

 }

void rec_decreasing(int* a,int n) {
   // base case
   if(n <= 0) {
    return;
   }
   // recursive call
   rec_decreasing(a+1,n-1);

   // output
   cout << a[0] << " " ;
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for(int i = 0;i<n;i++) {
       cin >> a[i];
    }

    rec_increasing(a,n);
    rec_decreasing(a,n);

}