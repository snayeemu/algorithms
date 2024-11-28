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
    }

    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int source, destination;
        cin >> source >> destination;

        if (find(adjacencyList[source].begin(), adjacencyList[source].end(), destination) != adjacencyList[source].end() || source == destination)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}