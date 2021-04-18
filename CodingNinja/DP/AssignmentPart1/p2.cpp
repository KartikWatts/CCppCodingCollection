//MAX SUM SUBRECTANGLE

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findZeroes(int a[], int size)
{
    int maxZeroes = 0;
    int list = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 0)
        {
            list++;
        }
        else
        {
            list = 0;
        }
        if (list > maxZeroes)
        {
            maxZeroes = list;
        }
    }
    return maxZeroes;
}

int findMaxSquareWithAllZeros(int **a, int n, int m)
{
    int maxZeroes = 0;
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
                if (a[row][R] == 1)
                {
                    subArr[row] = 1;
                }
            }
            int tempZeroes = min(findZeroes(subArr, n), R - L + 1);
            // tempZeroes = tempZeroes * (R - L + 1);
            if (tempZeroes > maxZeroes)
            {
                maxZeroes = tempZeroes;
            }
        }
    }
    return maxZeroes;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **a;
    a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(a, n, m);
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }

    delete[] a;

    return 0;
}