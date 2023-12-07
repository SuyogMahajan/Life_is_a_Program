#include<iostream>
#include<string>
using namespace std;

string NumName[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printNum(int n) {
    if(n == 0) return;
    int digit = n%10;
    printNum(n/10);
    cout <<" "<< NumName[digit] ;
}

int main() {
    int n;
    cin >> n;

    printNum(n);
    return 0;
}