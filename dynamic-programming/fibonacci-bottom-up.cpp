#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v;
    v.push_back(0);
    v.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        long long int fibo = v[i - 1] + v[i - 2];
        v.push_back(fibo);
    }

    cout << v[n];

    return 0;
}