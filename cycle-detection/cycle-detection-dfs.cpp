#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjacents[N];
bool visited[N];
int parents[N];

bool cycle = false;
bool isCycle(int source)
{
    visited[source] = true;

    for (int child : adjacents[source])
    {
        if (visited[child] && parents[source] != child)
            cycle = true;

        if (!visited[child])
        {
            parents[child] = source;
            isCycle(child);
        }
    }

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
        adjacents[secondNode].push_back(firstNode);
    }

    memset(visited, false, sizeof(visited));
    memset(parents, -1, sizeof(parents));

    cout << (isCycle(0) ? "Cycle" : "No Cycle");

    return 0;
}