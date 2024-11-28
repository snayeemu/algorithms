#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjacencyList[N];
bool visited[N];

void dfs(int source)
{
    visited[source] = true;

    cout << source << endl;

    for (int child : adjacencyList[source])
        if (!visited[child])
            dfs(child);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    memset(visited, false, sizeof(visited));

    while (numberOfEdges--)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    dfs(0);

    return 0;
}