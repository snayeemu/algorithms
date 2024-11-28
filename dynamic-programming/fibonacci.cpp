#include <bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;
vector<long long int> memo(n, -1);

long long int fibo(int number)
{
    if (memo[number] != -1)
        return memo[number];

    memo[number] = fibo(number - 1) + fibo(number - 2);
    return memo[number];
}

// long long int fibo(int number)
// {
//     if (number == 0 || number == 1)
//         return number;

//     if (memo[number] != -1)
//         return memo[number];

//     memo[number] = fibo(number - 1) + fibo(number - 2);
//     return memo[number];
// }

int main()
{
    int number;
    cin >> number;
    memo[0] = 0;
    memo[1] = 1;

    cout << fibo(number);

    return 0;
}