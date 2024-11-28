#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numberOfNodes, numberOfEdges; cin >> numberOfNodes >> numberOfEdges;
    vector<pair<int, int>> edges;

    while(numberOfEdges--)
    {
        int firstNode, secondNode;  cin >> firstNode >> secondNode;
        edges.push_back({firstNode, secondNode});
    }
    cout << endl << endl << endl << endl;
    for(pair<int, int> edge: edges)
        cout << edge.first << " " << edge.second << endl;
    
    return 0;
}