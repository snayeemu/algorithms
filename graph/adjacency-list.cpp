#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numberOfNodes, numberOfEdges; cin >> numberOfNodes >> numberOfEdges;
    vector<int> adjacent[6];

    while(numberOfEdges--)
    {
        int a, b; cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a); 
    }

    for(int node: adjacent[0]) cout << node << " ";
    
    return 0;
}