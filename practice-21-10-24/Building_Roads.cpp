#include <bits/stdc++.h>
using namespace std;

const long long int n = 2 * 1e5 + 1;

vector<int> par(n, -1);

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_initialize(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
        par[leaderA] = leaderB;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> leaders;

    int numberOfNodes, edges;
    cin >> numberOfNodes >> edges;

    while (edges--)
    {
        int a, b;
        int parent6 = par[6];
        int parent8 = par[8];
        cin >> a >> b;
        dsu_initialize(a, b);
    }

    for (int i = 1; i <= numberOfNodes; i++)
    {
        int leader = dsu_find(i);
        int leadersSize = leaders.size();
        if (find(leaders.begin(), leaders.end(), leader) == leaders.end())
        {
            leaders.push_back(leader);
        }
    }

    cout << leaders.size() - 1 << endl;

    for (long long int i = 1; i < leaders.size(); i++)
        cout << leaders[0] << " " << leaders[i] << endl;

    return 0;
}