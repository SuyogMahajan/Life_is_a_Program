#include<iostream>
#include<string>
using namespace std;

string toBin(int n) {

string ans = "";
n = abs(n);

while(n != 0) {
    string t = (n%2 ? "1" : "0" );
    ans = t +ans;
    n /= 2;    
}

for(int i = 0;i<ans.size();i++) {
    ans[i] = ans[i] == '0' ? '1' : '0';
}

return ans;
}

int main() {

int n;
cin >> n;
cout << toBin(n) << endl;

return 0;
}