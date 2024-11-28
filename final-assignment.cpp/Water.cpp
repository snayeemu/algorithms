#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int h[n];

        for (int i = 0; i < n; i++)
            cin >> h[i];

        int highest = h[0], secondHighest = INT_MIN, highestIndex = 0, secondHighestIndex;
        for (int i = 1; i < n; i++)
            if (h[i] > highest)
            {
                highest = h[i];
                highestIndex = i;
            }

        for (int i = 0; i < n; i++)
            if (h[i] > secondHighest && i != highestIndex)
            {
                secondHighest = h[i];
                secondHighestIndex = i;
            }
        if (highestIndex < secondHighestIndex)
            cout << highestIndex << " " << secondHighestIndex << endl;
        else
            cout << secondHighestIndex << " " << highestIndex << endl;
    }

    return 0;
}