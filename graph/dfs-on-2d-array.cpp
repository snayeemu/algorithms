#include <bits/stdc++.h>
using namespace std;

int rows, cols;
bool visited[20][20];
char matrix[20][20];
vector<pair<int, int>> valuesToCalculateChilds = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return !(i < 0 || i >= rows || j < 0 || j >= cols);
}

void dfsOnMatrix(int sourceI, int sourceJ)
{
    visited[sourceI][sourceJ] = true;
    cout << sourceI << " " << sourceJ << endl;

    for (pair<int, int> values : valuesToCalculateChilds)
    {
        int childI = sourceI + values.first;
        int childJ = sourceJ + values.second;

        if (isValid(childI, childJ) && !visited[childI][childJ])
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
    cin >> sourceI >> sourceJ;

    memset(visited, false, sizeof(visited));
    dfsOnMatrix(sourceI, sourceJ);

    return 0;
}