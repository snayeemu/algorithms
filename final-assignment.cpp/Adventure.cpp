#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
vector<vector<int>> dp(N, vector<int>(N, -1));

int knapsack(int n, int weight[], int value[], int w, vector<vector<int>> &dp)
{
    if (n < 0 || w <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weight[n] <= w)
    {
        int opt1 = knapsack(n - 1, weight, value, w - weight[n], dp) + value[n];

        int opt2 = knapsack(n - 1, weight, value, w, dp);
        return dp[n][w] = max(opt1, opt2);
    }
    else
    {
        int opt2 = knapsack(n - 1, weight, value, w, dp);
        return dp[n][w] = opt2;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int w;
        cin >> n >> w;

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= w; j++)
                dp[i][j] = -1;
        int weight[n], value[n];
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> value[i];

        cout << knapsack(n - 1, weight, value, w, dp) << endl;
    }

    return 0;
}
