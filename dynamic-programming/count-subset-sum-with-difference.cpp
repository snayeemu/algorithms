#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1005, vector<int>(1005, -1));

int subset_sum(int n, int a[], int s)
{
    if (s == 0)
        return 1;
    else if (s < 0 || n <= 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    int opt1 = subset_sum(n - 1, a, s - a[n - 1]);
    int opt2 = subset_sum(n - 1, a, s);
    return dp[n][s] = opt1 + opt2;
}
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
    int difference;
    cin >> difference;

    int s1 = (difference + sum) / 2;

    int dp[n + 1][sum + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= s1; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s1; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }

    cout << dp[n][s1] << endl;
    return 0;
}