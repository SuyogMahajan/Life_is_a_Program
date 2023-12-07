#include<iostream>
#include<string>
using namespace std;

int stringToNum(int i,string s) {

int len = s.length();
if(i == len-1) {
    return s[i]-'0';
}

int a = stringToNum(i+1,s);
int p = 1;
for(int j = 0;j< (len-i-1);j++) {
    p *= 10;
}

return (s[i] - '0')*p + a;
}

int main() {

string a;
cin >> a;

cout << stringToNum(0,a) << endl;

return 0;
 
}
