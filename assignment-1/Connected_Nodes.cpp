#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacencyList[1005];
int level[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    for (int i = 0; i < numberOfEdges; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int source;
        cin >> source;

        sort(adjacencyList[source].begin(), adjacencyList[source].end(), greater<int>());

        for (int value : adjacencyList[source])
            cout << value << " ";
        if (adjacencyList[source].empty())
            cout << -1;
        cout << endl;
    }

    return 0;
}