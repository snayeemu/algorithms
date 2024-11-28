#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> parent(N, -1);
vector<int> group_size(N, 1);
bool cycle = false;

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if (leader1 == leader2)
    {
        // cout << "Cycle Detected!" << endl;
        cycle = true;
        return;
    }
    if (group_size[leader1] > group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
    }

    if (cycle)
        cout << "Cycle found!" << endl;
    else
        cout << "Cycle Not found!" << endl;

    return 0;
}