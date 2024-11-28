#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjacents[N];
bool visited[N];
int parents[N];

bool isCycle(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adjacents[parent])
        {
            if (visited[child] && parents[parent] != child)
                return true;

            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parents[child] = parent;
            }
        }
    }
    return false;
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