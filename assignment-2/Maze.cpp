#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<vector<char>> matrix(N, vector<char>(N));
vector<vector<pair<int, int>>> par(N, vector<pair<int, int>>(N, {-1, -1}));
vector<vector<bool>> visited(N, vector<bool>(N, false));
vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j, int row, int col)
{
    return i < row && j < col && i >= 0 && j >= 0;
}

void bfs(int row, int col, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
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
            if (isValid(cI, cJ, row, col) && !visited[cI][cJ] && (matrix[cI][cJ] == '.' || matrix[cI][cJ] == 'D'))
            {
                q.push({cI, cJ});
                visited[cI][cJ] = true;
                par[cI][cJ] = {pI, pJ};
                if (matrix[cI][cJ] == 'D')
                    return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;

    pair<int, int> source;
    pair<int, int> destination;
    string path = "";

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'R')
                source = {i, j};
            else if (matrix[i][j] == 'D')
                destination = {i, j};
        }

    bfs(row, col, source.first, source.second);

    if (visited[destination.first][destination.second])
    {
        // cout << "YES" << endl;
        pair<int, int> current = destination;
        // pair<int, int> invalid = {-1, -1};
        while (true)
        {

            pair<int, int> prev = par[current.first][current.second];
            char currentValue = matrix[prev.first][prev.second];
            if (matrix[prev.first][prev.second] == 'R')
                break;
            matrix[prev.first][prev.second] = 'X';
            current = prev;
        }
        // cout << path.size() << endl;
        // cout << path << endl;
    }
    // else
    //     cout << "NO" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j];
        cout << endl;
    }

    return 0;
}