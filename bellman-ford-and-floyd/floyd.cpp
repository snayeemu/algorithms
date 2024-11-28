#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    ll matrix[numberOfNodes][numberOfNodes];

    for (int i = 0; i < numberOfNodes; i++)
        for (int j = 0; j < numberOfNodes; j++)
            if (i != j)
                matrix[i][j] = INT_MAX;
            else
                matrix[i][j] = 0;

    for (int i = 0; i < numberOfNodes; i++)
        for (int j = 0; j < numberOfNodes; j++)
        {
            int parent, child, cost;
            cin >> parent >> child >> cost;
            matrix[parent][child] = cost;
        }

    cout << "Before: " << endl;
    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
            if (matrix[i][j] == INT_MAX)
                cout << "Infinity ";
            else
                cout << matrix[i][j] << " ";
        cout << endl;
    }

    for (int k = 0; k < numberOfNodes; k++)
        for (int i = 0; i < numberOfNodes; i++)
            for (int j = 0; j < numberOfNodes; j++)
            {
                ll newDistance = matrix[i][k] + matrix[k][j];

                if (newDistance < matrix[i][j])
                    matrix[i][j] = newDistance;
            }

    // for (int i = 0; i < numberOfNodes; i++)
    //     for (int j = 0; j < numberOfNodes; j++)
    //         if (matrix[i][j] == INT_MAX)
    //             cout << i << " " << j << " Infinity" << endl;
    //         else
    //             cout << i << " " << j << " " << matrix[i][j] << endl;
    cout << "after: " << endl;
    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
            if (matrix[i][j] == INT_MAX)
                cout << "Infinity ";
            else
                cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}