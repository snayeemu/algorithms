#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp(1005, vector<long long>(1005, -1));

bool equal_sum(long long n, long long a[], long long s)
{
    if (s == 0)
        return true;
    else if (s < 0 || n <= 0)
        return false;
    if (dp[n][s] != -1)
        return dp[n][s];
    bool opt1 = equal_sum(n - 1, a, s - a[n - 1]);
    bool opt2 = equal_sum(n - 1, a, s);
    return dp[n][s] = opt1 || opt2;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int s = 1000 - m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum = s;
        bool dp[n + 1][sum + 1];
        dp[0][0] = true;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][sum])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
