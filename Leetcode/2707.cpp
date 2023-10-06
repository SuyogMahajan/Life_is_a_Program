#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    class TrieNode {
        public:
        char c;
        // unordered_map<char,TrieNode*> nexts;
        TrieNode* nexts[26];
        bool isEnd;

        TrieNode(char c,bool e) {
            this->c = c;
            for(int i = 0;i <26;i++) {
                nexts[i] = NULL;
            }
            isEnd = e;
        }        

    };

    string str;
    vector<string> dic;
    TrieNode* origin;

    void insertInTrie(TrieNode* root,string s) {
        TrieNode* t = root;
        for(int i = 0;i < s.length();i++) {
            TrieNode* k; 
            if(t->nexts[s[i]-'a']) {
                k = t->nexts[s[i]-'a'];
                if(i == (s.length()-1)) k->isEnd = true;

            }else{
                k = new TrieNode(s[i],i == (s.length()-1));
            }
            t->nexts[s[i]-'a'] = k;
            t = t->nexts[s[i]-'a']; 
        }

    }

    void printTrie(TrieNode* root) {
        cout << root->c ;
        if(root->isEnd) cout <<"*";
        cout <<"->";

        for(int i = 0; i < 26;i++) {
            if(root->nexts[i]) 
            printTrie(root->nexts[i]);
        }
    }

    // leetscode
    // sayhelloworld

    int findMinExtraChar(string s,TrieNode* root) {
        TrieNode* t = root;
        int i = 0;
        int n = s.length();
        int ans = 0;
        int temp = 0;

        while(i < n) {
            temp++;
            cout << i <<" "<<temp<< endl;
            
            if(t->nexts[s[i]-'a']) {
                t = t->nexts[s[i]-'a'];
                if(t->isEnd) {
                    temp = 0;
                    t = root;
                }
    
            }else{
                ans += temp;
                temp = 0;
                t = root;
            }
            
            i++;
        }

        return ans;
    }

    int findMinExtraChar(int i,int till,string s,TrieNode* root){
        if(i >= s.length()) return till;

        int ans = s.length();
        
       

        if(origin->nexts[s[i]-'a']) {
            ans = findMinExtraChar(i+1,1,s,origin->nexts[s[i]-'a']);
        }

        if(root->nexts[s[i]-'a']) {
             till++;
        if(root->nexts[s[i]-'a']->isEnd ) {
            till = 0;
        }
            return min(ans,findMinExtraChar(i+1,till,s,root->nexts[s[i]-'a']));
        }
            return till + findMinExtraChar(i+1,0,s,origin);
        

        // ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
      
        // base case if i >= n
        // return till

        // if we are at end of a word
        // make till 0 

        // new matching string starts here
        // make call to origin will till as 0

        // we are currently between a string
        // increament till make call to next node

        // nothing matches
        // add everything up
        // make call to origin with till as 0

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode('0',false);

        for(auto x:dictionary) {
            insertInTrie(root,x);
        }
        origin = root;
        str = s;
        dic = dictionary;
        return findMinExtraChar(0,0,s,root);
    }
};

int main() {

string s;
vector<string> k;
cin >> s;
int n;
cin >> n;

for(int i = 0;i<n;i++) {
    string  x;
    cin >> x;
    k.push_back(x);
}

Solution* sol = new Solution();
cout << sol->minExtraChar(s,k)<< endl;

return 0;
}