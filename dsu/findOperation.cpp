#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];

void dsi_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if (level[leader1] > level[leader2])
    {
        par[leader2] = leader1;
    }
    else if (level[leader1] < level[leader2])
    {
        par[leader1] = leader2;
    }
    else
    {
        par[leader1] = leader2;
        level[leader2]++;
    }
}

void dsu_union_by_level(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    par[leader1] = leader2;
}

void dsu_union_by_size(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    // par[leader1] = leader2;

    if (group_size[node1] > group_size[node2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dsi_initialize(7);

    dsu_union_by_level(1, 2); 
    dsu_union_by_level(2, 3);
    dsu_union_by_level(4, 5);
    dsu_union_by_level(1, 4);
    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}