#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjacents[N];
bool visited[N];
bool pathVisited[N];

bool cycle = false;
bool isCycle(int source)
{
    visited[source] = true;
    pathVisited[source] = true;

    for (int child : adjacents[source])
    {
        if (pathVisited[child])
            cycle = true;
        if (!visited[child])
            isCycle(child);
    }

    pathVisited[source] = false;

    return cycle;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    while (numberOfEdges--)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        adjacents[firstNode].push_back(secondNode);
    }

    cycle = false;
    memset(visited, false, sizeof(visited));
    memset(pathVisited, false, sizeof(pathVisited));

    for (int i = 0; i < numberOfNodes; i++)
        for (int child : adjacents[i])
            if (!visited[child])
                isCycle(child);

    cout << (cycle ? "Cycle" : "No Cycle");

    return 0;
}