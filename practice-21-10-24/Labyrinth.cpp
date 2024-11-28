#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<vector<char>> matrix(N, vector<char>(N));
vector<vector<pair<int, int>>> par(N, vector<pair<int, int>>(N, {-1, -1}));
vector<vector<bool>> visited(N, vector<bool>(N, false));
vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


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
            if (isValid(cI, cJ, row, col) && !visited[cI][cJ] && (matrix[cI][cJ] == '.' || matrix[cI][cJ] == 'B'))
            {
                q.push({cI, cJ});
                visited[cI][cJ] = true;
                par[cI][cJ] = {pI, pJ};
                if (matrix[cI][cJ] == 'B')
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
            if (matrix[i][j] == 'A')
                source = {i, j};
            else if (matrix[i][j] == 'B')
                destination = {i, j};
        }

    bfs(row, col, source.first, source.second);

    if (visited[destination.first][destination.second])
    {
        cout << "YES" << endl;
        pair<int, int> current = destination;
        pair<int, int> invalid = {-1, -1};
        while (par[current.first][current.second] != invalid)
        {

            pair<int, int> prev = par[current.first][current.second];
            pair<int, int> newIndex = {current.first - prev.first, current.second - prev.second};

            if (newIndex == neighbors[0])
                path = "U" + path;
            else if (newIndex == neighbors[1])
                path = "D" + path;
            else if (newIndex == neighbors[2])
                path = "L" + path;
            else if (newIndex == neighbors[3])
                path = "R" + path;

            current = prev;
        }
        cout << path.size() << endl;
        cout << path << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}