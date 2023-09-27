// You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.
// In one operation you can choose any subarray from initial and increment each value by one.
// Return the minimum number of operations to form a target array from initial.
// The test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: target = [1,2,3,2,1]
// Output: 3
// Explanation: We need at least 3 operations to form the target array from the initial array.
// [0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
// [1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
// [1,2,2,2,1] increment 1 at index 2.
// [1,2,3,2,1] target array is formed.

// Example 2:
// Input: target = [3,1,1,2]
// Output: 4
// Explanation: [0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2]

// Example 3:
// Input: target = [3,1,5,4,2]
// Output: 7
// Explanation: [0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2].

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

// O(n) optimised approach

    int minNumberOperations(vector<int> &target) {
        
        int n = target.size();
        int ans = 0;
        int temp = 0;
        
        for(int i = n-1;i >= 0;i--) {
            
            if(target[i] > temp) {
                ans += (target[i]-temp);
            }else if(target[i] == 0) {
                temp = 0;
                continue;
            }
            temp = target[i];
        }

        return ans;
    }
     
// Brute Force

    int minNumberOperations1(vector<int> &target)
    {

        int i = 0;
        int cnt = 0;

        while (i < target.size())
        {
            while (i < target.size() && target[i] == 0)
            {
                i++;
            }
            if (i < target.size())
            {
                cnt++;
                while (i < target.size() && target[i] != 0)
                {
                    i++;
                }
            }
        }

        for (i = 0; i < target.size(); i++)
        {
            if (target[i] != 0)
            {
                target[i]--;
            }
        }
        if (cnt == 0)
            return 0;

        return cnt + minNumberOperations1(target);
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    Solution s;
    cout << s.minNumberOperations(v) << endl;

    return 0;
}