#include <bits/stdc++.h>
using namespace std;

int rows, cols;
bool visited[20][20];
char matrix[20][20];
int step[20][20];
vector<pair<int, int>> valuesToCalculateChilds = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return !(i < 0 || i >= rows || j < 0 || j >= cols);
}

void bfsOnMatrix(int sourceI, int sourceJ)
{
    queue<pair<int, int>> q;
    q.push({sourceI, sourceJ});
    step[sourceI][sourceJ] = 0;
    visited[sourceI][sourceJ] = true;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        cout << parent.first << " " << parent.second << endl;

        for (auto values : valuesToCalculateChilds)
        {
            int childI = parent.first + values.first;
            int childJ = parent.second + values.second;

            if (isValid(childI, childJ) && !visited[childI][childJ])
            {
                q.push({childI, childJ});
                visited[childI][childJ] = true;
                step[childI][childJ] = step[parent.first][parent.second] + 1;
            }
        }
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

    memset(step, -1, sizeof(step));
    memset(visited, false, sizeof(visited));
    bfsOnMatrix(sourceI, sourceJ);

    cout << step[2][3];

    return 0;
}