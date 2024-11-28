#include <bits/stdc++.h>
using namespace std;

int rows, cols;
bool visited[1005][1005];
char matrix[1005][1005];
vector<pair<int, int>> valuesToCalculateChilds = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool canGo = false;

bool isValid(int i, int j)
{
    return !(i < 0 || i >= rows || j < 0 || j >= cols);
}

void dfsOnMatrix(int sourceI, int sourceJ)
{
    if (matrix[sourceI][sourceJ] == 'B')
        canGo = true;

    visited[sourceI][sourceJ] = true;
    

    for (pair<int, int> values : valuesToCalculateChilds)
    {
        int childI = sourceI + values.first;
        int childJ = sourceJ + values.second;

        if (isValid(childI, childJ) && !visited[childI][childJ] and matrix[childI][childJ] != '#')
            dfsOnMatrix(childI, childJ);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            char ch;
            cin >> ch;
            matrix[i][j] = ch;
        }
    int sourceI, sourceJ;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] == 'A')
            {
                sourceI = i;
                sourceJ = j;
            }

    memset(visited, false, sizeof(visited));
    dfsOnMatrix(sourceI, sourceJ);

    cout << (canGo ? "YES" : "NO") << endl;

    return 0;
}