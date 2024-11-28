#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;
        vector<int> adj[n];

        for (vector<int> edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();

            for (int child : adj[parent])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        return visited[destination];
    }
};