#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    vector<vector<ll>> matrix(numberOfNodes, vector<ll>(numberOfNodes, LLONG_MAX));

    for (int i = 0; i < numberOfNodes; i++)
        matrix[i][i] = 0;

    while (numberOfEdges--)
    {
        ll parent, child, cost;
        cin >> parent >> child >> cost;
        parent -= 1;
        child -= 1;
        if (matrix[parent][child] > cost)
            matrix[parent][child] = cost;
    }

    for (int k = 0; k < numberOfNodes; k++)
        for (int i = 0; i < numberOfNodes; i++)
            for (int j = 0; j < numberOfNodes; j++)
            {
                if (matrix[i][k] != LLONG_MAX && matrix[k][j] != LLONG_MAX)
                {
                    ll newDistance = matrix[i][k] + matrix[k][j];

                    if (newDistance < matrix[i][j])
                        matrix[i][j] = newDistance;
                }
            }

    ll numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        ll source, destination;
        cin >> source >> destination;
        source -= 1;
        destination -= 1;

        // bool negativeCycle = false;
        // for (int i = 0; i < numberOfTestCases; i++)
        // {
        //     if (matrix[i][i] < 0)
        //     {
        //         negativeCycle = true;
        //         break;
        //     }
        // }

        if (matrix[source][destination] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << matrix[source][destination] << endl;
    }

    return 0;
}