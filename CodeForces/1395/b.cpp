#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << x << " " << y << endl;
    int currRow = x, currCol = y;
    for (int i = y + 1; i <= m; i++)
    {
        cout << x << " " << i << endl;
        currCol = i;
    }
    for (int i = y - 1; i >= 1; i--)
    {
        cout << x << " " << i << endl;
        currCol = i;
    }

    for (int i = 1; i < x; i++)
    {
        if (currCol == m)
        {
            for (int j = m; j >= 1; j--)
            {
                cout << i << " " << j << endl;
                currCol = j;
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                cout << i << " " << j << endl;
                currCol = j;
            }
        }
    }

    for (int i = x + 1; i <= n; i++)
    {
        if (currCol == m)
        {
            for (int j = m; j >= 1; j--)
            {
                cout << i << " " << j << endl;
                currCol = j;
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                cout << i << " " << j << endl;
                currCol = j;
            }
        }
    }
}