#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int first, second;
    void make_pair(int first, int second)
    {
        this->first = first;
        this->second = second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Pair p;
    // p.make_pair(10, 20);
    // cout << p.first << " " << p.second << endl;

    pair<int, int> p(10, 20);

    p = make_pair(30, 40);

    cout << p.first << " " << p.second << endl;

    return 0;
}