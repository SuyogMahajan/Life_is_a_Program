#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Input: board =

// 5 3 . . 7 . . . .
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . 2 8 .
// . . . 4 1 9 . . 5
// . . . . 8 . . 7 9

// Output:
// 5 3 4 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// 1 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 9 1
// 7 1 3 9 2 4 8 5 6
// 9 6 1 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9

class Solution
{

    static pair<int, int> findStartPointOfBlock(int i, int j)
    {

        pair<int, int> p = make_pair((i / 3) * 3, (j / 3) * 3);
        return p;
    }

    static bool checkBox(vector<vector<char>> &board, int ci, int cj, char target)
    {
        pair<int,int> p = findStartPointOfBlock(ci,cj);
        int si = p.first;
        int sj = p.second;
        
        for (int i = si; i <= si + 2; i++)
        {
            for (int j = sj; j <= sj + 2; j++)
            {
                if (board[i][j] == target)
                    return false;
            }
        }

        return true;
    }

    static bool checkRow(vector<vector<char>> &board, int row, char target)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == target)
                return false;
        }

        return true;
    }

    static bool checkColumn(vector<vector<char>> &board, int column, char target)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][column] == target)
                return false;
        }

        return true;
    }

public:
    bool solveSudokuBacktrack(int i, int j, vector<vector<char>> &board)
    {
         if (i == 9 and j == 0)
            return true;

        if (i >= 9 or j >= 9)
            return false;

       
        if (board[i][j] == '.')
        {

            for (int k = 1; k <= 9; k++)
            {
                bool isInBox = checkBox(board, i, j, ('0' + k));
                if (!isInBox)
                    continue;

                bool isInRow = checkRow(board, i, ('0' + k));
                if (!isInRow)
                    continue;

                bool isInCol = checkColumn(board, j, ('0' + k));
                if (!isInCol)
                    continue;

                board[i][j] = ('0' + k);
                bool ans = false;
                if (j + 1 == 9)
                {
                    ans = solveSudokuBacktrack(i + 1, 0, board);
                }
                else
                {
                    ans = solveSudokuBacktrack(i, j + 1, board);
                }

                if (ans)
                    return true;

            }

            board[i][j] = '.';
            return false;
        }
        if (j + 1 == 9)
        {
            return solveSudokuBacktrack(i + 1, 0, board);
        }

        return solveSudokuBacktrack(i, j + 1, board);
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        bool ans = solveSudokuBacktrack(0,0,board);

        if(ans) {
            cout << endl;

            for(int i = 0;i<9;i++) {
                for(int j = 0;j<9;j++) {
                    cout << board[i][j] <<" ";
                }
                cout << endl;
            }
        }else{
            cout << "No Solution" << endl;
        }
    }
};

int main()
{

    vector<vector<char>> board(9, vector<char>(9));

    for(int i= 0;i<9;i++) {
        for(int j = 0;j<9;j++) {
            cin >> board[i][j];
        }
    }

    Solution s;
    s.solveSudoku(board);

    return 0;
}
