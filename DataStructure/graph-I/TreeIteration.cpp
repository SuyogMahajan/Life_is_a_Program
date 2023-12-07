#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Node{

    public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }

};
// 9,3,4,#,#,1,#,#,2,#,6,#,#
Node* rec(int& i,string &s) {
    if(i >= s.length()) return NULL;
    if(s[i] == '#') {
        i+=2;
        return NULL;
    }
    int j = i;

    while(j < s.length() && s[j] != ','){
        j++;
    }

    Node* t = new Node(stoi(s.substr(i,j-i)));
    i = j+1;
    t->left = rec(i,s);
    t->right = rec(i,s);
    return t;
}

void preOrderTrav(Node* root) {

stack<Node*> stk;

while(1) {
    while(root) {
        cout << root->val <<" ";
        stk.push(root);
        root = root->left;
    }

    if(stk.empty()) break;
    root = stk.top();
    stk.pop();
    root = root -> right;
}

}

Node* buildTree(string s) {
    int i = 0;
    return rec(i,s);
}

void printTree(Node* root) {
    if(root == NULL) {cout <<"#";
    return;
    }
    cout << root->val ;
    printTree(root->left);
    printTree(root->right);
}

int main() {

    string s;
    cin >> s;

    Node* root = buildTree(s);
    preOrderTrav(root);
    cout << endl;
return 0;
}