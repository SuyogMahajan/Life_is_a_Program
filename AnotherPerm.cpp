// 01. Another Permutation Problem

// Problem Statement
// Given an array nums contaming N hstinct integers ar an integer K. You can perform any marober of operations Select a sub-array of length K in nums and replace all the elements in the sub-array with the maximum number present in the current sub-array.
// Find the minimum number of operations such that All element of nums Maximum element in nums.

// Input format:
// The input consists of three lines:
// The first input line contains an integer Le N
// The second line contains N space-separated intogars denoting the array elements,
// The third line contains an integer Le K... The input will be read from the STDIN by the candidate.

// Output format:.

// Print the minimum number of operations required that All element of nums Maximum element in nums. The output will be matched to the candidate's output printed on the STDOUT.

// Constraints:

// 2sks NS 10"
// 1 ≤ nums[i] ≤ 10

// Example

// Input:
// 8
// 7 3 1 8 4 6 2 5
// 3

// Output:
// 4 Explanation:
// One of the possible ways is Operation on subarray 2 to 4.
// nums= (7, 8, 8, 8, 4, 6, 2, 5) nums (7, 8, 8, 8, 8, 8, 2, 5)
// Operation on subarray 4 to 6.
// Operation on subarray 6 to 8
// nums 7, 8, 8, 8, 8, 8, 8, 8) Operation on subarray 1 to 3,
// nams (8,8,8,8,8,8,8,81
// Sample input

// 4 2

// 0 2

// Sample Output
// 1

#include<iostream>
#include<vector>
using namespace std;

int findForI(int i,int mi,vector<int> v) {
    int ans = 0;

    

}

int solve(int n,int k,vector<int>& v) {

    int max_ele = 0;
    int max_index = -1;

    for(int i = 0;i< n;i++) {
        if(max_ele <= v[i]) {
            max_ele = v[i];
            max_index = i;
        }
    }
    int ans = n;

    for(int i = 0;i<k;i++) {
        ans = min(ans,findForI(i,max_index,v));    
    }

    return ans;
}


int main() {
    int n,k;
    cin >> n;

    vector<int> v(n);

    for(int i = 0;i<n;i++) {
        cin >> v[i];
    }

    cin >> k;

    cout << solve(n,k,v) << endl;

return 0;
}