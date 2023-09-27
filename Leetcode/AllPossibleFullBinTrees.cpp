
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {

        vector<TreeNode *> ans;
        if (n % 2 == 0)
            return ans;
        // big tree on right small one on left
        if (n == 1)
        {
            ans.push_back(new TreeNode());
            return ans;
        }

        n--;
        int i = 1;
        vector<TreeNode *> t1;
        vector<TreeNode *> t2;

        while (i < n)
        {

            t1 = allPossibleFBT(i);
            t2 = allPossibleFBT(n - i);

            for (int j = 0; j < t1.size(); j++)
            {
                for (int k = 0; k < t2.size(); k++)
                {
                    TreeNode *t = new TreeNode();
                    t->left = t1[j];
                    t->right = t2[k];
                    ans.push_back(t);
                }
            }

            i += 2;
        }

        return ans;
    }

};

void printTreen(TreeNode* t) {

    if(t == NULL ) {cout << "NULL "; return;}
    cout << t->val <<" ";
    printTreen(t->left);
    printTreen(t->right);

}

int main() {
    int n;
    cin >> n;
    Solution s;
    vector<TreeNode*> ans = s.allPossibleFBT(n);

    for(auto x:ans) {
        cout <<"[";
        printTreen(x);
        cout <<"]"<< endl;
    }

    return 0;
}