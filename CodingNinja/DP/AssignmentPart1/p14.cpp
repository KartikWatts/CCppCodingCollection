#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int a[r][c], res[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> a[i][j];
            }
        }
        res[r - 1][c - 1] = 1;
        for (int i = r - 1; i >= 0; i--)
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (i == (r - 1) && j == (c - 1))
                {
                    continue;
                }
                if (i + 1 < r && j + 1 < c)
                {
                    res[i][j] = min(res[i + 1][j], res[i][j + 1]) - a[i][j];
                }
                else if (i + 1 < r)
                {
                    res[i][j] = res[i + 1][j] - a[i][j];
                }
                else
                {
                    res[i][j] = res[i][j + 1] - a[i][j];
                }
                if (res[i][j] + a[i][j] <= 0)
                {
                    res[i][j] = res[i][j] + abs(res[i][j] + a[i][j]) + 1;
                }
            }
        }
        // cout << "\n\nSolution Array:\n";
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         cout << res[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\nResult:\t";
        if (res[0][0] <= 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << res[0][0] << endl;
        }
    }
}