#include<iostream>
#include<string>
using namespace std;

// print all possible combinations for keypad clicks

string keypad[9] = {"","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void combine(string num,string out,int i,int j) {
    
    if(i == num.length()) {
        cout << out <<endl;
        return;
    }

    int digit = num[i]-'0';

    for(int k = 0;k < keypad[digit].length();k++){
        combine(num,out+keypad[digit][k],i+1,j+1);
    }

    return;

}

int main() {

string num;
cin >> num;
combine(num,"",0,0);
return 0;
}