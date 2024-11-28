#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> dp(N, -1);
bool possible(int n, int ans)
{
    if (n == ans)
        return true;
    if (n < ans)
        return false;
    if (dp[ans] != -1)
        return dp[ans];
    return dp[ans] = possible(n, ans + 3) || possible(n, ans * 2);
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
        cin >> n;
        for (int i = 0; i <= n; i++)
            dp[i] = -1;
        if (possible(n, 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}