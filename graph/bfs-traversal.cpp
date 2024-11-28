#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacencyList[1005];
int level[1005];

void bfs(int source)
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
        int front = nodes.front();
        nodes.pop();

        cout << level[front] << ": " << front << endl;

        for (int node : adjacencyList[front])
            if (!visited[node])
            {
                nodes.push(node);
                visited[node] = true;
                level[node] = level[front] + 1;
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

    for (int i = 0; i < numberOfEdges; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        adjacencyList[firstNode].push_back(secondNode);
        adjacencyList[secondNode].push_back(firstNode);
    }

    int source;
    cin >> source;

    bfs(source);

    return 0;
}