#include <bits/stdc++.h>
using namespace std;

int lcs(int *X, int *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

void decToBinary(int n)
{
    int bNum[32];

    int i = 0;
    while (n > 0)
    {
        bNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << bNum[j];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int X[n], Y[m];
        string xStr, yStr;
        for (int i = 0; i < n; i++)
        {
            cin >> X[i];
        }

        cin >> xStr;

        for (int i = 0; i < m; i++)
        {
            cin >> Y[i];
        }

        cin >> yStr;

        int pos = lcs(X, Y, n, m);
        // cout << " x= " << int(xStr[pos - 1]);
        // cout << " y= " << int(yStr[pos - 1]);
        int resInt = int(xStr[pos - 1]) ^ int(yStr[pos - 1]);
        // cout << resInt << endl;
        decToBinary(resInt);
        cout << "\n";
    }
    return 0;
}