#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> parents(N, -1);
vector<int> groupSize(N, 1);

class Edge
{
public:
    int par, child, cost;
    Edge(int par, int child, int cost)
    {
        this->par = par;
        this->child = child;
        this->cost = cost;
    }
};

int dsuFind(int node)
{
    if (parents[node] == -1)
        return node;

    int leader = dsuFind(parents[node]);
    parents[node] = leader;
    return leader;
}

bool dsuUnion(int node1, int node2)
{
    int leader1 = dsuFind(node1);
    int leader2 = dsuFind(node2);

    if (leader1 == leader2)
        return false;
    if (groupSize[leader1] > groupSize[leader2])
    {
        parents[leader2] = leader1;
        groupSize[leader1] += groupSize[leader2];
    }
    else
    {
        parents[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
    }
    return true;
}

bool cmp(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    int i = e;
    while (i--)
    {
        int par, child, cost;
        cin >> par >> child >> cost;
        edges.push_back(Edge(par, child, cost));
    }

    sort(edges.begin(), edges.end(), cmp);

    int totalCost = 0;
    for (Edge ed: edges)
    {
        if (dsuUnion(ed.par, ed.child))
            totalCost += ed.cost;
    }

    cout << totalCost;

    return 0;
}