#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first > p2.first;
    }
};

void dijkstra(int source, vector<pair<int, int>> adjacency[], vector<int> &dis)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({source, 0});
    dis[source] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.first;
        int parentDistance = parent.second;

        for (pair<int, int> child : adjacency[parentNode])
        {
            int childNode = child.first;
            int parentToChildDistance = child.second;
            int newDistance = parentDistance + parentToChildDistance;
            if (newDistance < dis[childNode])
            {
                dis[childNode] = newDistance;
                pq.push({childNode, newDistance});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numberOfNodes, source, destination;
    cin >> numberOfNodes >> source >> destination;

    vector<pair<int, int>> adjacency[numberOfNodes + 1];

    for (int i = 0; i < numberOfNodes; i++)
        for (int j = 0; j < numberOfNodes; j++)
        {

            int weight;
            cin >> weight;

            if (weight != -1)
                adjacency[i + 1].push_back({j + 1, weight});
        }

    vector<int> dis(numberOfNodes + 1, INT_MAX);

    dijkstra(source, adjacency, dis);

    for (int i = 0; i < numberOfNodes; i++) 
        if (dis[destination] == INT_MAX)
            dis[destination] = -1;

    cout << dis[destination];

    return 0;
}
