#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea = 0;

    bool isValid(int i, int j, int row, int col)
    {
        return i < row && j < col && i >= 0 && j >= 0;
    }

    void bfs(pair<int, int> source, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        int row = grid.size(), col = grid[0].size();
        vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push(source);
        visited[source.first][source.second] = true;

        int area = 0;

        while (!q.empty())
        {
            area++;
            pair<int, int> parent = q.front();
            q.pop();

            int pI = parent.first;
            int pJ = parent.second;

            for (pair<int, int> n : neighbors)
            {
                int nI = n.first;
                int nJ = n.second;

                int childI = pI + nI;
                int childJ = pJ + nJ;

                if (isValid(childI, childJ, row, col) && !visited[childI][childJ] && grid[childI][childJ] == 1)
                {
                    q.push({childI, childJ});
                    visited[childI][childJ] = true;
                }
            }
        }

        if (area > maxArea)
            maxArea = area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                    bfs({i, j}, grid, visited);
            }

        return maxArea;
    }
};