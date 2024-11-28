#include <bits/stdc++.h>
using namespace std;

int steps = 0;
vector<pair<int, int>> neighbors({{-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}});

bool isValid(int i, int j, int row, int col) { return i < row && i >= 0 && j < col && j >= 0; }

void isPossibleToReach(int Ki, int Kj, int Qi, int Qj, int numberOfNodes, int numberOfEdges, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({Ki, Kj});
    visited[Ki][Kj] = true;
    bool matched = false;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> parent = q.front();
            q.pop();

            int parentI = parent.first;
            int parentJ = parent.second;

            if (parentI == Qi && parentJ == Qj)
            {
                matched = true;
                break;
            }

            for (pair<int, int> p : neighbors)
            {
                int childI = parentI + p.first;
                int childJ = parentJ + p.second;
                if (isValid(childI, childJ, numberOfNodes, numberOfEdges) && !visited[childI][childJ])
                {
                    q.push({childI, childJ});
                    visited[childI][childJ] = true;
                }
            }
        }
        if (matched)
        {
            break;
        }
        else if (!q.empty())
            steps++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        int numberOfNodes, numberOfEdges;
        cin >> numberOfNodes >> numberOfEdges;

        vector<vector<bool>> visited(numberOfNodes, vector<bool>(numberOfEdges, false));

        int Ki, Kj;
        cin >> Ki >> Kj;
        int Qi, Qj;
        cin >> Qi >> Qj;

        steps = 0;
        isPossibleToReach(Ki, Kj, Qi, Qj, numberOfNodes, numberOfEdges, visited);

        if (visited[Qi][Qj])
            cout << steps << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}