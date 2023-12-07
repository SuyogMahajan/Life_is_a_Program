#include<iostream>
using namespace std;

// generate all possible combinations of valid
// paranthesis having n pairs of brackets

void generateBracketRec(int i,int n,int open,int close,string till_now) {
    //  base case
    if(i == 2*n) {
        cout << till_now << endl;
        return;
    }

    // operations
    if(open < n) {
        generateBracketRec(i+1,n,open+1,close,till_now + "(");
    }
    
    if(open > close) {
        generateBracketRec(i+1,n,open,close+1,till_now+")");
    }

}

int main() {
  int n;
  cin >> n;

  generateBracketRec(0,n,0,0,"");

return 0;
}