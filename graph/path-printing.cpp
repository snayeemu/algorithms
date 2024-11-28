#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacencyList[1005];
int level[1005];
int parent[1005];

void bfs(int source, int destination)
{
    queue<int> nodes;
    nodes.push(source);
    visited[source] = true;
    level[source] = 0;

    cout << endl
         << endl
         << endl
         << endl;
    while (!nodes.empty())
    {
        int par = nodes.front();
        nodes.pop();

        for (int child : adjacencyList[par])
            if (!visited[child])
            {
                nodes.push(child);
                visited[child] = true;
                parent[child] = par;
                level[child] = level[par] + 1;
            }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < numberOfEdges; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    int source, destination;
    cin >> source >> destination;

    bfs(source, destination);

    int current = destination;
    stack<int> path;
    

    while (current != -1)
    {
        path.push(current);
        current = parent[current];
    }

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }

    return 0;
}