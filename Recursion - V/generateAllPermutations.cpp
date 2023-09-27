#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permute(int i,string s) {
    
    // base case
    if(i == s.length()) {
       cout << s << endl;
       return;
    }

    for(int j = i;j < s.length();j++) {
        swap(s[i],s[j]);
        permute(i+1,s);
        swap(s[i],s[j]);
    }

}

int main() {

string s;
cin >> s;

permute(0,s);

return 0;
}