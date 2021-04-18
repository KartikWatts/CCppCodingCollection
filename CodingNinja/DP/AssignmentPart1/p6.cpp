#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minCount(int n)
{
    int res[n + 1];
    int squares[32];
    for (int i = 0; i < 32; i++)
    {
        squares[i] = (i + 1) * (i + 1);
    }

    res[1] = 1;
    int psn = 1;
    for (int i = 2; i <= n; i++)
    {
        res[i] = INT_MAX;
        if (i == squares[psn])
        {
            res[i] = 1;
            psn++;
            continue;
        }
        for (int j = 1; j <= i / 2; j++)
        {
            int temp = res[j] + res[i - j];
            if (temp < res[i])
            {
                res[i] = temp;
            }
        }
    }
    return res[n];
}

int main()
{
    int n;
    cin >> n;

    cout << minCount(n);
}