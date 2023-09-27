#include<iostream>
using namespace std;

// we have given max number of step and length of ladder 
// find number of ways to climb stairs

int ways(int ladder,int step ){
    if(ladder == 0 or ladder == 1) return 1;

    return ways(ladder-1,step) + ways(ladder-step,step);

}

int main() {
  int ladder,step;
  cin >> ladder >> step;

  cout << ways(ladder,step) << endl;

}