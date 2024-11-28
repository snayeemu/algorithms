#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numberOfIslands = 0;

    bool isValid(int i, int j, int row, int col)
    {
        return i < row && j < col && i >= 0 && j >= 0;
    }

    void dfs(pair<int, int> source, int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        int pI = source.first;
        int pJ = source.second;
        visited[pI][pJ] = true;

        for (pair<int, int> n : neighbors)
        {
            int cI = pI + n.first;
            int cJ = pJ + n.second;

            if (isValid(cI, cJ, row, col) && grid[cI][cJ] == '1' && !visited[cI][cJ])
                dfs({cI, cJ}, row, col, grid, visited);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs({i, j}, row, col, grid, visited);
                    numberOfIslands++;
                }
        return numberOfIslands;
    }
};