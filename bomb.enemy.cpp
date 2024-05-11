#include <bits/stdc++.h>
using namespace std;

/*
   Given a 2D grid, each cell is either a wall "W", an enemy "E" or empty "0" (the number zero),
   return the maximum enemies you can kill using one bomb.
   The bomb kills all the enemies in the same row and column from the planted point until it hits the wall
   since the wall is too strong to be destroyed.
   Note: You can only put the bomb at an empty cell.
*/

// O(N^3)
int bombEnemy(vector<vector<string>> &grid)
{
    int rows = grid.size();
    if (rows == 0)
        return 0;
    int cols = grid[0].size();
    if (cols == 0)
        return 0;

    int maxCnt = INT_MIN;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == "0")
            {
                // check for all the rows
                int cnt = 0;
                for (int i = r; i < rows && grid[i][c] != "W"; i++)
                {
                    if (grid[i][c] == "E")
                        cnt++;
                }
                for (int i = r; i >= 0 && grid[i][c] != "W"; i--)
                {
                    if (grid[i][c] == "E")
                        cnt++;
                }
                for (int i = c; i < cols && grid[r][i] != "W"; i++)
                {
                    if (grid[r][i] == "E")
                        cnt++;
                }
                for (int i = c; i >= 0 && grid[r][i] != "W"; i--)
                {
                    if (grid[r][i] == "E")
                        cnt++;
                }
                // cout << r << " " << c << " " << cnt << endl;
                maxCnt = max(maxCnt, cnt);
            }
        }
    }
    return maxCnt;
}

// O(N^2)
int bombEnemyOptimised(vector<vector<string>> &grid)
{
    // here we will maintain the count previously so that we need to traverse again to count the enemies
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> killCount(rows, vector<int>(cols, 0));

    // for each row, we will count the enemies in the left direction
    for (int r = 0; r < rows; r++)
    {
        int cnt = 0;
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == "E")
                cnt++;
            if (grid[r][c] == "W")
                cnt = 0;
            killCount[r][c] += cnt;
        }
        cnt = 0;
        for (int c = cols - 1; c >= 0; c--)
        {
            if (grid[r][c] == "E")
                cnt++;
            if (grid[r][c] == "W")
                cnt = 0;
            killCount[r][c] += cnt;
        }
    }

    // for each column, we will count the enemies in the up direction
    for (int c = 0; c < cols; c++)
    {
        int cnt = 0;
        for (int r = 0; r < rows; r++)
        {
            if (grid[r][c] == "E")
                cnt++;
            if (grid[r][c] == "W")
                cnt = 0;
            killCount[r][c] += cnt;
        }
        cnt = 0;
        for (int r = rows - 1; r >= 0; r--)
        {
            if (grid[r][c] == "E")
                cnt++;
            if (grid[r][c] == "W")
                cnt = 0;
            killCount[r][c] += cnt;
        }
    }

    // now we have count matric , now only thing left is to calculate the max count
    int maxCnt = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == "0")
            {
                maxCnt = max(maxCnt, killCount[r][c]);
            }
        }
    }
    return maxCnt;
}