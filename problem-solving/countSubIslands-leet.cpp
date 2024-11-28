#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isMatched = true;
    int numberOfMatchedIslands = 0;

    bool isValid(int i, int j, int row, int col)
    {
        return i < row && j < col && i >= 0 && j >= 0;
    }

    void bfs(pair<int, int> source, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited)
    {
        isMatched = true;
        int row = grid2.size();
        int col = grid2[0].size();

        queue<pair<int, int>> q;
        q.push(source);
        visited[source.first][source.second] = true;

        if (grid2[source.first][source.second] != grid1[source.first][source.second])
        {
            isMatched = false;
        }

        while (!q.empty())
        {
            pair<int, int> parent = q.front();
            q.pop();
            int pI = parent.first;
            int pJ = parent.second;

            for (pair<int, int> n : neighbors)
            {
                int nI = n.first;
                int nJ = n.second;
                int cI = pI + nI;
                int cJ = pJ + nJ;

                if (isValid(cI, cJ, row, col) && !visited[cI][cJ] && grid2[cI][cJ] == 1)
                    if (grid1[cI][cJ] != grid2[cI][cJ])
                    {
                        isMatched = false;
                    }
                    else
                    {
                        q.push({cI, cJ});
                        visited[cI][cJ] = true;
                    }
            }
        }

        if (isMatched)
            numberOfMatchedIslands++;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int row = grid2.size();
        int col = grid2[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid2[i][j] == 1 && !visited[i][j])
                {
                    bfs({i, j}, grid1, grid2, visited);
                }

        return numberOfMatchedIslands;
    }
};