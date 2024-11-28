#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Edge
{
public:
    ll parent, child, cost;
    Edge(ll parent, ll child, ll cost)
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

    ll n, e;
    cin >> n >> e;

    vector<Edge> edges;
    vector<ll> dis(n, LLONG_MAX);

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a -= 1;
        b -= 1;

        Edge edg(a, b, c);
        edges.push_back(edg);
    }

    ll source;
    cin >> source;
    source -= 1;
    dis[source] = 0;
    ll numberOfTestCases;
    cin >> numberOfTestCases;

    for (ll i = 0; i < n - 1; i++)
    {
        for (Edge edg : edges)
        {
            ll parentDis = dis[edg.parent];
            ll childDis = dis[edg.child];
            if (parentDis < LLONG_MAX && parentDis + edg.cost < childDis)
            {
                ll newDis = dis[edg.parent] + edg.cost;
                dis[edg.child] = newDis;
            }
        }
    }

    bool negativeCycle = false;

    for (Edge edg : edges)
    {
        ll parentDis = dis[edg.parent];
        ll childDis = dis[edg.child];
        if (parentDis < LLONG_MAX && parentDis + edg.cost < childDis)
        {
            negativeCycle = true;
            break;
        }
    }

    while (numberOfTestCases--)
    {
        ll destination;
        cin >> destination;
        destination -= 1;
        if (negativeCycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (dis[destination] < LLONG_MAX)
            cout << dis[destination] << endl;
        else
            cout << "Not Possible" << endl;
    }

    return 0;
}