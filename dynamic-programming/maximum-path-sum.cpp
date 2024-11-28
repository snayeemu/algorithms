#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int row, int col)
{
    return i < row && j < col && i >= 0 && j >= 0;
}

long long maximumPathSum(int i, int j, long long row, long long col, int matrix[][15], long long sum)
{
    if (i == row - 1 && j == col - 1)
        return sum;
    if (isValid(i + 1, j, row, col) && isValid(i, j + 1, row, col))
    {
        long long sum1 = maximumPathSum(i + 1, j, row, col, matrix, sum + matrix[i + 1][j]);
        long long sum2 = maximumPathSum(i, j + 1, row, col, matrix, sum + matrix[i][j + 1]);
        return max(sum1, sum2);
    }
    else if (isValid(i + 1, j, row, col))
        return maximumPathSum(i + 1, j, row, col, matrix, sum + matrix[i + 1][j]);
    else if (isValid(i, j + 1, row, col))
        return maximumPathSum(i, j + 1, row, col, matrix, sum + matrix[i][j + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long row, col;
    cin >> row >> col;

    int matrix[15][15];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];

    long long sum = matrix[0][0];
    cout << maximumPathSum(0, 0, row, col, matrix, sum) << endl;

    return 0;
}