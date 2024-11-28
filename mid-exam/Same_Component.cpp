#include <bits/stdc++.h>
using namespace std;

bool same = false;
vector<pair<int, int>> neighbors({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

bool isValid(int i, int j, int row, int col)
{
    return i < row && j < col && i >= 0 && j >= 0;
}

void isSame(int i1, int j1, int i2, int j2, int numberOfNodes, int numberOfEdges, char matrix[1000][1000], bool visited[1000][1000])
{
    visited[i1][j1] = true;

    if (i1 == i2 && j1 == j2)
    {
        same = true;
        return;
    }

    for (pair<int, int> p : neighbors)
    {
        int newChildI = i1 + p.first;
        int newChildJ = j1 + p.second;

        if (isValid(newChildI, newChildJ, numberOfNodes, numberOfEdges) && !visited[newChildI][newChildJ] && matrix[newChildI][newChildJ] == '.')
            isSame(newChildI, newChildJ, i2, j2, numberOfNodes, numberOfEdges, matrix, visited);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    bool visited[1000][1000] = {false};
    char matrix[1000][1000];

    for (int i = 0; i < numberOfNodes; i++)
        for (int j = 0; j < numberOfEdges; j++)
        {
            cin >> matrix[i][j];
        }

    int i1, j1;
    cin >> i1 >> j1;
    int i2, j2;
    cin >> i2 >> j2;

    isSame(i1, j1, i2, j2, numberOfNodes, numberOfEdges, matrix, visited);

    if (same)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}