#include<iostream>
using namespace std;

int findWayOfFilling(int n) {
    if(n <= 3) return 1;
    if(n == 4) return 2;

    return findWayOfFilling(n-1)+findWayOfFilling(n-4);
}


// while brick size is 4 x 1
int main() {
    int n;
    cin >> n;

    cout << findWayOfFilling(n) << endl;
    return 0;
}
