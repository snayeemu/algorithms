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

void dfsOnMatrix(int sourceI, int sourceJ, int &numberOfRooms)
{
    numberOfRooms++;

    visited[sourceI][sourceJ] = true;

    for (pair<int, int> values : valuesToCalculateChilds)
    {
        int childI = sourceI + values.first;
        int childJ = sourceJ + values.second;

        if (isValid(childI, childJ) && !visited[childI][childJ] and matrix[childI][childJ] != '#')
            dfsOnMatrix(childI, childJ, numberOfRooms);
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

    memset(visited, false, sizeof(visited));

    int numberOfApartments = 0;
    vector<int> numberOfRoomsCollection;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            if (visited[i][j] == false && matrix[i][j] != '#')
            {
                int numberOfRooms = 0;
                dfsOnMatrix(i, j, numberOfRooms);
                numberOfApartments++;
                numberOfRoomsCollection.push_back(numberOfRooms);
            }
        }
    sort(numberOfRoomsCollection.begin(), numberOfRoomsCollection.end());
    if (numberOfApartments == 0)
        cout << numberOfApartments;
    else
        for (int numberOfRooms : numberOfRoomsCollection)
            cout << numberOfRooms << " ";

    return 0;
}