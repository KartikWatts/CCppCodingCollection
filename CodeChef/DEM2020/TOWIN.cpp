#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string first = "first", second = "second", draw = "draw", winner;
    while (t--)
    {
        int n;
        cin >> n;
        unsigned long long a[n];
        unsigned long long p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, greater<int>());
        if (n > 3)
        {
            p1 = a[0];
            p2 = a[1] + a[2];
            for (int i = 3; i < n; i++)
            {
                if (i % 2 != 0)
                {
                    p1 += a[i];
                }
                else
                {
                    p2 += a[i];
                }
            }
            if (p1 > p2)
            {
                winner = first;
            }
            else if (p1 == p2)
            {
                winner = draw;
            }
            else
            {
                winner = second;
            }
        }

        else if (n == 1)
        {
            if (a[0] > 0)
                winner = first;
            else
                winner = draw;
        }
        else if (n == 2)
        {
            if (a[0] > a[1])
                winner = first;
            else
                winner = draw;
        }
        else if (n == 3)
        {
            p2 = a[1] + a[2];
            if (a[0] > p2)
            {
                winner = first;
            }
            else if (a[0] == p2)
            {
                winner = draw;
            }
            else
            {
                winner = second;
            }
        }
        cout << winner << endl;
    }
}