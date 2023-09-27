// An array arr a mountain if the following properties hold:
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
// You must solve it in O(log(arr.length)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int s = 0, e = n - 1;

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1])
            {
                return m;
            }
            if (arr[m] < arr[m - 1])
            {
                e = m;
            }
            if (arr[m] < arr[m + 1])
            {
                s = m;
            }
        }

        return -1;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0;i<n;i++) {
        cin >> v[i];
    }
    Solution s;
    cout << s.peakIndexInMountainArray(v) << endl;
    return 0;
}