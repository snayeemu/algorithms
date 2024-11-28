#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;
    int matrix[nodes][nodes];

    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < edges; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        matrix[firstNode][secondNode] = 1;
        matrix[secondNode][firstNode] = 1;
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}