#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dis[N];
vector<pair<int, int>> adjacency[N];

class cmp{
    public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

void dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({source, 0});
    dis[source] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.top();
        int parentNode = parent.first;
        int parentWeight = parent.second;
        q.pop();

        for (pair<int, int> child : adjacency[parentNode])
        {
            int childNode = child.first;
            int childWeight = child.second;
            int newWeight = parentWeight + childWeight;

            if (newWeight < dis[childNode])
            {
                q.push({childNode, newWeight});
                dis[childNode] = newWeight;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    while (numberOfEdges--)
    {
        int firstNode, secondNode, weight;
        cin >> firstNode >> secondNode >> weight;
        adjacency[firstNode].push_back({secondNode, weight});
        adjacency[secondNode].push_back({firstNode, weight});
    }

    for (int i = 0; i < numberOfNodes; i++)
        dis[i] = INT_MAX;

    dijkstra(0);

    for (int i = 0; i < numberOfNodes; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}