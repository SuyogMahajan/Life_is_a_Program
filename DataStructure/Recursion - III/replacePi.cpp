#include<iostream>
#include<string>
using namespace std;

string replacePi(string s) {
    int len = s.length();

    if(len < 2) return s;

    if(s[0] == 'p' and s[1] == 'i') {
        return "3.14" + replacePi(s.substr(2));
    }
        return s[0] + replacePi(s.substr(1));
}

int main() {
    string s;
    cin >> s;

    string ans = replacePi(s);
    cout << ans << endl;

    return 0;
}