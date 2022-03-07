#include <iostream>

using namespace std;

int main()
{
    int t, n, m, x, y, i, j;
    cin >> t;
    while (t--)
    {
        int cost = 0;
        cin >> n >> m >> x >> y;
        char a[n][m];
        int processed[n][m];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> a[i][j];
                processed[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (processed[i][j] == 0)
                {

                    if ((a[i][j] == '.' && j + 1 == m) || (a[i][j] == '.' && a[i][j + 1] == '*'))
                    {
                        cost += x;
                        processed[i][j] = 1;
                    }

                    else if (a[i][j] == '.' && a[i][j + 1] == '.')
                    {
                        if (2 * x <= y)
                            cost += 2 * x;
                        else
                            cost += y;

                        processed[i][j] = 1;
                        processed[i][j + 1] = 1;
                    }
                }
            }
        }
        cout << cost << endl;
    }
}