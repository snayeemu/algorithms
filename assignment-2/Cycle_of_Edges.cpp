#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> parents(N, -1);
vector<int> groupSize(N, 1);

class Edge
{
public:
    int par, child;
    Edge(int par, int child)
    {
        this->par = par;
        this->child = child;
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
        return true;
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
    return false;
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
        int par, child;
        cin >> par >> child;
        edges.push_back(Edge(par, child));
    }

    int numberOfEdgesCreatingLoop = 0;
    for (Edge ed : edges)
    {
        if (dsuUnion(ed.par, ed.child))
            numberOfEdgesCreatingLoop++;
    }

    cout << numberOfEdgesCreatingLoop;

    return 0;
}