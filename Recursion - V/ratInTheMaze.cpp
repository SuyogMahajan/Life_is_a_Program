#include <iostream>
using namespace std;

// given a 2d matrix which will act as maze , we have to reach end from the start
// output total number of ways.

bool solveTheMaze(int i, int j, int maze[][100], int sol[][100], int n, int m)
{

    if (i >= n or j >= m)
        return false;

    if(i == n-1 and j == m-1) {
        sol[i][j] = 1;    
        return true;
    }

    if(maze[i][j] == -1) return false;

    sol[i][j] = 1;
    bool a = solveTheMaze(i,j+1,maze,sol,n,m);
    bool b = solveTheMaze(i+1,j,maze,sol,n,m);

    if(!(a or b))
     sol[i][j] = 0;
    
    return a or b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int maze[n][100];
    int sol[n][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            sol[i][j] = 0;
        }
    }
    cout << solveTheMaze(0, 0, maze, sol, n, m) << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}