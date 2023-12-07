#include<iostream>
using namespace std;

void towerOfHanoi(int n,string this_rod,string temp_rod,string target_rod) {
    if(n == 0) return;

    towerOfHanoi(n-1,this_rod,target_rod,temp_rod);
    cout << "move "<< n << " from "<<this_rod << " to " << target_rod << endl;
    towerOfHanoi(n-1,temp_rod,this_rod,target_rod);
}

int main() {
    int n;
    cin >> n;

    towerOfHanoi(n,"A","B","C");
    return 0;
}