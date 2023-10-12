#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
    string multiply(string num1, string num2)
    {
        int n = num1.length(), m = num2.length();

        if(num1 == "0" || num2 == "0") return "0";

        string ans = "";
        int k_start = 0,k = 0,ans_len = 0;

        for(int i = n-1; i >= 0;i--) {
            char c = num1[i];
            int carry = 0;
            k = k_start;

            for(int j = m-1;j >= 0;j--) {

                char t = num2[j];
                int multy = (t-'0')*(c-'0');
                multy += carry;
                
                if(ans_len <= k) {
                    
                    ans += string(1,('0' + (multy%10)));
                    ans_len++;

                }else{
                    multy += (ans[k]-'0');
                    ans[k] = ('0' + (multy%10));
                }

                k++;
                multy /= 10;         
                carry = multy;
            }

            while(carry) {
                ans += string(1,('0' + (carry%10)));
                carry /= 10;
                ans_len++;
            }

            k_start++;
        }

        reverse(ans.begin(),ans.end());

    return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
    string a,b;
    cin >> a>> b;
    cout << sol->multiply(a,b) << endl;
    return 0;
}