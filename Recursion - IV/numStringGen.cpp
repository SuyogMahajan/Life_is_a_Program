#include<iostream>
#include<string>
using namespace std;

void printAllPos(int i,string temp,int* digit,int n) {
    if(i >= n) {
        cout << temp <<" ";
        return;
    }

    printAllPos(i+1,temp + string(1,'A'+digit[i]-1),digit,n);

    if(n-i >= 2){
        int num = digit[i]*10 + digit[i+1];
        if(num < 27)
        printAllPos(i+2,temp +string(1,('A' +num-1)),digit,n);
    }

}

int main() {

int n;
cin >> n;

int digit[n];

for(int i =0;i<n;i++) {
    cin >> digit[i];
}

printAllPos(0,"",digit,n);
cout << endl;
return 0;
}