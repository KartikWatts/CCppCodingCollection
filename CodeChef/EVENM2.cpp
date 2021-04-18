#include <iostream>

using namespace std;

int main()
{
    long t, i, j;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;

        long a[n][n];

        long num = 1;
        if (n >= 1)
        {
            a[0][0] = 1;
            num++;
        }
        for (long size = 2; size <= n; size++)
        {
            for (i = 0; i <= size - 1; i++)
            {
                a[i][size - 1] = num++;
            }
            for (i = size - 2; i >= 0; i--)
            {
                a[size - 1][i] = num++;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}