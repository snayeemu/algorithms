#include <bits/stdc++.h>
using namespace std;

bool possible(long long int value, long long int init)
{
    if (value == init)
        return true;
    else if (value < init)
        return false;
    return possible(value, init * 10) || possible(value, init * 20);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        long long int value;
        cin >> value;
        if (possible(value, 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}