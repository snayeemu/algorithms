#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isSurrounded;
    int numberOfSurroundedIslands = 0;

    bool isValid(int i, int j, int row, int col)
    {
        return i < row && j < col && i >= 0 && j >= 0;
    }

    void bfs(int pI, int pJ, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        isSurrounded = true;
        queue<pair<int, int>> q;
        q.push({
            pI,
            pJ,
        });
        visited[pI][pJ] = true;
        int row = grid.size();
        int col = grid[0].size();

        while (!q.empty())
        {
            pair<int, int> parent = q.front();
            pI = parent.first;
            pJ = parent.second;
            q.pop();

            for (pair<int, int> n : neighbors)
            {
                int nI = n.first;
                int nJ = n.second;
                int cI = pI + nI;
                int cJ = pJ + nJ;

                if (isValid(cI, cJ, row, col) && !visited[cI][cJ] && grid[cI][cJ] == 0)
                {
                    q.push({cI, cJ});
                    visited[cI][cJ] = true;
                }
                else if (!isValid(cI, cJ, row, col))
                    isSurrounded = false;
            }
        }

        if (isSurrounded)
            numberOfSurroundedIslands++;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (!visited[i][j] && grid[i][j] == 0)
                    bfs(i, j, grid, visited);

        return numberOfSurroundedIslands;
    }
};

int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};

    Solution sl;
    int closed = sl.closedIsland(grid);
    cout << closed << endl;

    return 0;
}