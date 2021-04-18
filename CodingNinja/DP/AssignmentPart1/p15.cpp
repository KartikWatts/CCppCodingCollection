//MAX SUM SUBRECTANGLE

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int kadaneSum(int a[], int size)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
        if ((sum > maxSum))
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int maxSum = INT_MIN;
    for (int L = 0; L < m; L++)
    {
        int subArr[n];
        for (int i = 0; i < n; i++)
        {
            subArr[i] = 0;
        }

        for (int R = L; R < m; R++)
        {
            for (int row = 0; row < n; row++)
            {
                subArr[row] += a[row][R];
            }
            int tempSum = kadaneSum(subArr, n);
            if (tempSum > maxSum)
            {
                maxSum = tempSum;
            }
        }
    }
    cout << maxSum;
    return 0;
}