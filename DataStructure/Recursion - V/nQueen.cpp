#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 51. N-Queens

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

void printAns(vector<vector<string>> ans) {
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            for(int k = 0;k < ans[i][j].length();k++)
             cout << ans[i][j][k] << " ";
             cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}

class Solution
{

    static bool checkPlusPositions(int i, int j, vector<string> board)
    {
        int n = board.size();
        // for (int k = j; k >= 0;k--)
        // {
        //     if (board[i][k] == 'Q')
        //         return false;
        // }

        for (int k = i; k >= 0; k--)
        {
            if (board[k][j] == 'Q')
                return false;
        }

        return true;
    }

    static bool checkCrossPositions(int row, int column, vector<string> board)
    {

        int n = board.size();

        int i = row, j = column;
        while (i >= 0 && j >= 0)
        {
            if (board[i--][j--] == 'Q')
            {
                return false;
            }
        }
        i = row;
        j = column;

        while (i >= 0 && j < n)
        {
            if (board[i--][j++] == 'Q')
            {
                return false;
            }
        }
        // i = row;
        // j = column;
        // while (i < n && j >= 0)
        // {
        //     if (board[i++][j--] == 'Q')
        //     {
        //         return false;
        //     }
        // }
        // i = row;
        // j = column;
        // while (i < n && j < n)
        // {
        //     if (board[i++][j++] == 'Q')
        //     {
        //         return false;
        //     }
        // }

        return true;
    }

public:
    void nQueenBacktrack(int i, int j, int queensPlaced, vector<string> board, vector<vector<string>> &ans)
    {
        int n = board.size();

        if (queensPlaced == n)
        {
            ans.push_back(board);
            // printAns(ans);
            return;
        }
        if (i >= n or j >= n) {
          return;
        }
         
        int nexti = i, nextj = j + 1;

        if (checkPlusPositions(i, j, board) and checkCrossPositions(i, j, board)){
            board[i][j] = 'Q';
            nQueenBacktrack(i+1, 0, queensPlaced + 1, board, ans);
            board[i][j] = '.';
        }
        
        nQueenBacktrack(i, j+1, queensPlaced, board, ans);
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> t(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueenBacktrack(0, 0, 0, t, ans);
        return ans;
    }
};



int main()
{
    int n;
    cin >> n;

    Solution s;

    vector<vector<string>> ans = s.solveNQueens(n);
    printAns(ans);    

    return 0;
}