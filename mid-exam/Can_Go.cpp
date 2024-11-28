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

    while (numberOfEdges--)
    {
        int parent, child, cost;
        cin >> parent >> child >> cost;
        matrix[parent - 1][child - 1] = cost;
    }

    for (int k = 0; k < numberOfNodes; k++)
        for (int i = 0; i < numberOfNodes; i++)
            for (int j = 0; j < numberOfNodes; j++)
            {
                ll newDistance = matrix[i][k] + matrix[k][j];

                if (newDistance < matrix[i][j])
                    matrix[i][j] = newDistance;
            }

    int source;
    cin >> source;
    int numberOfTestCases;
    cin >> numberOfTestCases;

        while (numberOfTestCases--)
    {
        int destination, destinationCost;
        cin >> destination >> destinationCost;

        if (matrix[source - 1][destination - 1] <= destinationCost)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}