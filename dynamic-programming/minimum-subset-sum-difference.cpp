#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    bool dp[n + 1][sum + 1];
    dp[0][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];

    vector<int> v;

    for (int i = 0; i <= sum; i++)
        if (dp[n][i])
            v.push_back(i);

    int ans = INT_MAX;
    int minDifference = sum / 2;
    for (int val : v)
    {
        // int difference = abs(sum / 2 - val);
        // if (minDifference > difference)
        // {
        //     ans = val;
        //     minDifference = difference;
        // }
        int difference = abs(sum - 2*val);
        ans = min(ans, difference);
    }

    // cout << sum - ans - ans << endl;
    cout << ans << endl;

    return 0;
}