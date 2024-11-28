#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int parent, child, cost;
    Edge(int parent, int child, int cost)
    {
        this->parent = parent;
        this->child = child;
        this->cost = cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    vector<Edge> edgeList;
    vector<int> dis(numberOfNodes, INT_MAX);
    dis[0] = 0;

    while (numberOfEdges--)
    {
        int parent, child, cost;
        cin >> parent >> child >> cost;
        edgeList.push_back(Edge(parent, child, cost)); 
    }

    for (int i = 0; i < numberOfNodes - 1; i++)
    {
        for (Edge ed : edgeList)
        {
            if (dis[ed.parent] < INT_MAX && dis[ed.parent] + ed.cost < dis[ed.child])
            {
                dis[ed.child] = dis[ed.parent] + ed.cost;
            }
        }
    }

    for (int i = 0; i < numberOfNodes; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}