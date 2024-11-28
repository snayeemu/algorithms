#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<vector<bool>> visited(N, vector<bool>(N, false));
vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int minimumArea = INT_MAX;

bool isValid(int i, int j, int row, int col)
{
    return i < row && j < col && i >= 0 && j >= 0;
}

void bfs(int i, int j, int row, int col, char matrix[][1005])
{
    int area = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    area++;
    visited[i][j] = true;

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

            if (isValid(cI, cJ, row, col) && !visited[cI][cJ] && matrix[cI][cJ] == '.')
            {
                q.push({cI, cJ});
                visited[cI][cJ] = true;
                area++;
            }
        }
    }

    if (minimumArea > area)
        minimumArea = area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;
    char matrix[1005][1005];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!visited[i][j] && matrix[i][j] == '.')
                bfs(i, j, row, col, matrix);

    if (minimumArea != INT_MAX)
        cout << minimumArea;
    else
        cout << -1;

    return 0;
}