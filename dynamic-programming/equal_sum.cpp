#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1005, vector<int>(1005, -1));

bool equal_sum(int n, int a[], int s)
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

    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 == 0 && equal_sum(n, a, sum / 2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}