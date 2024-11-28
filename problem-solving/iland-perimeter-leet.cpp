#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int i, int j, int row, int col)
    {
        return i < row && j < col && i >= 0 && j >= 0;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int perimeter = 0;
        vector<pair<int, int>> neighbors = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    break;
                }

        while (!q.empty())
        {
            pair<int, int> parent = q.front();
            q.pop();

            int parentI = parent.first;
            int parentJ = parent.second;

            for (pair<int, int> n : neighbors)
            {
                int nI = n.first;
                int nJ = n.second;

                int newI = parentI + nI;
                int newJ = parentJ + nJ;

                if (!isValid(newI, newJ, row, col) || (isValid(newI, newJ, row, col) && grid[newI][newJ] == 0))
                    perimeter++;
                else if (isValid(newI, newJ, row, col) && grid[newI][newJ] == 1 && !visited[newI][newJ])
                {
                    q.push({newI, newJ});
                    visited[newI][newJ] = true;
                }
            }
        }

        return perimeter;
    }
};
