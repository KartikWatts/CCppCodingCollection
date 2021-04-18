#include <iostream>

using namespace std;

int main()
{
    int t, n, i, j, k;
    cin >> t;
    for (k = 0; k < t; k++)
    {
        cin >> n;
        int a[n][n];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int trace = 0;
        int rowrep = 0;
        int colrep = 0;
        for (i = 0; i < n; i++)
        {
            trace += a[i][i];
        }
        for (i = 0; i < n; i++)
        {
            bool repeat = false;
            for (j = 0; j < n - 1; j++)
            {
                for (int l = j + 1; l < n; l++)
                {
                    if (a[i][j] == a[i][l])
                    {
                        repeat = true;
                        break;
                    }
                }
                if (repeat == true)
                {
                    rowrep++;
                    break;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            bool repeat = false;
            for (j = 0; j < n - 1; j++)
            {
                for (int l = j + 1; l < n; l++)
                {
                    if (a[j][i] == a[l][i])
                    {
                        repeat = true;
                        break;
                    }
                }
                if (repeat == true)
                {
                    colrep++;
                    break;
                }
            }
        }
        cout << "Case #" << k + 1 << ": " << trace << " " << rowrep << " " << colrep << endl;
    }
}